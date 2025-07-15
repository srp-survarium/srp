void __usercall drft_clear(drft_lookup *l@<eax>)
{
  float **p_trigcache; // edi

  if ( l )
  {
    if ( l->trigcache )
      ogg_free_impl(l->trigcache);
    if ( l->splitcache )
      ogg_free_impl(l->splitcache);
    l->n = 0;
    p_trigcache = &l->trigcache;
    *p_trigcache = 0;
    p_trigcache[1] = 0;
  }
}
