<div class="flex flex-col justify-center items-center gap-6">

    <div class="flex items-center justify-around sm:justify-center sm:gap-6 md:gap-20">
        <img src="{{ Storage::url(Auth::user()->pic) }}" alt="user photo" class="w-3/10 sm:w-2/10 md:1/10 aspect-square rounded-full">
        <div>
          <p class="text-xl sm:text-3xl md:text-5xl lg:text-6xl xl:text-7xl">{{Auth::user()->name}}</p>
          <p class="text-xs sm:text-ms md:text-xl lg:text-2xl xl:text-3xl">{{Auth::user()->email}}</p>
        </div>
    </div>


    <div  class="flex flex-col justify-center items-center gap-6 mt-6 md:mt-12 w-9/10 md:w-7/10">

        <form wire:submit.prevent='updateusername' class="flex flex-row-reverse justify-center gap-2 w-9/10">
            <button type="submit" class="btn btn-dash" wire:loading.attr="disabled" wire:target='updateusername'>change name</button>
            <div class="w-10/10">
                <input class="input input-accent w-10/10" type="text" wire:model='name' placeholder="{{ Auth::user()->name }}">
                @error('name') <p class="text-error text-sm"> {{ $message }} </p> @enderror
            </div>
        </form> 

        <form wire:submit.prevent='updateuseremail' class="flex flex-row-reverse justify-center gap-2 w-9/10">
            <button type="submit" class="btn btn-dash" wire:loading.attr="disabled" wire:target='updateuseremail'>change email</button>
            <div class="w-10/10 ">
                <input class="input input-accent w-10/10" type="text" wire:model='email' placeholder="{{ Auth::user()->email }}">
                @error('email') <p class="text-error text-sm"> {{ $message }} </p> @enderror
            </div>
        </form>

        <form wire:submit.prevent='updateuserpassword' class="flex flex-col-reverse justify-center gap-2 w-9/10">
            <button type="submit" class="btn btn-dash w-10/10" wire:loading.attr="disabled" wire:target='updateuserpassword'>change pasword</button>
            <div class="flex gap-2 w-10/10">
                <input class="input input-accent w-10/10" type="password" wire:model='password' placeholder="password">
                <input class="input input-accent w-10/10" type="password" wire:model='password_confirmation' placeholder="confirm password">
            </div>
            @error('password') <p class="text-error text-sm"> {{ $message }} </p> @enderror
            <div x-data="{ x: '' }" 
                 x-on:password_changed.window="
                    x = 'password changed';
                    setTimeout(() => x = '', 2000);">
                    <p class="text-success text-sm" x-text="x"></p>
            </div>
        </form>

        <form wire:submit.prevent='updateuserpic' class="flex flex-col-reverse justify-center gap-2 w-9/10">
            <button type="submit" class="btn btn-dash" wire:loading.attr="disabled" wire:target='updateuserpic'>change profile picture</button>
            <div>
                <input type="file" class="file-input w-10/10" wire:model='pic'/>
                @error('pic') <p class="text-error text-sm"> {{ $message }} </p> @enderror
            </div>
        </form>

    </div>
</div>
