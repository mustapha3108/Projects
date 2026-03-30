<div class="flex flex-col w-10/10">
    <form wire:submit='search' class="flex gap-0 text-3xl w-10/10">
        <input wire:model.live='query'
         type="text" placeholder="what are you i the mood for" class="input focus:outline-0 w-7/10 " /> 
        <button class="btn w-3/10" type="submit"> search </button>
    </form>
    <div class="relative w-10/10">
        <div class="absolute w-10/10 bg-base-100 border-1 border-base-200 ">
            @if ($suggestions)
                <ul>
                    @foreach ($suggestions as $sug)
                        <li class="w-10/10 bg-base-100 hover:bg-base-200 p-3 cursor-pointer"
                         wire:click='searchsug(@json($sug))'
                        >{{$sug}}</li>
                    @endforeach
                </ul>
            @endif
        </div>
    </div>
</div>
