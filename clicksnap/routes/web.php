<?php

use Illuminate\Auth\Middleware\Authenticate;
use Illuminate\Support\Facades\{Route, Storage};
use Illuminate\Http\Request;
use App\Http\Middleware\mymid;
use App\Livewire\Browse;
use App\Models\{User, photo};


Route::get('/', function () {
    $photos = photo::orderBy('likes_count')->take(20)->with('userget', 'likes', 'savved')->get();
    return view('welcome', ['photos'=>$photos]);
})->name('welcome');

Route::view('/account', 'account')->name('account')->middleware(mymid::class);
Route::view('/upload', 'upload')->name('upload')->middleware(mymid::class);
Route::view('/mypics', 'mypics')->name('mypics')->middleware(mymid::class);

Route::get('/browse', function(){
    $query = request('query');
    return view('browsepage', ['query'=>$query]);
})->name('browse');

Route::get('/photos/{photoid}', function($photoid){
    $photo = photo::with('userget', 'likes', 'savved')->findOrFail($photoid);
    $suggestions = photo::search($photo->keywords)->take(20)->get();
    $suggestions->load('userget', 'likes', 'savved');
    return view('photopage', ['photo'=>$photo, 'suggestions'=>$suggestions]);
})->name('photopage');

Route::get('/author/{authorid}', function($authorid){
    $author = User::findOrFail($authorid);
    $photos = photo::where('user', $authorid)->with('userget', 'likes', 'savved')->simplePaginate(20);
    //$photos->load('userget', 'likes', 'savved');
    return view('authorpage', ['author'=>$author, 'photos'=>$photos]);
})->name('authorpage');

Route::get('/download/{title}/{path}', function ($title, $path) {
    $relativePath =  $path;

    if (!$path || !Storage::disk('public')->exists($relativePath)) {
        return response()->json([
            'error' => 'File not found',
            'path' => $relativePath
        ], 404);
    }

    return Storage::disk('public')->download($relativePath, $title);
})->where('path', '.*');


