int __usercall vorbis_unpack_comment@<eax>(vorbis_comment *vc@<esi>, oggpack_buffer *opb@<eax>)
{
  signed int v3; // ecx
  vostok::memory *v4; // ebx
  char *v5; // eax
  int *v6; // eax
  int v7; // ebp
  bool v8; // cc

  v4 = (vostok::memory *)oggpack_read(opb, 0x20u);
  if ( (int)v4 < 0 )
    goto err_out_3;
  if ( (int)v4 > opb->storage - 8 )
    goto err_out_3;
  v5 = (char *)calloc((unsigned int)v4 + 1, 1u);
  vc->vendor = v5;
  v_readstring(opb, (int)v4, v5);
  v3 = oggpack_read(opb, 0x20u);
  if ( v3 < 0 || v3 > (opb->storage - (opb->endbit + 7) / 8 - opb->endbyte) >> 2 )
    goto err_out_3;
  vc->comments = v3;
  vc->user_comments = (char **)calloc(v3 + 1, 4u);
  v6 = (int *)calloc(vc->comments + 1, 4u);
  v7 = 0;
  v8 = vc->comments <= 0;
  vc->comment_lengths = v6;
  if ( !v8 )
  {
    do
    {
      v4 = (vostok::memory *)oggpack_read(opb, 0x20u);
      if ( (int)v4 < 0 )
        goto err_out_3;
      v3 = opb->storage - (opb->endbit + 7) / 8 - opb->endbyte;
      if ( (int)v4 > v3 )
        goto err_out_3;
      vc->comment_lengths[v7] = (int)v4;
      vc->user_comments[v7] = (char *)calloc((unsigned int)v4 + 1, 1u);
      v_readstring(opb, (int)v4, vc->user_comments[v7++]);
    }
    while ( v7 < vc->comments );
  }
  if ( oggpack_read(opb, 1u) != 1 )
  {
err_out_3:
    vorbis_comment_clear((vostok::memory::doug_lea_mt_allocator *)v3, v4, (vostok::memory *)opb, vc);
    return -133;
  }
  return 0;
}
