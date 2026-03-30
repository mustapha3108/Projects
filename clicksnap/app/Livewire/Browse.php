<?php

namespace App\Livewire;

use App\Models\photo;
use Illuminate\Support\Facades\Storage;
use Livewire\{Component, WithPagination};
use Livewire\Attributes\On;

class Browse extends Component
{

    use WithPagination;

    public $query='', $sugquery, $suggestions;


    public function updatingQuery()
    {
        $this->resetPage();
    }


    public function updatedSugquery(){
        if($this->sugquery == ""){
            $this->suggestions = collect();
        }else{
            $this->suggestions = photo::search($this->sugquery)->take(4)->get();
            $this->suggestions = $this->suggestions->pluck('title')->toArray();
        }
    }
    
    public function search($sug){
        $this->query = $sug;
        $this->suggestions = collect();
        $this->resetPage();
    }

    public function searchbar(){
        $this->query = $this->sugquery;
        $this->suggestions = collect();
        $this->resetPage();
    }


    public function mount(){
        if(request('query')){
            $this->query = request('query');
        }
    } 

    public function render()
    {

        if (trim($this->query) === '') {
        $results = photo::with('userget', 'likes', 'savved')
            ->latest()
            ->simplePaginate(20);
        } else {
            $results = photo::search($this->query)->simplePaginate(20);
            $results->load('userget', 'likes', 'savved');
        }


        //$results = photo::search($this->query)->simplePaginate(1);
        //$results->load('userget', 'likes', 'savved');


        return view('livewire.browse', [
            'results' => $results,
        ]);
    }
}
