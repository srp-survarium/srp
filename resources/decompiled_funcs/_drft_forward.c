void __usercall drft_forward(drft_lookup *l@<edx>, float *data)
{
  if ( l->n != 1 )
    drftf1(data, l->splitcache, l->n, l->trigcache, &l->trigcache[l->n]);
}
