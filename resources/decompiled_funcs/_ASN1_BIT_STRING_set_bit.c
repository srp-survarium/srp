int __cdecl ASN1_BIT_STRING_set_bit(asn1_string_st *a, int n, int value)
{
  int v3; // eax
  int v4; // edi
  char v5; // bl
  signed int length; // edx
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // ebp
  unsigned __int8 *data; // ecx
  int v12; // eax
  char v; // [esp+18h] [ebp+8h]

  v3 = 1 << (7 - (n & 7));
  v4 = n / 8;
  v = v3;
  v5 = ~(_BYTE)v3;
  if ( !value )
  {
    v = 0;
    LOBYTE(v3) = 0;
  }
  if ( !a )
    return 0;
  length = a->length;
  a->flags &= 0xFFFFFFF0;
  if ( length >= v4 + 1 && a->data )
  {
LABEL_16:
    a->data[v4] = v3 | a->data[v4] & v5;
    if ( a->length > 0 )
    {
      data = a->data;
      do
      {
        if ( data[a->length - 1] )
          break;
        v12 = a->length - 1;
        a->length = v12;
      }
      while ( v12 > 0 );
    }
    return 1;
  }
  if ( value )
  {
    v7 = a->data;
    if ( v7 )
      v8 = CRYPTO_realloc_clean(v7, length, v4 + 1, ".\\crypto\\asn1\\a_bitstr.c", 199);
    else
      v8 = (unsigned __int8 *)CRYPTO_malloc(v4 + 1, ".\\crypto\\asn1\\a_bitstr.c", 195);
    v9 = v8;
    if ( !v8 )
    {
      ERR_put_error(0xDu, 183, 65, ".\\crypto\\asn1\\a_bitstr.c", 202);
      return 0;
    }
    if ( v4 - a->length + 1 > 0 )
      memset((int)&v8[a->length], 0, v4 - a->length + 1);
    a->length = v4 + 1;
    LOBYTE(v3) = v;
    a->data = v9;
    goto LABEL_16;
  }
  return 1;
}
