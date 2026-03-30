<div class="masonry-item"
 wire:ignore x-data="{ x: $wire.liked, y: $wire.saved, likes_count: $wire.photo['likes_count'], saves_count: $wire.photo['saves_count'] }">
    
    <div
     x-data="{ hover: false }" @mouseenter="hover = true" @mouseleave="hover = false"
     onclick="document.getElementById('pic_modal{{ $photo['id'] }}').showModal()"
     class="relative masonry-item overflow-hidden rounded-2xl shadow-md hover:shadow-xl transition group bg-base-200 cursor-pointer"
     >
        <div>
            <img src="{{ Storage::url($photo['path']) }}" alt="" class="masonryimg">
        </div>
        <div x-show="hover" x-cloak x-transition.duration.400ms
          class="flex flex-col absolute inset-0 p-3 text-white items-center justify-between"
          >
            <div class="bg-black/80 p-2 rounded-2xl text-sm">
                <p>{{ $photo['title'] }} by 
                    <a class="text-info link-hover">{{$photo['userget']['name']}}</a>
                </p>
            </div>
            <div class="flex flex-row-reverse justify-between items-center w-10/10">

                <button class="btn btn-circle btn-success border-0 hell-download"
                 @click.stop=''
                 data-path="{{ $photo['path'] }}" 
                 data-title="{{ $photo['title'] }}">
                    <x-untitledui-download class="w-10 h-10 rounded-full p-2  transition-colors duration-200" />
                </button>

                @auth  
                <button type="button" class="btn btn-circle border-0 transition-colors duration-200 z-100" 
                 :class="{'bg-red-500 hover:bg-red-900': x==true, 'bg-black hover:bg-gray-400': x==false}"
                 x-on:click.stop="x=!x; x? likes_count++ : likes_count-- ; $wire.like(x); setTimeout(() => {x = $wire.liked; likes_count=$wire.photo['likes_count'];}, 5000)"
                >
                    <x-iconpark-like-o class="w-15 h-15 rounded-full p-3"/>
                </button>
                <button type="button" class="btn btn-circle border-0 transition-colors duration-200" 
                 :class="{'bg-gray-500 hover:bg-black': y==true, 'bg-black hover:bg-gray-500': y==false}"
                 x-on:click.stop="y=!y; y? saves_count++ : saves_count-- ; $wire.savve(y); setTimeout(() => {y = $wire.saved; saves_count=$wire.photo['saves_count'];}, 5000)"
                >
                    <x-fluentui-save-copy-20-o class="w-15 h-15 rounded-full p-3 "/>
                </button>
                @endauth

            </div>
        </div> 
    </div>


    <dialog wire:ignore.self id="pic_modal{{ $photo['id'] }}" class="modal modal-bottom sm:modal-middle w-full">
        <div class="modal-box w-full sm:w-[80%] lg:w-[70%] max-w-[1200px] max-h-[90vh] overflow-auto">
            <div class="flex flex-col sm:flex-row gap-6 w-full"> 
                <div class="sm:w-[60%] flex flex-col items-center gap-2">
                    <div>
                        <img src="{{ Storage::url($photo['path']) }}" alt="" class="w-full h-auto object-contain">
                    </div>
                    <div class="flex flex-row-reverse justify-between items-center w-full m-3 p-1">
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
                <div class="sm:w-[40%] flex flex-col items-between justify-between gap-3">
                    <div>
                        <div>
                            <h3 class="text-2xl font-bold mb-3">{{$photo['title']}}</h3>
                            <p>{{ $photo['description'] }} </p>
                        </div>

                        <a href="{{ route('authorpage', ['authorid'=>$photo['userget']['id']]) }}" wire:navigate>
                         <div class="flex flex-row justify-start items-center gap-2 mt-5">
                            <img src="{{ Storage::url( $photo['userget']['pic']) }}" alt="" class="w-12 h-12 rounded-full" />
                            <p class="text-lg">{{$photo['userget']['name']}}</p>
                         </div>
                        </a>
                    </div>
                    
                    <div class="flex justify-end">
                        <button class="btn" onclick="document.getElementById('pic_modal{{ $photo['id'] }}').close()">Close</button>
                    </div>
                </div>
            </div>
        </div>
    </dialog>

</div>
