<div class="flex flex-col justify-center items-center">
    <!-- searchabr, with categories and auto-complete-->
    <form class="flex flex-col items-center w-10/10"  wire:submit='searchbar'>
        <div class="flex justify-center w-10/10">
            <input wire:model.live='sugquery' type="text" class="input myinput mb-0 w-5/10">
            <input type="submit" class="btn btn-dash w-2/10 text-xs px-1 md:text-lg" value="search" />
        </div>
    </form>
    <div class="relative flex justify-center w-10/10">
        <ul class="absolute flex flex-col justify-start items-start w-7/10 bg-base-100 border-1 border-base-200 z-100">
            @if ($suggestions)
                @foreach ($suggestions as $sug)
                    <li class="w-10/10 bg-base-100 hover:bg-base-200 p-3 cursor-pointer"
                     wire:click='search(@json($sug))'
                    >{{$sug}}</li>
                @endforeach
            @endif
        </ul>
    </div>


    <!-- displaying the results, grid, foreach -->
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

    @if ($results)
        <div wire:navigate>
            {{ $results->links() }}
        </div>
    @else
        <h1 class="text-2xl">sorry no pictures found</h1>
    @endif
   
</div>