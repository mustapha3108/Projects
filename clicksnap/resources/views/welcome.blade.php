<x-scaf>
    <div class="p-6">
        <x-navbar/>
        <x-welcome.hero/>
        <x-welcome.photos/>

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

        <div class="flex justify-center">
            <a href="{{ route('browse') }}" class="text-xl link link-hover">More Photos</a>
        </div>
        
    </div>
</x-scaf>