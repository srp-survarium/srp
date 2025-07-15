int __cdecl ogg_stream_reset_serialno(ogg_stream_state *os, int serialno)
{
  ogg_stream_state *v2; // edx
  int v4; // edx

  if ( ogg_stream_check(os) )
    return -1;
  ogg_stream_reset(v2);
  *(_DWORD *)(v4 + 336) = serialno;
  return 0;
}
