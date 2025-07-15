int __usercall ogg_stream_check@<eax>(ogg_stream_state *os@<eax>)
{
  if ( os && os->body_data )
    return 0;
  else
    return -1;
}
