int __usercall os_body_expand@<eax>(ogg_stream_state *os@<esi>, int needed@<eax>)
{
  int body_storage; // eax
  unsigned __int8 *v4; // eax

  body_storage = os->body_storage;
  if ( body_storage <= needed + os->body_fill )
  {
    v4 = (unsigned __int8 *)ogg_realloc_impl(os->body_data, body_storage + needed + 1024);
    if ( !v4 )
    {
      ogg_stream_clear(os);
      return -1;
    }
    os->body_storage += needed + 1024;
    os->body_data = v4;
  }
  return 0;
}
