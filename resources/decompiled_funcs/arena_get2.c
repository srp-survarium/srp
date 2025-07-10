malloc_arena *__usercall arena_get2@<eax>(malloc_arena *a_tsd@<edx>, const void *a2@<edi>, unsigned int size)
{
  malloc_arena *next; // esi
  volatile __int32 *p_mutex; // ecx
  malloc_arena *result; // eax
  malloc_arena *v6; // esi
  volatile __int32 *v7; // ecx
  malloc_arena *a; // [esp+4h] [ebp-20h]
  malloc_arena *aa; // [esp+4h] [ebp-20h]

  if ( !a_tsd )
  {
    a_tsd = &main_arena;
    next = &main_arena;
LABEL_3:
    a = next;
    goto repeat;
  }
  next = a_tsd->next;
  a = next;
  if ( next )
  {
    do
    {
repeat:
      p_mutex = &a->mutex;
      _mm_pause();
      if ( !_InterlockedExchange(p_mutex, 1) )
      {
        TlsSetValue(arena_key, next);
        return next;
      }
      next = next->next;
      a = next;
    }
    while ( next != a_tsd );
    _mm_pause();
    if ( _InterlockedExchange(&list_lock, 1) )
    {
      next = a_tsd;
      goto LABEL_3;
    }
    _mm_pause();
    _InterlockedExchange(&list_lock, 0);
    result = (malloc_arena *)int_new_arena(size, a2);
    v6 = result;
    aa = result;
    if ( result )
    {
      TlsSetValue(arena_key, result);
      v6->mutex = 0;
      do
      {
        v7 = &aa->mutex;
        _mm_pause();
      }
      while ( _InterlockedExchange(v7, 1) );
      do
        _mm_pause();
      while ( _InterlockedExchange(&list_lock, 1) );
      v6->next = main_arena.next;
      main_arena.next = v6;
      _mm_pause();
      _InterlockedExchange(&list_lock, 0);
      return v6;
    }
  }
  else
  {
    do
      _mm_pause();
    while ( _InterlockedExchange(&main_arena.mutex, 1) );
    return &main_arena;
  }
  return result;
}
