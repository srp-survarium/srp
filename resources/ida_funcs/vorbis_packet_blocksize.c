int __cdecl vorbis_packet_blocksize(vorbis_info *vi, ogg_packet *op)
{
  unsigned __int8 *packet; // ecx
  _DWORD *codec_setup; // esi
  int bytes; // ecx
  int v6; // ecx
  unsigned int i; // eax
  unsigned int v8; // eax
  oggpack_buffer opb; // [esp+8h] [ebp-14h] BYREF

  packet = op->packet;
  codec_setup = vi->codec_setup;
  opb.storage = 0;
  opb.ptr = packet;
  opb.buffer = packet;
  bytes = op->bytes;
  opb.endbyte = 0;
  opb.endbit = 0;
  opb.storage = bytes;
  if ( oggpack_read(&opb, 1u) )
    return -135;
  v6 = codec_setup[2];
  for ( i = 0; v6 > 1; ++i )
    v6 >>= 1;
  v8 = oggpack_read(&opb, i);
  if ( v8 == -1 )
    return -136;
  else
    return codec_setup[*(_DWORD *)codec_setup[v8 + 8]];
}
