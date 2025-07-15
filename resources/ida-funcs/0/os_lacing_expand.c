int __usercall os_lacing_expand@<eax>(ogg_stream_state *os@<esi>, int needed@<eax>)
{
  int lacing_storage; // eax
  int *v4; // eax
  __int64 *v6; // eax

  lacing_storage = os->lacing_storage;
  if ( lacing_storage <= needed + os->lacing_fill )
  {
    v4 = (int *)ogg_realloc_impl(os->lacing_vals, 4 * (needed + lacing_storage) + 128);
    if ( !v4
      || (os->lacing_vals = v4,
          (v6 = (__int64 *)ogg_realloc_impl(os->granule_vals, 8 * (needed + os->lacing_storage) + 256)) == 0) )
    {
      ogg_stream_clear(os);
      return -1;
    }
    os->lacing_storage += needed + 32;
    os->granule_vals = v6;
  }
  return 0;
}
