int __cdecl GENERAL_NAME_print(bio_st *out, GENERAL_NAME_st *gen)
{
  int result; // eax
  _DWORD *ptr; // eax
  unsigned __int8 *v4; // esi
  int v5; // ebx

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
      X509_NAME_print_ex(out, gen->d.directoryName, 0, (unsigned int)&unk_82031F);
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
      v4 = (unsigned __int8 *)ptr[2];
      if ( *ptr == 4 )
      {
        BIO_printf(out, "IP Address:%d.%d.%d.%d", *v4, v4[1], v4[2], v4[3]);
        result = 1;
      }
      else if ( *ptr == 16 )
      {
        BIO_printf(out, "IP Address");
        v5 = 8;
        do
        {
          BIO_printf(out, ":%X", v4[1] | (*v4 << 8));
          v4 += 2;
          --v5;
        }
        while ( v5 );
        BIO_puts(out, "\n");
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
      i2a_ASN1_OBJECT(out, gen->d.registeredID);
      goto LABEL_17;
    default:
LABEL_17:
      result = 1;
      break;
  }
  return result;
}
