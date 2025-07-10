BOOL __cdecl vorbis_synthesis_idheader(ogg_packet *op)
{
  BOOL result; // eax
  bool v2; // zf
  unsigned __int8 *packet; // edx
  int bytes; // eax
  int v5; // esi
  char *v6; // ebx
  char buffer[6]; // [esp+0h] [ebp-1Ch] BYREF
  oggpack_buffer opb; // [esp+8h] [ebp-14h] BYREF

  result = 0;
  if ( op )
  {
    v2 = op->b_o_s == 0;
    packet = op->packet;
    memset(&opb.buffer, 0, 12);
    opb.endbyte = 0;
    opb.endbit = 0;
    bytes = op->bytes;
    opb.ptr = packet;
    opb.buffer = packet;
    opb.storage = bytes;
    if ( v2 )
    {
      return 0;
    }
    else
    {
      if ( oggpack_read(&opb, 8u) != 1 )
        return 0;
      memset(buffer, 0, sizeof(buffer));
      v5 = 6;
      v6 = buffer;
      do
      {
        --v5;
        *v6++ = oggpack_read(&opb, 8u);
      }
      while ( v5 );
      return *(_DWORD *)buffer == 1651666806 && buffer[4] == 105 && buffer[5] == 115;
    }
  }
  return result;
}
