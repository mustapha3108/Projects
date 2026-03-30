<?php

namespace App\Livewire;

use Illuminate\Support\Facades\{Auth, Storage};
use App\Models\User;
use Livewire\{Component, WithFileUploads};

class Useraccount extends Component
{
    use WithFileUploads;

    public $name, $email, $password, $password_confirmation, $pic;

    public function updateusername(){

        $this->validate([
            'name'=>'required',
        ]);
        $user = Auth::user();
        $user->update([
            'name'=>$this->name
        ]);
        $this->reset('name');
    }

    public function updateuseremail(){
        
        $this->validate([
            'email'=>'email|required|unique:users,email'
        ]);
        $user = Auth::user();
        $user->update([
            'email'=>$this->email
        ]);
        $this->reset('email');

    }

    public function updateuserpassword(){

        $this->validate([
            'password'=>'confirmed'
        ]);
        $user = Auth::user();
        $user->update([
            'password'=>$this->password
        ]);
        $this->reset('password');

        $this->dispatch('password_changed');

    }

    public function updateuserpic(){
        $this->validate([
            'pic'=>'image'
        ]);
        $image = $this->pic->store(path:'profilepics', options:'public');
        //dd($image);
        $user = AUth::user();
        $user->update([
            'pic'=>$image
        ]);
        $this->reset('pic');
    }

    /*
    public function resetpic(){
        $user = Auth::user();
        Storage::disk('public')->delete($user->pic);
        $user->update([
            'pic'=>"website/nopic.avif"
        ]);
    }
    */

    public function render()
    {
        return view('livewire.useraccount');
    }
}
