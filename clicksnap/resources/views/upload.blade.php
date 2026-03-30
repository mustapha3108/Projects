<x-dashboard.sidebar>

    <x-slot:phone>
        <h1 class="text-xl text-center p-4 mb-6">Honnor us with your creativity</h1>
        <livewire:up/>
    </x-slot:phone>

    <x-slot:pc>
        <h1 class="text-3xl text-center p-4 mb-6">Honnor us with your creativity</h1>
        <livewire:up/>
    </x-slot:pc>

</x-dashboard.sidebar>

<div x-data="" x-on:photo_uploaded.window="comf.showModal()">
    <dialog id="comf" class="modal modal-bottom sm:modal-middle">
      <div class="modal-box">
        <div class="flex flex-col gap-4">
            
        <h1 class="text-success text-center text-xl">photo successfully uploaded!!</h1>
    
        <div class="modal-action">
          <form method="dialog">
            <button class="btn">Close</button>
          </form>
        </div>
      </div>
    </dialog>
</div>