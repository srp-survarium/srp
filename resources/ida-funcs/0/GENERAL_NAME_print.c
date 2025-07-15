int __usercall GENERAL_NAME_print@<eax>(int a1@<ebx>, bio_st *out, GENERAL_NAME_st *gen)
{
  int result; // eax
  _DWORD *ptr; // eax
  unsigned __int8 *v5; // esi
  int v6; // ebx

  switch ( gen->type )
  {
    case 0:
      BIO_printf(out, "othername:<unsupported>");
      result = 1;
      break;
    case 1:
      BIO_printf(out, "email:%s", *((const char **)gen->d.ptr + 2));
      result = 1;
      break;
    case 2:
      BIO_printf(out, "DNS:%s", *((const char **)gen->d.ptr + 2));
      result = 1;
      break;
    case 3:
      BIO_printf(out, "X400Name:<unsupported>");
      result = 1;
      break;
    case 4:
      BIO_printf(out, "DirName: ");
      X509_NAME_print_ex(out, gen->d.directoryName, 0, 0x82031Fu);
      result = 1;
      break;
    case 5:
      BIO_printf(out, "EdiPartyName:<unsupported>");
      result = 1;
      break;
    case 6:
      BIO_printf(out, "URI:%s", *((const char **)gen->d.ptr + 2));
      result = 1;
      break;
    case 7:
      ptr = gen->d.ptr;
      v5 = (unsigned __int8 *)ptr[2];
      if ( *ptr == 4 )
      {
        BIO_printf(out, "IP Address:%d.%d.%d.%d", *v5, v5[1], v5[2], v5[3]);
        result = 1;
      }
      else if ( *ptr == 16 )
      {
        BIO_printf(out, "IP Address");
        v6 = 8;
        do
        {
          BIO_printf(out, ":%X", v5[1] | (*v5 << 8));
          v5 += 2;
          --v6;
        }
        while ( v6 );
        BIO_puts(0, out, "\n");
        result = 1;
      }
      else
      {
        BIO_printf(out, "IP Address:<invalid>");
        result = 1;
      }
      break;
    case 8:
      BIO_printf(out, "Registered ID");
      i2a_ASN1_OBJECT(a1, out, gen->d.registeredID);
      goto LABEL_17;
    default:
LABEL_17:
      result = 1;
      break;
  }
  return result;
}
