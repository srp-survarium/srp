int __cdecl vorbis_packet_blocksize(vorbis_info *vi, ogg_packet *op)
{
  unsigned __int8 *packet; // ecx
  _DWORD *codec_setup; // ebx
  int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // eax
  oggpack_buffer b; // [esp+Ch] [ebp-14h] BYREF

  packet = op->packet;
  codec_setup = vi->codec_setup;
  memset(&b, 0, sizeof(b));
  b.storage = op->bytes;
  b.ptr = packet;
  b.buffer = packet;
  if ( oggpack_read(&b, 1u) )
    return -135;
  v5 = codec_setup[2];
  v6 = 0;
  while ( v5 > 1 )
  {
    ++v6;
    v5 >>= 1;
  }
  v7 = oggpack_read(&b, v6);
  if ( v7 == -1 )
    return -136;
  else
    return codec_setup[*(_DWORD *)codec_setup[v7 + 8]];
}
