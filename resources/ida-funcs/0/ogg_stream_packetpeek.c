int __cdecl ogg_stream_packetpeek(ogg_stream_state *os, ogg_packet *op)
{
  if ( ogg_stream_check(os) )
    return 0;
  else
    return packetout(os, op, 0);
}
