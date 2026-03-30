<?php

namespace App\Livewire;

use App\Models\photo;
use Livewire\Component;

class Herosearch extends Component
{

    public $suggestions;
    public $query;

    public function updatedQuery(){
        if($this->query==null){
            $this->suggestions = collect();
        }else{
            $suggestions = photo::search($this->query)->take(5)->get();
            $this->suggestions = $suggestions->pluck('title')->toArray();
        }
    }

    public function search(){
        $this->redirectRoute('browse', ['query'=>$this->query], navigate:true);
    }

    public function searchsug($sug){
        $this->redirectRoute('browse', ['query'=>$sug], navigate:true);
    }

    public function render()
    {
        return view('livewire.herosearch');
    }
}
