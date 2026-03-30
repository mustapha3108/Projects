<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;
use Laravel\Scout\Searchable;
use App\Models\User;

class photo extends Model
{
    use Searchable;


    protected $guarded=[];


    public function toSearchableArray(): array
    {
        $array = $this->toArray();
        return $array;
    }

    public function userget()
    {
        return $this->belongsTo(User::class, 'user', 'id');
    }

    public function likes()
    {
        return $this->hasMany(likes::class);
    }
    
    public function savved()
    {
        return $this->hasMany(saves::class);
    }
}
