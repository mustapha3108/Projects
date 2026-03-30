@php
if (! isset($scrollTo)) {
    $scrollTo = 'body';
}

$scrollIntoViewJsSnippet = ($scrollTo !== false)
    ? <<<JS
       (\$el.closest('{$scrollTo}') || document.querySelector('{$scrollTo}')).scrollIntoView()
    JS
    : '';
@endphp

<div>
    @if ($paginator->hasPages())
        <div class="join flex">
          <button class="join-item btn btn-outline" @if ($paginator->onFirstPage()) disabled @endif wire:click="previousPage('{{ $paginator->getPageName() }}')">
            <a href="{{ $paginator->previousPageUrl() }}">Back</a>
          </button>
          <button class="join-item btn">Page {{ $paginator->currentPage() }}</button>
          <button class="join-item btn btn-outline" @if (!$paginator->hasMorePages()) disabled @endif wire:click="nextPage('{{ $paginator->getPageName() }}')">
            <a href="{{ $paginator->nextPageUrl() }}">Next</a>
          </button>
        </div>
    @endif
</div>
