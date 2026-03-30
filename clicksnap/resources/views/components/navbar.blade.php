
<!------------------------------ desktop navbar ------------------------------>
<div class="hidden md:flex justify-between items-center mb-20">
  <div>
    <a style="font-family: 'Poppins', sans-serif;" class="text-md sm:text-3xl"
    href="{{ route('welcome') }}" wire:navigate>ClickSnap</a>
  </div>
  <div class="flex justify-end items-center gap-3">
      <!--categories dropdow-->
      <div class="dropdown dropdown-center">
        <div tabindex="0" role="button" class="btn m-1 bg-base-100 border-0 btn-xs md:btn-md">Categories↓</div>
        <ul tabindex="-1" class="dropdown-content menu bg-base-100 rounded-box z-200 w-52 p-2 shadow-sm">
          <a role="a" class="p-2" href="{{ route('browse', ['query'=>'nature and landscape']) }}">Nature and Landscape</a>
          <a role="a" class="p-2" href="{{ route('browse', ['query'=>'floral']) }}">Floral</a>
          <a role="a" class="p-2" href="{{ route('browse', ['query'=>'architecture and cities']) }}">Architecture and Cities</a>
          <a role="a" class="p-2" href="{{ route('browse', ['query'=>'cars and vehicules']) }}">Cars and Vehicules</a>
          <a role="a" class="p-2" href="{{ route('browse', ['query'=>'animals']) }}">Animals</a>
          <a role="a" class="p-2" href="{{ route('browse', ['query'=>'abstarct']) }}">Abstract</a>
          <a role="a" class="p-2" href="{{ route('browse', ['query'=>'dark']) }}">Dark</a>
          <a role="a" class="p-2" href="{{ route('browse', ['query'=>'fantasy']) }}">Fantasy</a>
          <a role="a" class="p-2" href="{{ route('browse', ['query'=>'space']) }}">Space</a>
          <a role="a" class="p-2 pointer-event" href="{{ route('browse', ['query'=>'other']) }}">Other</a>
        </ul>
      </div>
      <!-- -->
      <a href="#" class="">Help center</a>

     @guest
     <!-- Open the modal using ID.showModal() method -->
      <button class="btn btn-dash" onclick="my_modal_1.showModal()">signup or log in</button>
      <dialog id="my_modal_1" class="modal">
        <div class="modal-box border-1 border-gray-400">
          <!-- livewire class here -->
          <livewire:signup/>
          <div class="modal-action">
            <form method="dialog">
              <!-- if there is a button in form, it will close the modal -->
              <button class="btn">Cancel</button>
            </form>
          </div>
        </div>
      </dialog>
      @endguest 

     @auth

     <a href="{{ route('upload') }}" wire:navigate class="btn btn-dash border-success">upload <x-fas-upload class="w-4"/></a>

      <div class="dropdown dropdown-end">
        <div tabindex="0" role="button" class=" m-1 brn-xs/6 text-sm/3 cursor-pointer">
          <img src="{{ Storage::url(Auth::user()->pic) }}" alt="user image as menu" class="w-10 h-10 rounded-full object-cover border-2 border-white shadow-md">
        </div>
        <ul tabindex="-1" class="dropdown-content menu bg-base-100 rounded-box z-1 w-52 p-2 shadow-sm">

          <li><a href="{{ route('upload') }}" wire:navigate class="flex justify-between">
            <p>upload pictures</p>
            <x-fas-upload class="w-5"/>
          </a></li>

          <li><a href="{{ route('account') }}" class="flex justify-between">
            <p>account</p> 
            <x-codicon-account class="w-5" />
          </a></li>

          <livewire:logout/>
        </ul>
      </div>
      @endauth
  </div>
</div>

<!----------------------------------phone navbar-------------------------------->

