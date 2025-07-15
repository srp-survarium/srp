int __usercall asn1_find_end@<eax>(int a1@<ecx>, int a2@<ebx>, unsigned __int8 **in, char inf)
{
  unsigned __int8 *v4; // esi
  int v5; // edi
  int v7; // ebp
  unsigned __int8 *v8; // ebx
  char object; // al
  unsigned __int8 *v10; // [esp+8h] [ebp-10h] BYREF
  int v11; // [esp+Ch] [ebp-Ch] BYREF
  int v12; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h] BYREF

  v4 = *in;
  v5 = a1;
  if ( inf )
  {
    v7 = 1;
    if ( a1 <= 0 )
    {
LABEL_18:
      ERR_put_error(a2, 0xDu, 190, 137, ".\\crypto\\asn1\\tasn_dec.c", 1132);
      return 0;
    }
    else
    {
      do
      {
        if ( v5 < 2 || *v4 || v4[1] )
        {
          v8 = v4;
          v10 = v4;
          object = ASN1_get_object(
                     (const unsigned __int8 **)v4,
                     (const unsigned __int8 **)&v10,
                     (unsigned int *)&v11,
                     &v13,
                     &v12,
                     (const unsigned __int8 *)v5);
          if ( object < 0 )
          {
            ERR_put_error((int)v4, 0xDu, 104, 102, ".\\crypto\\asn1\\tasn_dec.c", 1306);
            ERR_put_error((int)v4, 0xDu, 190, 58, ".\\crypto\\asn1\\tasn_dec.c", 1121);
            return 0;
          }
          if ( (object & 1) != 0 )
            v11 = v5 + v4 - v10;
          v4 = v10;
          if ( (object & 1) != 0 )
            ++v7;
          else
            v4 = &v10[v11];
          a2 = v8 - v4;
          v5 += a2;
        }
        else
        {
          v4 += 2;
          if ( !--v7 )
            goto LABEL_20;
          v5 -= 2;
        }
      }
      while ( v5 > 0 );
      if ( v7 )
        goto LABEL_18;
LABEL_20:
      *in = v4;
      return 1;
    }
  }
  else
  {
    *in = &v4[a1];
    return 1;
  }
}
