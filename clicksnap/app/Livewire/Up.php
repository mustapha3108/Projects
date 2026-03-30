<?php

namespace App\Livewire;

use App\Models\photo;
use Illuminate\Support\Facades\Auth;
use Livewire\{Component, WithFileUploads};

class Up extends Component
{
    use WithFileUploads;

    public $title, $description, $category, $keywords, $pic;

    public function newphoto(){
        
        //TODO: set size limits
        $this->validate([
            'title'=>"required|string|max:250",
            'description'=>"required|string|max:250",
            'category'=>"required|string|max:250",
            'keywords'=>"string|max:250",
            'pic'=>"image|max:4096"
        ]);

        $path = $this->pic->store(path:'uploads', options:'public');
        photo::create([
            'user'=>Auth::user()->id,
            'path'=>$path,
            'title'=>$this->title,
            'description'=>$this->description,
            'category'=>$this->category,
            'keywords'=>$this->keywords
        ]);
        
        $this->dispatch('photo_uploaded');
        $this->reset();
    }

    public function render()
    {
        return view('livewire.up');
    }
}
