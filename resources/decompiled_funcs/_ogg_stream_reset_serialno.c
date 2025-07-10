int __cdecl ogg_stream_reset_serialno(ogg_stream_state *os, int serialno)
{
  int v3; // edx

  if ( !os || !os->body_data )
    return -1;
  ogg_stream_reset(os);
  *(_DWORD *)(v3 + 336) = serialno;
  return 0;
}
