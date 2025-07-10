int __cdecl ASN1_get_object(const unsigned __int8 **pp, int *plength, int *ptag, int *pclass, unsigned __int8 *omax)
{
  _BYTE *v5; // eax
  int v6; // ebp
  int v7; // edx
  int v8; // ecx
  int v9; // edi
  char *v10; // eax
  int v11; // esi
  char v12; // dl
  int i; // ecx
  int v14; // edx
  bool v15; // zf
  int result; // eax
  const unsigned __int8 *v17; // esi
  int v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h] BYREF

  v5 = *pp;
  v6 = (int)omax;
  if ( !omax )
    goto err_24;
  v7 = *v5 & 0x20;
  v8 = *v5 & 0x1F;
  v9 = *v5 & 0xC0;
  v10 = v5 + 1;
  v18 = v7;
  v11 = (int)(omax - 1);
  if ( v8 == 31 )
  {
    if ( omax == (unsigned __int8 *)1 )
    {
err_24:
      ERR_put_error(0xDu, 114, 123, ".\\crypto\\asn1\\asn1_lib.c", 150);
      return 128;
    }
    v12 = *v10;
    for ( i = 0; *v10 < 0; v12 = *v10 )
    {
      i = v12 & 0x7F | (i << 7);
      ++v10;
      if ( !--v11 || i > (int)&vostok::memory::s_CRT_arena[5574199] )
        goto err_24;
    }
    v14 = (i << 7) | *v10++ & 0x7F;
    v8 = v14;
    v15 = --v11 == 0;
  }
  else
  {
    v15 = omax == (unsigned __int8 *)1;
  }
  omax = (unsigned __int8 *)v10;
  if ( v15 )
    goto err_24;
  *ptag = v8;
  *pclass = v9;
  if ( !asn1_get_length((const unsigned __int8 **)&omax, &v19, v11, plength) )
    goto err_24;
  v17 = omax;
  if ( *plength > v6 + *pp - omax )
  {
    ERR_put_error(0xDu, 114, 155, ".\\crypto\\asn1\\asn1_lib.c", 142);
    v18 |= 0x80u;
  }
  result = v18 | v19;
  *pp = v17;
  return result;
}
