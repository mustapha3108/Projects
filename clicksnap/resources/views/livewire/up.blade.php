<div class="flex flex-col justify-center items-center w-10/10">
    <form wire:submit='newphoto' class="fieldset w-9/10 flex flex-col justify-center items-center gap-5">

        <div class="flex flex-col justify-center gap-5">

            <div class="flex flex-col justify-start gap-2">
                <label  class="label  "> photo title</label >
                <input wire:model='title' type="text" placeholder="a dream's sakura tree" class="input myinput sm:w-120">
                @error('title') <p>{{ $message }} </p> @enderror
            </div>

            <div class="flex flex-col justify-start  gap-2">
                <label  class="label sm:text-xl">photo category</label >
                <select wire:model='category' class="select myinput" placeholder="choose a category">
                  <option>No Category</option>
                  <option>Nature and Landscape</option>
                  <option>Floral</option>
                  <option>Architecture and Cities</option>
                  <option>Cars and Vehicules</option>
                  <option>Animals</option>
                  <option>Abstract</option>
                  <option>Dark</option>
                  <option>Fantasy</option>
                  <option>Space</option>
                  <option>Other</option>
                </select>
                @error('category') <p>{{ $message }} </p> @enderror
            </div>

            <div class="flex flex-col justify-start gap-2">
                <label  class="label sm:text-xl">keywords</label >
                <input wire:model='keywords' type="text" placeholder="tree, dream, fantasy, pink..." class="input myinput sm:w-120">
                @error('keywords') <p>{{ $message }} </p> @enderror
            </div>

            <div class="flex flex-col justify-start gap-2">
                <label  class="label sm:text-xl">description</label >
                <textarea wire:model='description' type="text" placeholder="250 charachter max" class=" textarea myinput sm:w-120"></textarea>
                @error('description') <p>{{ $message }} </p> @enderror
            </div>

            <div class="flex flex-col justify-start gap-2">
                <label  class='label '>picture, max: 4MB</label >
                <input wire:model='pic' type="file" class="file-input file-input-ghost sm:w-120"/>
                @error('pic') <p>{{ $message }} </p> @enderror
            </div>   

            <button type="submit" class="btn sm:w-120">Upload</button>

        </div>

    </form>
</div>
