int __usercall fetch_headers@<eax>(
        __int128 a1@<xmm0>,
        OggVorbis_File *vf,
        vorbis_info *vi,
        vorbis_comment *vc,
        void **serialno_list,
        int *serialno_n,
        ogg_page *og_ptr)
{
  int v8; // eax
  int v9; // eax
  int v10; // [esp+8h] [ebp-54h]
  __int64 v11; // [esp+Ch] [ebp-50h]
  __int64 next_page; // [esp+14h] [ebp-48h]
  ogg_packet op; // [esp+1Ch] [ebp-40h] BYREF
  ogg_page og; // [esp+40h] [ebp-1Ch] BYREF
  int v15; // [esp+50h] [ebp-Ch]
  int v16; // [esp+54h] [ebp-8h]
  int v17; // [esp+58h] [ebp-4h]

  v16 = 0;
  if ( !og_ptr )
  {
    next_page = get_next_page(vf, &og, (unsigned int)&_sbh_sizeHeaderList);
    if ( next_page == -128 )
      return -128;
    if ( next_page < 0 )
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
          ogg_free_impl(*serialno_list);
        *serialno_list = 0;
        *serialno_n = 0;
        v15 = -133;
        goto bail_header;
      }
      add_serialno(og_ptr, serialno_list, serialno_n);
    }
    if ( vf->ready_state < 3 )
    {
      v8 = ogg_page_serialno(og_ptr);
      ogg_stream_reset_serialno(&vf->os, v8);
      ogg_stream_pagein(&vf->os, og_ptr);
      if ( ogg_stream_packetout(&vf->os, &op) > 0 )
      {
        LOBYTE(v9) = vorbis_synthesis_idheader(&op);
        if ( v9 )
        {
          vf->ready_state = 3;
          v15 = vorbis_synthesis_headerin(a1, vi, vc, &op);
          if ( v15 )
          {
            v15 = -133;
bail_header:
            vorbis_info_clear(vi);
            vorbis_comment_clear(vc);
            vf->ready_state = 2;
            return v15;
          }
        }
      }
    }
    v11 = get_next_page(vf, og_ptr, (unsigned int)&_sbh_sizeHeaderList);
    if ( v11 == -128 )
    {
      v15 = -128;
      goto bail_header;
    }
    if ( v11 < 0 )
    {
      v15 = -132;
      goto bail_header;
    }
  }
  while ( vf->ready_state != 3 || vf->os.serialno != ogg_page_serialno(og_ptr) );
  ogg_stream_pagein(&vf->os, og_ptr);
LABEL_28:
  if ( vf->ready_state != 3 )
  {
    v15 = -132;
    goto bail_header;
  }
  v17 = 0;
LABEL_31:
  while ( v17 < 2 )
  {
    while ( v17 < 2 )
    {
      v10 = ogg_stream_packetout(&vf->os, &op);
      if ( !v10 )
        break;
      if ( v10 == -1 )
      {
        v15 = -133;
        goto bail_header;
      }
      v15 = vorbis_synthesis_headerin(a1, vi, vc, &op);
      if ( v15 )
        goto bail_header;
      ++v17;
    }
    while ( v17 < 2 )
    {
      if ( (((unsigned __int64)get_next_page(vf, og_ptr, (unsigned int)&_sbh_sizeHeaderList) >> 32) & 0x80000000) != 0LL )
      {
        v15 = -133;
        goto bail_header;
      }
      if ( vf->os.serialno == ogg_page_serialno(og_ptr) )
      {
        ogg_stream_pagein(&vf->os, og_ptr);
        goto LABEL_31;
      }
      if ( ogg_page_bos(og_ptr) )
      {
        if ( v16 )
        {
          v15 = -133;
          goto bail_header;
        }
        v16 = 1;
      }
    }
  }
  return 0;
}
