<div wire:ignore x-data="{ x: $wire.liked, y: $wire.saved, likes_count: $wire.photo['likes_count'], saves_count: $wire.photo['saves_count'] }">
    <div class="flex flex-row-reverse justify-between items-center w-full mt-3">
        <button class="btn btn-circle btn-success border-0 hell-download" 
         @click.stop=''
         data-path="{{ $photo['path'] }}" 
         data-title="{{ $photo['title'] }}">
            <x-untitledui-download class="w-25 h-25 rounded-full p-3 transition-colors duration-200" />
        </button>
        @auth
        <div class="flex justify-center items-center gap-2">
            <button type="button" class="btn btn-circle border-0 transition-colors duration-200" 
             :class="{'bg-red-500 hover:bg-gray-900': x==true, 'bg-black hover:bg-red-900': x==false}"
             x-on:click="x=!x; x? likes_count++ : likes_count-- ;$wire.like(x); setTimeout(() => {x = $wire.liked; likes_count=$wire.photo['likes_count'];}, 5000)"
            >
                <x-iconpark-like-o class="w-30 h-30 rounded-full p-3 "/>
            </button>
            <p x-text='likes_count'></p>
        </div>
            
        <div class="flex justify-center items-center gap-2">
            <button type="button" class="btn btn-circle border-0 transition-colors duration-200" 
             :class="{'bg-gray-500 hover:bg-black': y==true, 'bg-black hover:bg-gray-500': y==false}"
             x-on:click="y=!y; y? saves_count++ : saves_count-- ;$wire.savve(y); setTimeout(() => {y = $wire.saved; saves_count=$wire.photo['saves_count'];}, 5000)"
            >
                <x-fluentui-save-copy-20-o class="w-30 h-30 rounded-full p-3 "/>
            </button>
            <p x-text='saves_count'></p>
        </div>
        @endauth
        <button class="btn btn-circle border-0 btn-info"
         x-data="{url:window.location.origin + '/photos/{{ $photo['id'] }}', clicked:false}"
         :class="{'bg-success' : clicked}"
         @click="navigator.clipboard.writeText(url); clicked = true; setTimeout(() => clicked = false, 3000)">
            <x-fas-share class="w-25 h-25 rounded-full p-3" />
        </button>
    </div>
</div>
