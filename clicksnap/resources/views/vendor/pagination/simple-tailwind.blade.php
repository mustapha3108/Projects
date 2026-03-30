@if ($paginator->hasPages())
    <nav role="navigation" aria-label="{!! __('Pagination Navigation') !!}" class="flex justify-center">
        <div class="join flex justify-center items-center">

          <a class="join-item btn btn-outline" @if ($paginator->onFirstPage()) disabled @endif href="{{ $paginator->previousPageUrl() }}">
            Back
          </a>
          <div class="join-item px-3">Page {{ $paginator->currentPage() }}</div>
          <a class="join-item btn btn-outline" @if (!$paginator->hasMorePages()) disabled @endif href="{{ $paginator->nextPageUrl() }}">
            Next
          </a>
        </div>
    </nav>
@endif
