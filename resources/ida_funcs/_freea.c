void __cdecl _freea(_DWORD *_Memory)
{
  if ( _Memory )
  {
    if ( *(_Memory - 2) == 56797 )
      free(_Memory - 2);
  }
}
