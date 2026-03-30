<div class="flex flex-col justify-center items-center">
    <!-- searchabr, with categories and auto-complete-->
    <select class="select myinput" wire:model.live='selected'>
      <option disabled selected>filter here</option>
      <option value="1">my uploaded pictures</option>
      <option value="2">the pictures i liked</option>
      <option value="3">saved pictures</option>
    </select>


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
