malloc_arena *__usercall arena_get2@<eax>(malloc_arena *a_tsd@<edx>, unsigned int size)
{
  malloc_arena *next; // esi
  malloc_arena *v3; // edx
  malloc_arena *v4; // edx
  malloc_arena *result; // eax
  malloc_arena *v6; // esi
  int v7; // edx

  if ( !a_tsd )
  {
    next = &main_arena;
    goto repeat;
  }
  next = a_tsd->next;
  if ( next )
  {
    while ( 1 )
    {
      do
      {
repeat:
        if ( !sltrywait(&next->mutex) )
        {
          TlsSetValue(arena_key, next);
          return next;
        }
        next = next->next;
      }
      while ( next != v3 );
      if ( !sltrywait(&list_lock) )
        break;
      next = v4;
    }
    _mm_pause();
    _InterlockedExchange(&list_lock, 0);
    result = int_new_arena(size);
    v6 = result;
    if ( result )
    {
      TlsSetValue(arena_key, result);
      v6->mutex = 0;
      slwait(&v6->mutex);
      slwait(&list_lock);
      v6->next = main_arena.next;
      main_arena.next = v6;
      _mm_pause();
      _InterlockedExchange(&list_lock, 0);
      return v7 == 0 ? v6 : 0;
    }
  }
  else
  {
    slwait(&main_arena.mutex);
    return &main_arena;
  }
  return result;
}
