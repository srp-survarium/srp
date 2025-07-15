int __cdecl fetch_headers(
        OggVorbis_File *vf,
        vorbis_info *vi,
        vorbis_comment *vc,
        void **serialno_list,
        int *serialno_n,
        ogg_page *og_ptr)
{
  int v7; // eax
  int result; // [esp+8h] [ebp-54h]
  __int64 next_page; // [esp+Ch] [ebp-50h]
  __int64 llret; // [esp+14h] [ebp-48h]
  ogg_packet op; // [esp+1Ch] [ebp-40h] BYREF
  ogg_page og; // [esp+40h] [ebp-1Ch] BYREF
  int ret; // [esp+50h] [ebp-Ch]
  int allbos; // [esp+54h] [ebp-8h]
  int i; // [esp+58h] [ebp-4h]

  allbos = 0;
  if ( !og_ptr )
  {
    llret = get_next_page(vf, &og, (unsigned int)&_sbh_sizeHeaderList);
    if ( llret == -128 )
      return -128;
    if ( llret < 0 )
      return -132;
    og_ptr = &og;
  }
  vorbis_info_init(vi);
  vorbis_comment_init(vc);
  vf->ready_state = 2;
  do
  {
    if ( !ogg_page_bos(og_ptr) )
      goto LABEL_28;
    if ( serialno_list )
    {
      if ( lookup_page_serialno(og_ptr, (int *)*serialno_list, *serialno_n) )
      {
        if ( *serialno_list )
          free(*serialno_list);
        *serialno_list = 0;
        *serialno_n = 0;
        ret = -133;
        goto bail_header;
      }
      add_serialno(og_ptr, (int **)serialno_list, serialno_n);
    }
    if ( vf->ready_state < 3 )
    {
      v7 = ogg_page_serialno(og_ptr);
      ogg_stream_reset_serialno(&vf->os, v7);
      ogg_stream_pagein(&vf->os, og_ptr);
      if ( ogg_stream_packetout(&vf->os, &op) > 0 )
      {
        if ( vorbis_synthesis_idheader(&op) )
        {
          vf->ready_state = 3;
          ret = vorbis_synthesis_headerin(vi, vc, &op);
          if ( ret )
          {
            ret = -133;
bail_header:
            vorbis_info_clear(vi);
            vorbis_comment_clear(vc);
            vf->ready_state = 2;
            return ret;
          }
        }
      }
    }
    next_page = get_next_page(vf, og_ptr, (unsigned int)&_sbh_sizeHeaderList);
    if ( next_page == -128 )
    {
      ret = -128;
      goto bail_header;
    }
    if ( next_page < 0 )
    {
      ret = -132;
      goto bail_header;
    }
  }
  while ( vf->ready_state != 3 || vf->os.serialno != ogg_page_serialno(og_ptr) );
  ogg_stream_pagein(&vf->os, og_ptr);
LABEL_28:
  if ( vf->ready_state != 3 )
  {
    ret = -132;
    goto bail_header;
  }
  i = 0;
LABEL_31:
  while ( i < 2 )
  {
    while ( i < 2 )
    {
      result = ogg_stream_packetout(&vf->os, &op);
      if ( !result )
        break;
      if ( result == -1 )
      {
        ret = -133;
        goto bail_header;
      }
      ret = vorbis_synthesis_headerin(vi, vc, &op);
      if ( ret )
        goto bail_header;
      ++i;
    }
    while ( i < 2 )
    {
      if ( (((unsigned __int64)get_next_page(vf, og_ptr, (unsigned int)&_sbh_sizeHeaderList) >> 32) & 0x80000000) != 0LL )
      {
        ret = -133;
        goto bail_header;
      }
      if ( vf->os.serialno == ogg_page_serialno(og_ptr) )
      {
        ogg_stream_pagein(&vf->os, og_ptr);
        goto LABEL_31;
      }
      if ( ogg_page_bos(og_ptr) )
      {
        if ( allbos )
        {
          ret = -133;
          goto bail_header;
        }
        allbos = 1;
      }
    }
  }
  return 0;
}
