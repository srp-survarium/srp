void __cdecl floor0_free_look(void *i)
{
  void **v1; // eax
  int v2; // eax

  if ( i )
  {
    v1 = (void **)*((_DWORD *)i + 2);
    if ( v1 )
    {
      if ( *v1 )
        ogg_free_impl(*v1);
      v2 = *((_DWORD *)i + 2);
      if ( *(_DWORD *)(v2 + 4) )
        ogg_free_impl(*(void **)(v2 + 4));
      ogg_free_impl(*((void **)i + 2));
    }
    memset(i, 0, 0x20u);
    ogg_free_impl(i);
  }
}
