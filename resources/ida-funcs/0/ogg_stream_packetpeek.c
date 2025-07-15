int __cdecl ogg_stream_packetpeek(ogg_stream_state *os, ogg_packet *op)
{
  if ( os && os->body_data )
    return packetout(os, op, 0);
  else
    return 0;
}
