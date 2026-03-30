<?php

namespace App\Livewire;

use Livewire\{Component, WithPagination};
use App\Models\photo;
use Illuminate\Support\Facades\Auth;

class Mapics extends Component
{

    use WithPagination;

    public $selected = 1;
    //public $selected;

    public function updatingSelected(){
        //$this->selected = (int) $this->selected;
    }


    public function render()
    {
        
        if($this->selected == 1){
            $results = photo::where('user', Auth::user()->id)->with('userget', 'likes', 'savved')->simplePaginate(20);
        }else if($this->selected == 2){

            $results = photo::whereHas('likes', function ($query) {
                    $query->where('user_id', Auth::user()->id);}
                    )->with('userget', 'likes', 'savved')->simplePaginate(20);

        }else if($this->selected == 3){

            $results = photo::whereHas('savved', function ($query) {
                    $query->where('user_id', Auth::user()->id);}
                    )->with('userget', 'likes', 'savved')->simplePaginate(20);
        }
        
        return view('livewire.mapics', ['results'=>$results]);
    }
}
