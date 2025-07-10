stack_st_CONF_VALUE *__cdecl i2v_GENERAL_NAME(v3_ext_method *method, GENERAL_NAME_st *gen, stack_st_CONF_VALUE *ret)
{
  _DWORD *ptr; // ecx
  unsigned __int8 *v4; // ebx
  int i; // ebp
  unsigned int v6; // eax
  char *v7; // edi
  char *v9; // edi
  stack_st_CONF_VALUE *extlist; // [esp+4h] [ebp-110h] BYREF
  char v13[7]; // [esp+8h] [ebp-10Ch] BYREF
  char v14; // [esp+Fh] [ebp-105h] BYREF
  char buf[256]; // [esp+10h] [ebp-104h] BYREF

  extlist = ret;
  switch ( gen->type )
  {
    case 0:
      X509V3_add_value("othername", "<unsupported>", &extlist);
      return extlist;
    case 1:
      X509V3_add_value_uchar("email", *((const unsigned __int8 **)gen->d.ptr + 2), &extlist);
      return extlist;
    case 2:
      X509V3_add_value_uchar("DNS", *((const unsigned __int8 **)gen->d.ptr + 2), &extlist);
      return extlist;
    case 3:
      X509V3_add_value("X400Name", "<unsupported>", &extlist);
      return extlist;
    case 4:
      X509_NAME_oneline(gen->d.directoryName, buf, 256);
      X509V3_add_value("DirName", buf, &extlist);
      return extlist;
    case 5:
      X509V3_add_value("EdiPartyName", "<unsupported>", &extlist);
      return extlist;
    case 6:
      X509V3_add_value_uchar("URI", *((const unsigned __int8 **)gen->d.ptr + 2), &extlist);
      return extlist;
    case 7:
      ptr = gen->d.ptr;
      v4 = (unsigned __int8 *)ptr[2];
      if ( *ptr == 4 )
      {
        BIO_snprintf(buf, 0x100u, "%d.%d.%d.%d", *v4, v4[1], v4[2], v4[3]);
LABEL_20:
        X509V3_add_value("IP Address", buf, &extlist);
        return extlist;
      }
      if ( *ptr == 16 )
      {
        buf[0] = 0;
        for ( i = 0; i < 8; ++i )
        {
          BIO_snprintf(v13, 5u, "%X", v4[1] | (*v4 << 8));
          v4 += 2;
          v6 = strlen(v13) + 1;
          v7 = &v14;
          while ( *++v7 )
            ;
          qmemcpy(v7, v13, v6);
          if ( i != 7 )
          {
            v9 = &v14;
            while ( *++v9 )
              ;
            *(_WORD *)v9 = 58;
          }
        }
        goto LABEL_20;
      }
      X509V3_add_value("IP Address", "<invalid>", &extlist);
      return extlist;
    case 8:
      i2t_ASN1_OBJECT(buf, 0x100u, gen->d.registeredID);
      X509V3_add_value("Registered ID", buf, &extlist);
      return extlist;
    default:
      return extlist;
  }
}
