<div>
    <div class="masonry p-10 w-10/10">
        @if ($results)
            @foreach ($results as $res)

                <livewire:photocard
                :photo="$res->toArray()"
                wire:key="photo-{{ $res->id }}" 
                />

            @endforeach
        @endif 
    </div>
</div>