<div>
    <div>
      <form class="fieldset flex flex-col gap-2" wire:submit="signup">
        <legend class="fieldset-legend text-xl">Sign up</legend>

        <label for="">name</label>
        <input type="text" class="input myinput" wire:model="name" placeholder="type your name">
        @error('name') <p class="text-error">{{$message}}</p> @enderror

        <label for="">email</label>
        <input type="text" class="input myinput" wire:model="email" placeholder="type your email">
        @error('email') <p class="text-error">{{$message}}</p> @enderror
        <label for="">password</label>

        <input type="password" class="input myinput" wire:model="password" placeholder="type your password">
        @error('password') <p class="text-error">{{$message}}</p> @enderror
        <input type="password" class="input myinput" wire:model="password_confirmation" placeholder="type your password">

        <button type="submit" class="btn btn-success btn-dash mt-3">Signup</button>
      </form>
    </div>

    <div class="divider">OR</div>

    <div>
      <form class="fieldset flex flex-col fap-3" wire:submit="login">
        <legend class="fieldset-legend text-xl">Login</legend>

        <label for="">email</label>
        <input type="text" class="input myinput" wire:model="lemail" placeholder="type your email">
        @error('lemail')
          <p class="text-error">{{ $message }} </p>
        @enderror
        <label for="">password</label>
        <input type="password" class="input myinput" wire:model="lpassword" placeholder="type your password">
        @error('lpassword')
          <p class="text-error">{{ $message }} </p>
        @enderror
        <button class="btn btn-success btn-dash mt-3"="login">Login</button>
      </form>
    </div>
</div>
