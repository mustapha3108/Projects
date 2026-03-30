<x-scaf>
    <div class="p-3">
        <x-navbar />

        <div class="m-6 flex flex-col sm:flex-row justify-around gap-3">
            <div class="max-w-[%90] max-h-[%70vh] sm:max-w-3/5 flex flex-col  ">
                <img src="{{ Storage::url($photo->path) }}" alt="" class="w-full">
                <livewire:likeandshare
                :photo="$photo->toArray()" />
            </div>
            <div class="">
                <h1 class="text-2xl">{{ $photo->title }}</h1>
                <p>{{ $photo->description }}</p>
                <div class="flex gap-2 items-center justify-start mt-4">
                    <img src="{{ Storage::url($photo->userget->pic) }}" alt="" class="size-12 rounded-full">
                    <span class="text-lg">{{$photo->userget->name}}</span>
                </div>
            </div>
        </div>

        <div class="masonry p-10 w-10/10">
        @if ($suggestions)
            @foreach ($suggestions as $res)
                @if ($photo->id != $res->id)
                <livewire:photocard
                :photo="$res->toArray()"
                wire:key="photo-{{ $res->id }}" 
                />
                @endif
            @endforeach
        @endif 
        </div>
        
    </div>
</x-scaf>