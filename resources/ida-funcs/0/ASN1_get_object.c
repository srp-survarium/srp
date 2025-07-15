int __usercall ASN1_get_object@<eax>(
        const unsigned __int8 **p_omax@<ebx>,
        const unsigned __int8 **pp,
        unsigned int *plength,
        int *ptag,
        int *pclass,
        const unsigned __int8 *omax)
{
  _BYTE *v6; // eax
  const unsigned __int8 *v7; // ebp
  int v8; // edx
  int v9; // ecx
  int v10; // edi
  const unsigned __int8 *v11; // eax
  const unsigned __int8 *v12; // esi
  char v13; // dl
  int i; // ecx
  int v15; // edx
  bool v16; // zf
  int result; // eax
  const unsigned __int8 *v18; // esi
  int v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+14h] [ebp-4h] BYREF

  v6 = *pp;
  v7 = omax;
  if ( !omax )
    goto err_26;
  v8 = *v6 & 0x20;
  v9 = *v6 & 0x1F;
  v10 = *v6 & 0xC0;
  v11 = v6 + 1;
  v19 = v8;
  v12 = omax - 1;
  if ( v9 == 31 )
  {
    if ( omax == (const unsigned __int8 *)1 )
    {
err_26:
      ERR_put_error((int)p_omax, 0xDu, 114, 123, ".\\crypto\\asn1\\asn1_lib.c", 150);
      return 128;
    }
    v13 = *v11;
    for ( i = 0; *(char *)v11 < 0; v13 = *v11 )
    {
      i = v13 & 0x7F | (i << 7);
      ++v11;
      if ( !--v12 || i > 0xFFFFFF )
        goto err_26;
    }
    v15 = (i << 7) | *v11++ & 0x7F;
    v9 = v15;
    v16 = --v12 == 0;
  }
  else
  {
    v16 = omax == (const unsigned __int8 *)1;
  }
  omax = v11;
  if ( v16 )
    goto err_26;
  *ptag = v9;
  *pclass = v10;
  p_omax = &omax;
  if ( !asn1_get_length(&omax, &v20, (int)v12, plength) )
    goto err_26;
  v18 = omax;
  if ( (int)*plength > (int)&v7[*pp - omax] )
  {
    ERR_put_error((int)pp, 0xDu, 114, 155, ".\\crypto\\asn1\\asn1_lib.c", 142);
    v19 |= 0x80u;
  }
  result = v19 | v20;
  *pp = v18;
  return result;
}
