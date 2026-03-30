<x-scaf>
    <div class="p-3">
        <x-navbar />

        <div class="flex flex-col items-center justify-center">
            <img src="{{ Storage::url($author->pic) }}" alt="" class="size-50 rounded-full">
            <h1 class="text-2xl">{{ $author->name }}</h1>
            <p>{{ $author->email }}</p>
        </div>

        <div class="masonry p-10 w-10/10">
        @if ($photos)
            @foreach ($photos as $res)

                <livewire:photocard
                :photo="$res->toArray()"
                wire:key="photo-{{ $res->id }}" 
                />

            @endforeach
        @endif 
        </div>

        @if ($photos) {{ $photos->links() }}  @endif
    </div>
</x-scaf>