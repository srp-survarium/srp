bool __cdecl vorbis_synthesis_idheader(ogg_packet *op)
{
  bool result; // al
  unsigned __int8 *packet; // edx
  int bytes; // eax
  bool v4; // zf
  int v5; // ecx
  const char *v6; // edi
  int *v7; // esi
  oggpack_buffer b; // [esp+8h] [ebp-1Ch] BYREF
  int v9; // [esp+1Ch] [ebp-8h] BYREF
  __int16 v10; // [esp+20h] [ebp-4h]

  result = 0;
  if ( op )
  {
    v4 = op->b_o_s == 0;
    packet = op->packet;
    memset(&b, 0, sizeof(b));
    bytes = op->bytes;
    b.ptr = packet;
    b.buffer = packet;
    b.storage = bytes;
    if ( v4 || oggpack_read(&b, 8u) != 1 )
    {
      return 0;
    }
    else
    {
      v9 = 0;
      v10 = 0;
      v_readstring((char *)&v9, &b, 6);
      v4 = 1;
      v5 = 3;
      v6 = "vorbis";
      v7 = &v9;
      do
      {
        if ( !v5 )
          break;
        v4 = *(_WORD *)v7 == *(_WORD *)v6;
        v7 = (int *)((char *)v7 + 2);
        v6 += 2;
        --v5;
      }
      while ( v4 );
      return v4;
    }
  }
  return result;
}
