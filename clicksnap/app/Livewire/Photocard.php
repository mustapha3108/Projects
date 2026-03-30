<?php

namespace App\Livewire;

use Illuminate\Support\Facades\Auth;
use App\Models\{likes, photo, saves};
use Livewire\Component;
use Psy\CodeCleaner\AssignThisVariablePass;

class Photocard extends Component
{
    public array $photo;
    public bool $liked, $saved;
    public string $yo = 'the dark knight';

    public function mount(){
        $this->liked = in_array(Auth::id(), array_column($this->photo['likes'], 'user_id'));
        $this->saved = in_array(Auth::id(), array_column($this->photo['savved'], 'user_id'));
    }

    public function like(bool $likestatus){
        $this->liked = !$this->liked;
        if($this->liked){
            if(Auth::check()){
                likes::create([
                    'user_id'=>Auth::user()->id,
                    'photo_id'=>$this->photo['id'],
                ]);
                $photo = photo::findOrFail($this->photo['id']);
                $newlike = $photo->likes_count;
                $newlike++;
                $photo->update([
                    'likes_count'=> $newlike,
                ]);
                $this->photo['likes_count'] = $newlike;
            }
        }
        else{
            if(Auth::check()){
            likes::where('user_id', Auth::user()->id)->where('photo_id', $this->photo['id'])->delete();
            $photo = photo::findOrFail($this->photo['id']);
            $likes = $photo->likes_count;
            $likes--;
            if($likes>=0){
                $photo->update([
                    'likes_count'=> $likes,
                ]);
            }
            $this->photo['likes_count'] = $likes;
            }
        }
    }

    public function savve(bool $savedstatus){
        $this->saved = !$this->saved;
        if($this->saved){
            if(Auth::check()){
                saves::create([
                    'user_id'=>Auth::user()->id,
                    'photo_id'=>$this->photo['id'],
                ]);
                $photo = photo::findOrFail($this->photo['id']);
                $saves = $photo->saves_count;
                $saves++;
                $photo->update([
                    'saves_count'=> $saves,
                ]);
                $this->photo['saves_count'] = $saves;
            }
        }
        else
        {
            if(Auth::check()){
                saves::where('user_id', Auth::user()->id)->where('photo_id', $this->photo['id'])->delete();
                $photo = photo::findOrFail($this->photo['id']);
                $saves = $photo->saves_count;
                $saves--;
                if($saves>=0){
                    $photo->update([
                        'saves_count'=> $saves,
                    ]);
                }
                $this->photo['saves_count'] = $saves;
            }
        }
    }

    public function render()
    {
        return view('livewire.photocard');
    }
}
