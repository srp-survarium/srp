int __usercall vorbis_unpack_comment@<eax>(vorbis_comment *vc@<edi>, oggpack_buffer *opb@<eax>)
{
  signed int v3; // ebx
  unsigned __int8 *v4; // eax
  signed int v5; // ecx
  int *v6; // eax
  bool v7; // cc
  signed int v8; // ebx
  int v10; // [esp+8h] [ebp-4h]

  v3 = oggpack_read(opb, 0x20u);
  if ( v3 < 0 )
    goto err_out_0;
  if ( v3 > opb->storage - 8 )
    goto err_out_0;
  v4 = ogg_calloc_impl(v3 + 1, 1u);
  vc->vendor = (char *)v4;
  v_readstring((char *)v4, opb, v3);
  v5 = oggpack_read(opb, 0x20u);
  if ( v5 < 0 || v5 > (opb->storage - (opb->endbit + 7) / 8 - opb->endbyte) >> 2 )
    goto err_out_0;
  vc->comments = v5;
  vc->user_comments = (char **)ogg_calloc_impl(v5 + 1, 4u);
  v6 = (int *)ogg_calloc_impl(vc->comments + 1, 4u);
  v10 = 0;
  v7 = vc->comments <= 0;
  vc->comment_lengths = v6;
  if ( !v7 )
  {
    do
    {
      v8 = oggpack_read(opb, 0x20u);
      if ( v8 < 0 || v8 > opb->storage - (opb->endbit + 7) / 8 - opb->endbyte )
        goto err_out_0;
      vc->comment_lengths[v10] = v8;
      vc->user_comments[v10] = (char *)ogg_calloc_impl(v8 + 1, 1u);
      v_readstring(vc->user_comments[v10++], opb, v8);
    }
    while ( v10 < vc->comments );
  }
  if ( oggpack_read(opb, 1u) != 1 )
  {
err_out_0:
    vorbis_comment_clear(vc);
    return -133;
  }
  return 0;
}
