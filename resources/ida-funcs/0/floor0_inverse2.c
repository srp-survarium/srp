int __usercall floor0_inverse2@<eax>(
        __int128 a1@<xmm2>,
        vorbis_block *vb,
        vorbis_look_floor0 *i,
        float *memo,
        float *out)
{
  vorbis_info_floor0 *vi; // edi
  int W; // eax

  vi = i->vi;
  floor0_map_lazy_init(vb, i, &vi->order);
  W = vb->W;
  if ( memo )
  {
    vorbis_lsp_to_curve(
      (int)vi,
      (int)i,
      a1,
      out,
      i->linearmap[W],
      i->n[W],
      i->ln,
      memo,
      i->m,
      memo[i->m],
      (float)vi->ampdB);
    return 1;
  }
  else
  {
    memset((int)out, 0, 4 * i->n[W]);
    return 0;
  }
}
