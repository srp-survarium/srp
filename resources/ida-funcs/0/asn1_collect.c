int __cdecl asn1_collect(buf_mem_st *buf, unsigned __int8 **in, int len, char inf, int tag, int aclass, int depth)
{
  buf_mem_st *v7; // ebx
  unsigned __int8 *v8; // eax
  int v10; // ebp
  unsigned __int8 *v11; // esi
  char object; // al
  unsigned int v13; // esi
  char v14; // dl
  bool v15; // zf
  const unsigned __int8 *length; // edi
  unsigned __int8 *ina; // [esp+8h] [ebp-18h] BYREF
  unsigned int v18; // [esp+Ch] [ebp-14h] BYREF
  int v19; // [esp+10h] [ebp-10h] BYREF
  int v20; // [esp+14h] [ebp-Ch] BYREF
  char infa[4]; // [esp+18h] [ebp-8h]
  unsigned __int8 *v22; // [esp+1Ch] [ebp-4h]

  inf &= 1u;
  v7 = buf;
  v8 = *in;
  ina = *in;
  if ( buf || inf )
  {
    v10 = len;
    if ( len <= 0 )
    {
LABEL_25:
      if ( inf )
      {
        ERR_put_error((int)v7, 0xDu, 106, 137, ".\\crypto\\asn1\\tasn_dec.c", 1213);
        return 0;
      }
      else
      {
LABEL_35:
        *in = v8;
        return 1;
      }
    }
    else
    {
      while ( 1 )
      {
        v22 = v8;
        if ( v10 >= 2 && !*v8 && !v8[1] )
          break;
        buf = (buf_mem_st *)v8;
        v11 = v8;
        object = ASN1_get_object(
                   (const unsigned __int8 **)v7,
                   (const unsigned __int8 **)&buf,
                   &v18,
                   &v19,
                   &v20,
                   (const unsigned __int8 *)v10);
        if ( object < 0 )
        {
          ERR_put_error((int)v7, 0xDu, 104, 102, ".\\crypto\\asn1\\tasn_dec.c", 1306);
LABEL_31:
          ERR_put_error((int)v7, 0xDu, 106, 58, ".\\crypto\\asn1\\tasn_dec.c", 1190);
          return 0;
        }
        if ( tag >= 0 && (tag != v19 || aclass != v20) )
        {
          ERR_put_error((int)v7, 0xDu, 104, 168, ".\\crypto\\asn1\\tasn_dec.c", 1319);
          goto LABEL_31;
        }
        if ( (object & 1) != 0 )
        {
          v13 = v10 + v11 - (unsigned __int8 *)buf;
          v18 = v13;
        }
        else
        {
          v13 = v18;
        }
        v14 = object & 1;
        v15 = (object & 0x20) == 0;
        v8 = (unsigned __int8 *)buf;
        infa[0] = v14;
        ina = (unsigned __int8 *)buf;
        if ( v15 )
        {
          if ( v13 )
          {
            if ( v7 )
            {
              length = (const unsigned __int8 *)v7->length;
              if ( !BUF_MEM_grow_clean(v7, v13 + v7->length) )
              {
                ERR_put_error((int)v7, 0xDu, 140, 65, ".\\crypto\\asn1\\tasn_dec.c", 1228);
                return 0;
              }
              memcpy((int)&length[(unsigned int)v7->data], (const __m128i *)ina, v13);
              v8 = ina;
            }
            v8 += v13;
            ina = v8;
          }
        }
        else
        {
          if ( depth >= 5 )
          {
            ERR_put_error((int)v7, 0xDu, 106, 197, ".\\crypto\\asn1\\tasn_dec.c", 1200);
            return 0;
          }
          if ( !asn1_collect(v7, &ina, v13, infa[0], tag, aclass, depth + 1) )
            return 0;
          v8 = ina;
        }
        v10 += v22 - v8;
        if ( v10 <= 0 )
          goto LABEL_25;
      }
      v8 += 2;
      ina = v8;
      if ( inf )
        goto LABEL_35;
      ERR_put_error((int)v7, 0xDu, 106, 159, ".\\crypto\\asn1\\tasn_dec.c", 1180);
      return 0;
    }
  }
  else
  {
    *in = &v8[len];
    return 1;
  }
}