<div class="md:hidden flex justify-between items-center mb-12">
  <div>
    <a style="font-family: 'Poppins', sans-serif;" class="text-xl"
    href="{{ route('welcome') }}">ClickSnap</a>
  </div>

  <div class="flex items-center">
    @guest

      <!-- signup/login -->
      <button class="btn btn-dash btn-xs" onclick="my_modal_5.showModal()">login or sign up</button>
      <dialog id="my_modal_5" class="modal modal-bottom sm:modal-middle">

        <div class="modal-box">

          <livewire:signup/>

          <div class="modal-action">
            <form method="dialog">
              <button class="btn">Close</button>
            </form>
          </div>

        </div>

      </dialog>

      <!-- menu -->
      <div class="drawer drawer-end">
        <input id="my-drawer-5" type="checkbox" class="drawer-toggle" />
        <div class="drawer-content">
          <!-- Page content here -->
          <label for="my-drawer-5" class="drawer-button btn btn-ghost btn-xs"><x-css-menu /></label>
        </div>
        <div class="drawer-side">
          <label for="my-drawer-5" aria-label="close sidebar" class="drawer-overlay"></label>
          <ul class="menu bg-base-200 min-h-full w-80 p-4flex flex-col justify-between">
            <!-- Sidebar content here -->
            <div>
              <li><a>Categories</a></li>
              <li><a>help center</a></li>
            </div>

            <li><label for="my-drawer-5" aria-label="close sidebar" 
             class="drawer-overlay btn">close menu</label></li>
          </ul>
        </div>
      </div>
    @endguest
    @auth
      <a href="{{ route('upload') }}" wire:navigate class="btn btn-sm btn-dash border-success m-2">upload <x-fas-upload class="w-2"/></a>

      <div class="drawer drawer-end">
        <input id="my-drawer-5" type="checkbox" class="drawer-toggle" />
        <div class="drawer-content">
          <!-- replace with profile picture -->
          <label for="my-drawer-5" class="drawer-button m-1 brn-xs/6 text-sm/3 cursor-pointer hover:bg-none">
            <!--x-css-menu /-->
            <img src="{{ Storage::url(Auth::user()->pic) }}" alt="" class="w-8 h-8 rounded-full object-cover border-1 border-white shadow-md">
          </label>
        </div>
        <div class="drawer-side">
          <label for="my-drawer-5" aria-label="close sidebar" class="drawer-overlay"></label>
          <ul class="menu bg-base-200 min-h-full w-80 p-4 flex flex-col justify-between">
            <!-- Sidebar content here -->
            <div>
              <li><a href="{{ route('upload') }}" wire:navigate class="flex justify-between">
                <span>upload photos</span>
                 <x-fas-upload class="w-3"/>
              </a></li>
              <li><a href="{{ route('account') }}" wire:navigate class="flex justify-between">
                <span>account</span> 
                <x-codicon-account class="w-3" />
              </a></li>

              <details class="group rounded-lg w-full">
                <summary class="font-semibold cursor-pointer flex items-center justify-between px-3 py-2 select-none">
                  Categories
                  <!-- Arrow that rotates -->
                  <svg
                    class="w-4 h-4 transition-transform duration-200 group-open:rotate-180"
                    xmlns="http://www.w3.org/2000/svg"
                    fill="none"
                    viewBox="0 0 24 24"
                    stroke="currentColor"
                  >
                    <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M19 9l-7 7-7-7" />
                  </svg>
                </summary>
              
                <ul class="menu w-full rounded-box p-2 shadow-sm mt-2">
                  <li><a href="{{ route('browse', ['query' => 'nature and landscape']) }}">Nature and Landscape</a></li>
                  <li><a href="{{ route('browse', ['query' => 'floral']) }}">Floral</a></li>
                  <li><a href="{{ route('browse', ['query' => 'architecture and cities']) }}">Architecture and Cities</a></li>
                  <li><a href="{{ route('browse', ['query' => 'cars and vehicles']) }}">Cars and Vehicles</a></li>
                  <li><a href="{{ route('browse', ['query' => 'animals']) }}">Animals</a></li>
                  <li><a href="{{ route('browse', ['query' => 'abstract']) }}">Abstract</a></li>
                  <li><a href="{{ route('browse', ['query' => 'dark']) }}">Dark</a></li>
                  <li><a href="{{ route('browse', ['query' => 'fantasy']) }}">Fantasy</a></li>
                  <li><a href="{{ route('browse', ['query' => 'space']) }}">Space</a></li>
                  <li><a href="{{ route('browse', ['query' => 'other']) }}">Other</a></li>
                </ul>
              </details>



              <livewire:logout/>
            </div>

            <li><label for="my-drawer-5" aria-label="close sidebar" 
             class="drawer-overlay btn right-2">close menu</label></li>

          </ul>
        </div>
      </div>
    @endauth
  </div>
</div>