int __cdecl ssl_cert_inst(cert_st **o)
{
  cert_st *v2; // eax

  if ( o )
  {
    if ( *o )
      return 1;
    v2 = ssl_cert_new();
    *o = v2;
    if ( v2 )
    {
      return 1;
    }
    else
    {
      ERR_put_error(0x14u, 222, 65, ".\\ssl\\ssl_cert.c", 406);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x14u, 222, 67, ".\\ssl\\ssl_cert.c", 399);
    return 0;
  }
}
