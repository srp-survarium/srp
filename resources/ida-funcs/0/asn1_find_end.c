int __cdecl asn1_find_end(unsigned __int8 **in, char inf)
{
  int len; // ecx
  unsigned __int8 *v3; // esi
  int v4; // edi
  int v6; // ebp
  unsigned __int8 *v7; // ebx
  char object; // al
  unsigned __int8 *pp; // [esp+8h] [ebp-10h] BYREF
  int plength; // [esp+Ch] [ebp-Ch] BYREF
  int pclass; // [esp+10h] [ebp-8h] BYREF
  int ptag; // [esp+14h] [ebp-4h] BYREF

  v3 = *in;
  v4 = len;
  if ( inf )
  {
    v6 = 1;
    if ( len <= 0 )
    {
LABEL_18:
      ERR_put_error(0xDu, 190, 137, ".\\crypto\\asn1\\tasn_dec.c", 1132);
      return 0;
    }
    else
    {
      do
      {
        if ( v4 < 2 || *v3 || v3[1] )
        {
          v7 = v3;
          pp = v3;
          object = ASN1_get_object((const unsigned __int8 **)&pp, &plength, &ptag, &pclass, (unsigned __int8 *)v4);
          if ( object < 0 )
          {
            ERR_put_error(0xDu, 104, 102, ".\\crypto\\asn1\\tasn_dec.c", 1306);
            ERR_put_error(0xDu, 190, 58, ".\\crypto\\asn1\\tasn_dec.c", 1121);
            return 0;
          }
          if ( (object & 1) != 0 )
            plength = v4 + v3 - pp;
          v3 = pp;
          if ( (object & 1) != 0 )
            ++v6;
          else
            v3 = &pp[plength];
          v4 += v7 - v3;
        }
        else
        {
          v3 += 2;
          if ( !--v6 )
            goto LABEL_20;
          v4 -= 2;
        }
      }
      while ( v4 > 0 );
      if ( v6 )
        goto LABEL_18;
LABEL_20:
      *in = v3;
      return 1;
    }
  }
  else
  {
    *in = &v3[len];
    return 1;
  }
}
