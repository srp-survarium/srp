void __usercall _ve_envelope_clear(envelope_lookup *e@<esi>)
{
  void **p_window; // edi
  int v2; // ebx

  mdct_clear(&e->mdct);
  p_window = (void **)&e->band[0].window;
  v2 = 7;
  do
  {
    ogg_free_impl(*p_window);
    p_window += 4;
    --v2;
  }
  while ( v2 );
  ogg_free_impl(e->mdct_win);
  ogg_free_impl(e->filter);
  ogg_free_impl(e->mark);
  memset((int)e, 0, sizeof(envelope_lookup));
}
