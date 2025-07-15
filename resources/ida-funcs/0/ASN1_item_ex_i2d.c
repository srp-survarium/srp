unsigned __int8 *__cdecl ASN1_item_ex_i2d(
        struct ASN1_VALUE_st **pval,
        unsigned __int8 **out,
        const ASN1_ITEM_st *it,
        int tag,
        int aclass)
{
  char itype; // al
  _DWORD *funcs; // ecx
  int (__cdecl *v8)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD); // ebp
  unsigned __int8 *result; // eax
  int (__cdecl *v10)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD); // edx
  const ASN1_TEMPLATE_st *templates; // eax
  int choice_selector; // eax
  const ASN1_TEMPLATE_st *v13; // edi
  struct ASN1_VALUE_st **field_ptr; // eax
  unsigned __int8 **v15; // edi
  int v16; // eax
  int v17; // ebp
  const ASN1_TEMPLATE_st *v18; // eax
  const ASN1_TEMPLATE_st *v19; // edi
  struct ASN1_VALUE_st **v20; // eax
  int v21; // eax
  int v22; // ebp
  const ASN1_TEMPLATE_st *v23; // eax
  const ASN1_TEMPLATE_st *v24; // edi
  struct ASN1_VALUE_st **v25; // eax
  int len; // [esp+Ch] [ebp-10h] BYREF
  int constructed; // [esp+10h] [ebp-Ch]
  int (__cdecl *v28)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD); // [esp+14h] [ebp-8h]
  unsigned __int8 *v29; // [esp+18h] [ebp-4h]
  const ASN1_TEMPLATE_st *ita; // [esp+28h] [ebp+Ch]
  const ASN1_TEMPLATE_st *itb; // [esp+28h] [ebp+Ch]

  itype = it->itype;
  funcs = it->funcs;
  v8 = 0;
  v29 = 0;
  constructed = 1;
  v28 = 0;
  if ( itype && !*pval )
    return 0;
  if ( funcs )
  {
    v10 = (int (__cdecl *)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD))funcs[4];
    if ( v10 )
    {
      v28 = (int (__cdecl *)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD))funcs[4];
      v8 = v10;
    }
  }
  switch ( itype )
  {
    case 0:
      templates = it->templates;
      if ( templates )
        return (unsigned __int8 *)asn1_template_ex_i2d(pval, out, templates, tag, aclass);
      else
        return (unsigned __int8 *)asn1_i2d_ex_primitive(it, pval, out, tag, aclass);
    case 1:
      goto $LN44_2;
    case 2:
      if ( v8 && !v8(6, pval, it, 0) )
        return 0;
      choice_selector = asn1_get_choice_selector(pval, it);
      if ( choice_selector >= 0 && choice_selector < it->tcount )
      {
        v13 = &it->templates[choice_selector];
        field_ptr = asn1_get_field_ptr(pval, v13);
        return (unsigned __int8 *)asn1_template_ex_i2d(field_ptr, out, v13, -1, aclass);
      }
      if ( v8 )
        v8(7, pval, it, 0);
      return 0;
    case 3:
      if ( out )
        v29 = *out;
      result = (unsigned __int8 *)((int (__cdecl *)(_DWORD, unsigned __int8 **))funcs[3])(*pval, out);
      if ( out && tag != -1 )
        *v29 = tag | aclass | *v29 & 0x20;
      return result;
    case 4:
      return (unsigned __int8 *)((int (__cdecl *)(struct ASN1_VALUE_st **, unsigned __int8 **, const ASN1_ITEM_st *, int, int))funcs[5])(
                                  pval,
                                  out,
                                  it,
                                  tag,
                                  aclass);
    case 5:
      return (unsigned __int8 *)asn1_i2d_ex_primitive(it, pval, out, -1, aclass);
    case 6:
      if ( (aclass & 0x800) != 0 )
        constructed = 2;
$LN44_2:
      v15 = out;
      v16 = asn1_enc_restore(&len, out, pval, it);
      if ( v16 < 0 )
        return 0;
      if ( v16 > 0 )
        return (unsigned __int8 *)len;
      len = 0;
      if ( tag == -1 )
      {
        aclass &= 0xFFFFFF3F;
        tag = 16;
      }
      if ( v8 && !v8(6, pval, it, 0) )
        return 0;
      v17 = 0;
      ita = it->templates;
      if ( it->tcount > 0 )
      {
        do
        {
          v18 = asn1_do_adb(pval, ita, 1);
          v19 = v18;
          if ( !v18 )
            return 0;
          v20 = asn1_get_field_ptr(pval, v18);
          v21 = asn1_template_ex_i2d(v20, 0, v19, -1, aclass);
          len += v21;
          ++ita;
          ++v17;
        }
        while ( v17 < it->tcount );
        v15 = out;
      }
      result = (unsigned __int8 *)ASN1_object_size(constructed, len, tag);
      v29 = result;
      if ( v15 )
      {
        ASN1_put_object(v15, constructed, len, tag, aclass);
        v22 = 0;
        itb = it->templates;
        if ( it->tcount > 0 )
        {
          do
          {
            v23 = asn1_do_adb(pval, itb, 1);
            v24 = v23;
            if ( !v23 )
              return 0;
            v25 = asn1_get_field_ptr(pval, v23);
            asn1_template_ex_i2d(v25, out, v24, -1, aclass);
            ++itb;
            ++v22;
          }
          while ( v22 < it->tcount );
          v15 = out;
        }
        if ( constructed == 2 )
          ASN1_put_eoc(v15);
        if ( v28 && !v28(7, pval, it, 0) )
          return 0;
        return v29;
      }
      return result;
    default:
      return 0;
  }
}
