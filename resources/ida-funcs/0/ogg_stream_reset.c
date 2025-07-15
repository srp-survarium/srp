int __cdecl ogg_stream_reset(ogg_stream_state *os)
{
  _DWORD *v1; // ecx
  int result; // eax

  if ( ogg_stream_check(os) )
    return -1;
  v1[85] = -1;
  result = 0;
  v1[2] = 0;
  v1[3] = 0;
  v1[7] = 0;
  v1[8] = 0;
  v1[9] = 0;
  v1[81] = 0;
  v1[82] = 0;
  v1[83] = 0;
  v1[86] = 0;
  v1[87] = 0;
  v1[88] = 0;
  v1[89] = 0;
  return result;
}
