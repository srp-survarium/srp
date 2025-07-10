int __usercall print_nc_ipadd@<eax>(bio_st *bp@<ebx>, asn1_string_st *ip)
{
  unsigned __int8 *data; // esi
  int length; // edi
  int i; // edi

  data = ip->data;
  length = ip->length;
  BIO_puts(bp, "IP:");
  if ( length == 8 )
  {
    BIO_printf(bp, "%d.%d.%d.%d/%d.%d.%d.%d", *data, data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
    return 1;
  }
  else if ( length == 32 )
  {
    for ( i = 0; i < 16; ++i )
    {
      BIO_printf(bp, "%X", data[1] | (*data << 8));
      data += 2;
      if ( i == 7 )
      {
        BIO_puts(bp, "/");
      }
      else if ( i != 15 )
      {
        BIO_puts(bp, (const char *)&stru_95963C.m_max_end);
      }
    }
    return 1;
  }
  else
  {
    BIO_printf(bp, "IP Address:<invalid>");
    return 1;
  }
}
