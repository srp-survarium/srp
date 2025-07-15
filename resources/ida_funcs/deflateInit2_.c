int __cdecl deflateInit2_(
        z_stream_s *strm,
        unsigned int level,
        int method,
        int windowBits,
        int memLevel,
        unsigned int strategy,
        const char *version,
        int stream_size)
{
  int v8; // ebp
  int v10; // ebx
  internal_state *v11; // eax
  internal_state *v12; // esi
  int v13; // eax
  void *v14; // eax
  unsigned int dummy; // ecx
  void *v16; // eax
  unsigned int v17; // ecx
  char *v18; // eax
  unsigned int v19; // ecx
  bool v20; // zf

  v8 = 1;
  if ( !version || *version != 49 || stream_size != 56 )
    return -6;
  if ( !strm )
    return -2;
  strm->msg = 0;
  if ( !strm->zalloc )
  {
    strm->zalloc = zcalloc;
    strm->opaque = 0;
  }
  if ( !strm->zfree )
    strm->zfree = jpeg_free_small;
  if ( level == -1 )
    level = 6;
  v10 = windowBits;
  if ( windowBits >= 0 )
  {
    if ( windowBits > 15 )
    {
      v8 = 2;
      v10 = windowBits - 16;
    }
  }
  else
  {
    v8 = 0;
    v10 = -windowBits;
  }
  if ( (unsigned int)(memLevel - 1) > 8 || method != 8 || (unsigned int)(v10 - 8) > 7 || level > 9 || strategy > 4 )
    return -2;
  if ( v10 == 8 )
    v10 = 9;
  v11 = (internal_state *)strm->zalloc(strm->opaque, 1, 5824);
  v12 = v11;
  if ( v11 )
  {
    strm->state = v11;
    v11[6].dummy = v8;
    v11[12].dummy = v10;
    v11[13].dummy = (1 << v10) - 1;
    v13 = 1 << (memLevel + 7);
    v12[20].dummy = memLevel + 7;
    v12->dummy = (int)strm;
    v12[19].dummy = v13;
    v12[21].dummy = v13 - 1;
    v12[7].dummy = 0;
    v12[11].dummy = 1 << v10;
    v12[22].dummy = (memLevel + 9) / 3u;
    v14 = strm->zalloc(strm->opaque, 1 << v10, 2);
    dummy = v12[11].dummy;
    v12[14].dummy = (int)v14;
    v16 = strm->zalloc(strm->opaque, dummy, 2);
    v17 = v12[19].dummy;
    v12[16].dummy = (int)v16;
    v12[17].dummy = (int)strm->zalloc(strm->opaque, v17, 2);
    v12[1447].dummy = 1 << (memLevel + 6);
    v18 = (char *)strm->zalloc(strm->opaque, 1 << (memLevel + 6), 4);
    v19 = v12[1447].dummy;
    v20 = v12[14].dummy == 0;
    v12[2].dummy = (int)v18;
    v12[3].dummy = 4 * v19;
    if ( !v20 && v12[16].dummy && v12[17].dummy && v18 )
    {
      v12[1449].dummy = (int)&v18[2 * (v19 >> 1)];
      v12[1446].dummy = (int)&v18[2 * v19 + v19];
      v12[33].dummy = level;
      v12[34].dummy = strategy;
      LOBYTE(v12[9].dummy) = 8;
      return deflateReset(strm);
    }
    v12[1].dummy = 666;
    strm->msg = (char *)z_errmsg[6];
    deflateEnd(strm);
  }
  return -4;
}
