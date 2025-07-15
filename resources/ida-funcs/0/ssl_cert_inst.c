int __usercall ssl_cert_inst@<eax>(int a1@<ebx>, cert_st **o)
{
  cert_st *v3; // eax

  if ( o )
  {
    if ( *o )
      return 1;
    v3 = ssl_cert_new(a1);
    *o = v3;
    if ( v3 )
    {
      return 1;
    }
    else
    {
      ERR_put_error(a1, 0x14u, 222, 65, ".\\ssl\\ssl_cert.c", 406);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x14u, 222, 67, ".\\ssl\\ssl_cert.c", 399);
    return 0;
  }
}
