<?php

namespace App\Livewire;

use App\Models\User;
use Illuminate\Support\Facades\Auth;
use Illuminate\Validation\Rules\Password;
use Livewire\Component;

use function Laravel\Prompts\password;

class Signup extends Component
{
    public $name, $email, $password, $password_confirmation;
    public $lemail, $lpassword;

    public function signup(){
        //dd('i got to the functions');
        $user = $this->validate([
            'name'=>'required',
            'email'=>'email|required|unique:users,email',
            'password'=>['required', 'confirmed', Password::min(3)->letters()->numbers()]
        ]);

        $user['pic'] = "storage/website/nopic.avif";

        $user = User::create($user);
        Auth::login($user, true);
        return $this->redirectRoute('account', navigate: true);
    }

    public function login(){
        $user = $this->validate([
            'lemail'=>'required|exists:users,email',
            'lpassword'=>'required'
        ]);

        Auth::attempt([
            'email'=>$user['lemail'],
            'password'=>$user['lpassword']
        ], true);

        return $this->redirectRoute('welcome', navigate: true);
    }

    public function render()
    {
        return view('livewire.signup');
    }
}
