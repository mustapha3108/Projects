<div class="flex justify-around items-center flex-col md:flex-row gap-6 md:gap-2">

    <!-- action task -->
    <div class="flex justify-center items-center flex-col md:w-1/3 gap-6 w-1/1">
            <h1 class="text-2xl md:text-3xl text-center">welcome to ClickSnap</h1>
            <h3 class="text-center text-sm md:text-md">share and look for pictures to your hearts desire</h3>
            <!-- replace with livewire component 
            <div class="flex gap-0 text-3xl">
              <input type="text" placeholder="what are you i the mood for" class="input focus:outline-0" /> 
              <span class="btn"> search </span>
            </div>
            -->
            <livewire:herosearch/>
    </div>

    <!-- hero photo -->
    <div class="md:w-1/4 flex justify-center">
      <!--
        <div class="grid  grid-cols-2 grid-rows-2 max-w-xl mx-auto gap-4">
            <img src="{{ asset('storage/webiste/hero1.jpg') }}" alt="Hero Image"  >
            <img src="{{ asset('storage/webiste/hero3.jpg') }}" alt="Hero Image 3">
            <img src="{{ asset('storage/webiste/hero2.jpg') }}" alt="Hero Image 2" class="col-span-2 aspect-[2/1]">
            
        </div>
      -->
      <img src="{{ Storage::url('website/camera.png') }}" alt="hero"
      class="w-9/12 md:w-10/10">
    </div>
    
</div>