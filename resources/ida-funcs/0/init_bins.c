void __usercall init_bins(malloc_state *m@<eax>)
{
  malloc_chunk **smallbins; // eax
  int v2; // ecx

  smallbins = m->smallbins;
  v2 = 32;
  do
  {
    smallbins[3] = (malloc_chunk *)smallbins;
    smallbins[2] = (malloc_chunk *)smallbins;
    smallbins += 2;
    --v2;
  }
  while ( v2 );
}
