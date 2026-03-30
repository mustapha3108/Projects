<x-scaf>

  <div class="sm:hidden p-6">



    {{ $phone }}




    <div class="fixed bottom-4 right-4 ">
      <button class="btn btn-success btn-dash" onclick="my_modal_5.showModal()">open modal</button>
      <dialog id="my_modal_5" class="modal modal-bottom sm:modal-middle">
        <div class="modal-box">

          <div class="flex flex-col gap-4">
            <div href="{{ route('welcome') }}" wire:navigate class="cursor-pointer p-2 rounded-xl w-10/10" data-tip="Homepage">
              <x-heroicon-o-home-modern class="w-5" />
              <span class="">Homepage</span>
            </div>

            <div href="{{ route('account') }}" wire:navigate wire:current.exact="bg-base-200 rounded-full"
             class="cursor-pointer p-2 rounded-xl w-10/10" data-tip="account">
              <x-codicon-account class="w-5" />
              <span class="">account</span>
            </div>

            <div href="{{ route('upload') }}" wire:navigate wire:current.exact="bg-base-200 w-10 rounded-full"
             class="cursor-pointer p-2 rounded-xl w-10/10" data-tip="upload pics">
              <x-fas-upload class="w-5"/>
              <span class="">upload pics</span>
            </div>


            <div href="{{ route('mypics') }}" wire:navigate wire:current.exact="bg-base-200 rounded-full"
             class="cursor-pointer p-2 rounded-xl w-10/10" data-tip="view my pics">
              <x-tabler-photo-check class="w-5"/>
              <span class="is-drawer-close:hidden">view my pictures</span>
            </div>



          </div>

          <div class="modal-action">
            <form method="dialog">
              <button class="btn">Close</button>
            </form>
          </div>
        </div>
      </dialog>
    </div>
  </div>

  <div class="hidden sm:block">
      <div class="drawer drawer-open ">
        <input id="my-drawer-4" type="checkbox" class="drawer-toggle" />
        
        <div class="drawer-content p-6">

          {{ $pc }}

        </div>

        <div class="drawer-side is-drawer-close:overflow-visible border-r-1 border-white">
          <label for="my-drawer-4" aria-label="close sidebar" class="drawer-overlay"></label>
          <div class="is-drawer-close:w-14 is-drawer-open:w-64 bg-base-100 flex flex-col items-start min-h-full">
            <!-- Sidebar content here -->
            <ul class="menu w-full grow flex flex-col justify-start gap-6">

              <!-- list items -->

              <li>
                <a href="{{ route('welcome') }}" wire:navigate class="is-drawer-close:tooltip is-drawer-close:tooltip-right rounded-full" data-tip="Homepage">
                  <div>
                  <x-heroicon-o-home-modern class="w-5" />
                  </div>
                  <span class="is-drawer-close:hidden">Homepage</span>
                </a>
              </li>

              <li>
                <a href="{{ route('account') }}" wire:navigate wire:current.exact="bg-base-200 rounded-full"
                 class="is-drawer-close:tooltip is-drawer-close:tooltip-right rounded-full" data-tip="account">
                  <x-codicon-account class="w-5" />
                  <span class="is-drawer-close:hidden">account</span>
                </a>
              </li>

              <li>
                <a href="{{ route('upload') }}" wire:navigate wire:current.exact="bg-base-200 rounded-full"
                 class="is-drawer-close:tooltip is-drawer-close:tooltip-right rounded-full" data-tip="upload pics">
                  <x-fas-upload class="w-5"/>
                  <span class="is-drawer-close:hidden">upload pics</span>
                </a>
              </li>

              <li>
                <a href="{{ route('mypics') }}" wire:navigate wire:current.exact="bg-base-200 rounded-full"
                 class="is-drawer-close:tooltip is-drawer-close:tooltip-right rounded-full" data-tip="view my pics">
                  <x-tabler-photo-check class="w-5"/>
                  <span class="is-drawer-close:hidden">view my pictures</span>
                </a>
              </li>


            </ul>

            <!-- button to open/close drawer -->
            <div class="m-2 is-drawer-close:tooltip is-drawer-close:tooltip-right" data-tip="Open">
              <label for="my-drawer-4" class="btn btn-ghost btn-circle drawer-button is-drawer-open:rotate-y-180">
                <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" stroke-linejoin="round" stroke-linecap="round" stroke-width="2" fill="none" stroke="currentColor" class="inline-block size-4 my-1.5"><path d="M4 4m0 2a2 2 0 0 1 2 -2h12a2 2 0 0 1 2 2v12a2 2 0 0 1 -2 2h-12a2 2 0 0 1 -2 -2z"></path><path d="M9 4v16"></path><path d="M14 10l2 2l-2 2"></path></svg>
              </label>
            </div>

          </div>
        </div>
      </div>
  </div>
</x-scaf>