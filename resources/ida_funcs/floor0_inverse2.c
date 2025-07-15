int __cdecl floor0_inverse2(vorbis_block *vb, vorbis_look_floor0 *i, float *memo, float *out)
{
  int *p_order; // esi
  float ampoffset; // [esp+4h] [ebp-14h]

  p_order = &i->vi->order;
  floor0_map_lazy_init(vb, i, p_order);
  if ( memo )
  {
    ampoffset = (float)p_order[4];
    vorbis_lsp_to_curve(out, i->linearmap[vb->W], i->n[vb->W], i->ln, memo, i->m, memo[i->m], ampoffset);
    return 1;
  }
  else
  {
    memset((int)out, 0, 4 * i->n[vb->W]);
    return 0;
  }
}
