unsigned int __cdecl asn1_ex_i2c(
        struct ASN1_VALUE_st **pval,
        unsigned __int8 *cout,
        int *putype,
        const ASN1_ITEM_st *it)
{
  const ASN1_ITEM_st *v4; // edx
  _DWORD *funcs; // eax
  int (__cdecl *v6)(struct ASN1_VALUE_st **, unsigned __int8 *, int *, const ASN1_ITEM_st *); // eax
  asn1_string_st **p_type; // ecx
  int v9; // eax
  asn1_string_st *v10; // ecx
  asn1_string_st *v11; // ecx
  unsigned __int8 *p_it; // eax
  unsigned int flags; // esi
  int v14; // eax
  asn1_string_st *v15; // ecx

  v4 = it;
  funcs = it->funcs;
  if ( funcs )
  {
    v6 = (int (__cdecl *)(struct ASN1_VALUE_st **, unsigned __int8 *, int *, const ASN1_ITEM_st *))funcs[6];
    if ( v6 )
      return v6(pval, cout, putype, it);
  }
  p_type = (asn1_string_st **)pval;
  if ( (it->itype || it->utype != 1) && !*pval )
    return -1;
  if ( it->itype == 5 )
  {
    v9 = *((_DWORD *)*pval + 1);
    *putype = v9;
  }
  else if ( it->utype == -4 )
  {
    v10 = (asn1_string_st *)*pval;
    v9 = *(_DWORD *)*pval;
    *putype = v9;
    p_type = (asn1_string_st **)&v10->type;
  }
  else
  {
    v9 = *putype;
  }
  if ( v9 <= 10 )
  {
    if ( v9 != 10 )
    {
      switch ( v9 )
      {
        case 1:
          if ( *p_type == (asn1_string_st *)-1 )
            return -1;
          if ( v4->utype == -4 )
            goto LABEL_24;
          if ( *p_type )
          {
            if ( v4->size > 0 )
              return -1;
          }
          else if ( !v4->size )
          {
            return -1;
          }
LABEL_24:
          LOBYTE(it) = (unsigned __int8)*p_type;
          p_it = (unsigned __int8 *)&it;
          flags = 1;
          break;
        case 2:
          return i2c_ASN1_INTEGER(*p_type, cout != 0 ? &cout : 0);
        case 3:
          return i2c_ASN1_BIT_STRING(*p_type, cout != 0 ? &cout : 0);
        case 5:
          p_it = 0;
          flags = 0;
          goto LABEL_34;
        case 6:
          v11 = *p_type;
          p_it = (unsigned __int8 *)v11[1].length;
          flags = v11->flags;
          goto LABEL_34;
        default:
          goto LABEL_28;
      }
      goto LABEL_34;
    }
    return i2c_ASN1_INTEGER(*p_type, cout != 0 ? &cout : 0);
  }
  v14 = v9 - 258;
  if ( !v14 || v14 == 8 )
    return i2c_ASN1_INTEGER(*p_type, cout != 0 ? &cout : 0);
LABEL_28:
  v15 = *p_type;
  if ( v4->size != 2048 || (v15->flags & 0x10) == 0 )
  {
    p_it = v15->data;
    flags = v15->length;
LABEL_34:
    if ( cout )
    {
      if ( flags )
        memcpy(cout, p_it, flags);
    }
    return flags;
  }
  if ( cout )
  {
    v15->data = cout;
    v15->length = 0;
  }
  return -2;
}
