int __usercall parse_tagging@<eax>(const char *vstart@<edx>, int vlen@<ecx>, int *pclass@<ebx>, int *ptag)
{
  signed int v6; // eax
  char *v7; // ecx
  int result; // eax
  char v9; // cl
  _BYTE v10[4]; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( !vstart )
    return 0;
  v6 = strtoul((unsigned int)pclass, vstart, &endptr, 0xAu);
  v7 = endptr;
  if ( endptr )
  {
    if ( *endptr && endptr > &vstart[vlen] )
      return 0;
  }
  if ( v6 < 0 )
  {
    ERR_put_error(0xDu, 182, 187, ".\\crypto\\asn1\\asn1_gen.c", 399);
    return 0;
  }
  *ptag = v6;
  if ( v7 && vstart - v7 + vlen )
  {
    v9 = *v7;
    switch ( v9 )
    {
      case 'A':
        *pclass = 64;
        result = 1;
        break;
      case 'C':
        goto $LN9_36;
      case 'P':
        *pclass = 192;
        result = 1;
        break;
      case 'U':
        *pclass = 0;
        result = 1;
        break;
      default:
        v10[0] = v9;
        v10[1] = 0;
        ERR_put_error(0xDu, 182, 186, ".\\crypto\\asn1\\asn1_gen.c", 432);
        ERR_add_error_data(2, "Char=", v10);
        result = 0;
        break;
    }
  }
  else
  {
$LN9_36:
    *pclass = 128;
    return 1;
  }
  return result;
}
