__int64 __cdecl initial_pcmoffset(OggVorbis_File *vf, vorbis_info *vi)
{
  int v2; // eax
  __int64 v3; // rax
  __int64 v5; // [esp+0h] [ebp-5Ch]
  int thisblock; // [esp+10h] [ebp-4Ch]
  ogg_packet op; // [esp+14h] [ebp-48h] BYREF
  __int64 accumulated; // [esp+34h] [ebp-28h]
  int lastblock; // [esp+40h] [ebp-1Ch]
  int result; // [esp+44h] [ebp-18h]
  ogg_page og; // [esp+48h] [ebp-14h] BYREF
  int serialno; // [esp+58h] [ebp-4h]

  accumulated = 0;
  lastblock = -1;
  serialno = vf->os.serialno;
  while ( (((unsigned __int64)get_next_page(vf, &og, -1) >> 32) & 0x80000000) == 0LL && !ogg_page_bos(&og) )
  {
    v2 = ogg_page_serialno(&og);
    if ( v2 == serialno )
    {
      ogg_stream_pagein(&vf->os, &og);
      while ( 1 )
      {
        result = ogg_stream_packetout(&vf->os, &op);
        if ( !result )
          break;
        if ( result > 0 )
        {
          thisblock = vorbis_packet_blocksize(vi, &op);
          if ( lastblock != -1 )
            accumulated += (thisblock + lastblock) >> 2;
          lastblock = thisblock;
        }
      }
      v5 = ogg_page_granulepos(&og);
      if ( (HIDWORD(v5) & (unsigned int)v5) != 0xFFFFFFFF )
      {
        v3 = ogg_page_granulepos(&og);
        accumulated = v3 - accumulated;
        break;
      }
    }
  }
  if ( accumulated < 0 )
    return 0;
  return accumulated;
}
