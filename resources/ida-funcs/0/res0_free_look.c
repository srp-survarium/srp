void __cdecl res0_free_look(unsigned __int8 *i)
{
  int j; // edi
  void **v2; // eax
  int k; // edi

  if ( i )
  {
    for ( j = 0; j < *((_DWORD *)i + 1); ++j )
    {
      v2 = (void **)(*((_DWORD *)i + 5) + 4 * j);
      if ( *v2 )
        ogg_free_impl(*v2);
    }
    ogg_free_impl(*((void **)i + 5));
    for ( k = 0; k < *((_DWORD *)i + 6); ++k )
      ogg_free_impl(*(void **)(*((_DWORD *)i + 7) + 4 * k));
    ogg_free_impl(*((void **)i + 7));
    memset((int)i, 0, 0x2Cu);
    ogg_free_impl(i);
  }
}
