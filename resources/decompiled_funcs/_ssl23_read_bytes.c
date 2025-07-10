unsigned int __cdecl ssl23_read_bytes(ssl_st *s, unsigned int n)
{
  unsigned int packet_length; // eax
  unsigned __int8 *packet; // ebx
  unsigned int result; // eax
  bio_st *rbio; // [esp-10h] [ebp-18h]

  packet_length = s->packet_length;
  if ( packet_length >= n )
    return n;
  packet = s->packet;
  rbio = s->rbio;
  s->rwstate = 3;
  for ( result = BIO_read(rbio, (char *)&packet[packet_length], n - packet_length);
        (int)result > 0;
        result = BIO_read(s->rbio, (char *)&packet[s->packet_length], n - s->packet_length) )
  {
    s->packet_length += result;
    result = s->packet_length;
    s->rwstate = 1;
    if ( result >= n )
      break;
    s->rwstate = 3;
  }
  return result;
}
