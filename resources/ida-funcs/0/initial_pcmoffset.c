__int64 __cdecl initial_pcmoffset(OggVorbis_File *vf, vorbis_info *vi)
{
  int v2; // eax
  int v3; // edx
  __int64 v4; // rax
  int v6; // [esp+0h] [ebp-5Ch]
  int v7; // [esp+10h] [ebp-4Ch]
  ogg_packet op; // [esp+14h] [ebp-48h] BYREF
  __int64 v9; // [esp+34h] [ebp-28h]
  int v10; // [esp+40h] [ebp-1Ch]
  int v11; // [esp+44h] [ebp-18h]
  ogg_page og; // [esp+48h] [ebp-14h] BYREF
  int serialno; // [esp+58h] [ebp-4h]

  v9 = 0;
  v10 = -1;
  serialno = vf->os.serialno;
  while ( (((unsigned __int64)get_next_page(vf, &og, -1) >> 32) & 0x80000000) == 0LL && !ogg_page_bos(&og) )
  {
    v2 = ogg_page_serialno(&og);
    if ( v2 == serialno )
    {
      ogg_stream_pagein(&vf->os, &og);
      while ( 1 )
      {
        v11 = ogg_stream_packetout(&vf->os, &op);
        if ( !v11 )
          break;
        if ( v11 > 0 )
        {
          v7 = vorbis_packet_blocksize(vi, &op);
          if ( v10 != -1 )
            v9 += (v7 + v10) >> 2;
          v10 = v7;
        }
      }
      v6 = ogg_page_granulepos(&og);
      if ( (v3 & v6) != 0xFFFFFFFF )
      {
        LODWORD(v4) = ogg_page_granulepos(&og);
        v9 = v4 - v9;
        break;
      }
    }
  }
  if ( v9 < 0 )
    return 0;
  return v9;
}
