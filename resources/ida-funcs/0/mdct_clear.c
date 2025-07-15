void __usercall mdct_clear(mdct_lookup *l@<eax>)
{
  int *p_log2n; // edi

  if ( l )
  {
    if ( l->trig )
      ogg_free_impl(l->trig);
    if ( l->bitrev )
      ogg_free_impl(l->bitrev);
    l->n = 0;
    p_log2n = &l->log2n;
    *p_log2n++ = 0;
    *p_log2n++ = 0;
    *p_log2n = 0;
    p_log2n[1] = 0;
  }
}
