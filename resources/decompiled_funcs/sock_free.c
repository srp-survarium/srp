int __cdecl sock_free(bio_st *a)
{
  if ( !a )
    return 0;
  if ( a->shutdown )
  {
    if ( a->init )
    {
      shutdown(a->num, 2);
      closesocket(a->num);
    }
    a->init = 0;
    a->flags = 0;
  }
  return 1;
}
