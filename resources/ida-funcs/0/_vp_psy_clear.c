void __usercall _vp_psy_clear(vorbis_look_psy *p@<esi>)
{
  int i; // edi
  int j; // ebx
  int k; // edi

  if ( p )
  {
    if ( p->ath )
      ogg_free_impl(p->ath);
    if ( p->octave )
      ogg_free_impl(p->octave);
    if ( p->bark )
      ogg_free_impl(p->bark);
    if ( p->tonecurves )
    {
      for ( i = 0; i < 17; ++i )
      {
        for ( j = 0; j < 8; ++j )
          ogg_free_impl(p->tonecurves[i][j]);
        ogg_free_impl(p->tonecurves[i]);
      }
      ogg_free_impl(p->tonecurves);
    }
    if ( p->noiseoffset )
    {
      for ( k = 0; k < 3; ++k )
        ogg_free_impl(p->noiseoffset[k]);
      ogg_free_impl(p->noiseoffset);
    }
    memset((int)p, 0, sizeof(vorbis_look_psy));
  }
}
