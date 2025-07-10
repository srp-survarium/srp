int __cdecl vorbis_synthesis_headerin(vorbis_info *vi, vorbis_comment *vc, ogg_packet *op)
{
  unsigned __int8 *packet; // ecx
  int v5; // esi
  char *v6; // ebx
  char buffer[6]; // [esp+4h] [ebp-1Ch] BYREF
  oggpack_buffer opb; // [esp+Ch] [ebp-14h] BYREF
  unsigned int packtype; // [esp+2Ch] [ebp+Ch]

  if ( !op )
    return -133;
  packet = op->packet;
  memset(&opb.buffer, 0, 12);
  opb.endbyte = 0;
  opb.endbit = 0;
  opb.storage = op->bytes;
  opb.ptr = packet;
  opb.buffer = packet;
  packtype = oggpack_read(&opb, 8u);
  memset(buffer, 0, sizeof(buffer));
  v5 = 6;
  v6 = buffer;
  do
  {
    --v5;
    *v6++ = oggpack_read(&opb, 8u);
  }
  while ( v5 );
  if ( *(_DWORD *)buffer != 1651666806 || buffer[4] != 105 || buffer[5] != 115 )
    return -132;
  if ( packtype != 1 )
  {
    if ( packtype == 3 )
    {
      if ( vi->rate )
        return vorbis_unpack_comment(vc, &opb);
    }
    else if ( packtype == 5 && vi->rate && vc->vendor )
    {
      return vorbis_unpack_books(&opb, (bool)v6, 0, vi);
    }
    return -133;
  }
  if ( !op->b_o_s || vi->rate )
    return -133;
  return vorbis_unpack_info((vostok::memory::doug_lea_mt_allocator *)vi, &opb, (bool)op);
}
