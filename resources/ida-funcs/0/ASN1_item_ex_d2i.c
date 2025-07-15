int __cdecl ASN1_item_ex_d2i(
        struct ASN1_VALUE_st **pval,
        unsigned __int8 **in,
        const unsigned __int8 **len,
        const ASN1_ITEM_st *it,
        int tag,
        int aclass,
        int opt,
        ASN1_TLC_st *ctx)
{
  struct ASN1_VALUE_st **v8; // ebx
  const ASN1_ITEM_st *v9; // edi
  struct ASN1_VALUE_st **funcs; // ebp
  unsigned __int8 *v11; // ecx
  struct ASN1_VALUE_st *v12; // edx
  const ASN1_TEMPLATE_st *templates; // eax
  ASN1_TLC_st *v15; // esi
  unsigned __int8 **v16; // ebp
  int v17; // ecx
  int v18; // esi
  unsigned __int8 **v19; // ebp
  int utype; // eax
  int v21; // eax
  unsigned __int8 *v22; // eax
  unsigned __int8 v23; // dl
  int v24; // eax
  const ASN1_TEMPLATE_st *v25; // esi
  int v26; // ebp
  bool v27; // zf
  bool v28; // cc
  struct ASN1_VALUE_st **v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  unsigned __int8 *v34; // ebp
  const ASN1_TEMPLATE_st *v35; // ecx
  const ASN1_TEMPLATE_st *v36; // eax
  const ASN1_TEMPLATE_st *v37; // esi
  int v38; // edx
  char v39; // cl
  int v40; // eax
  const ASN1_TEMPLATE_st *v41; // eax
  const ASN1_TEMPLATE_st *v42; // esi
  const stack_st **v43; // eax
  struct ASN1_VALUE_st *v44; // eax
  char v45; // [esp+13h] [ebp-1Dh] BYREF
  unsigned __int8 *v46; // [esp+14h] [ebp-1Ch] BYREF
  const ASN1_TEMPLATE_st *tt; // [esp+18h] [ebp-18h]
  unsigned __int8 *v48; // [esp+1Ch] [ebp-14h]
  struct ASN1_VALUE_st *v49; // [esp+20h] [ebp-10h]
  const ASN1_TEMPLATE_st *v50; // [esp+24h] [ebp-Ch]
  struct ASN1_VALUE_st **field_ptr; // [esp+28h] [ebp-8h]
  unsigned __int8 *v52; // [esp+2Ch] [ebp-4h]

  v8 = pval;
  v9 = it;
  funcs = (struct ASN1_VALUE_st **)it->funcs;
  v11 = 0;
  v50 = 0;
  field_ptr = funcs;
  v46 = 0;
  v48 = 0;
  LOBYTE(it) = 0;
  if ( pval )
  {
    if ( funcs && funcs[4] )
    {
      v12 = funcs[4];
      v49 = v12;
    }
    else
    {
      v12 = 0;
      v49 = 0;
    }
    switch ( v9->itype )
    {
      case 0:
        templates = v9->templates;
        if ( !templates )
          return asn1_d2i_ex_primitive(tag, (int)pval, (asn1_type_st **)pval, in, len, v9, aclass, opt, ctx);
        if ( tag == -1 && !(_BYTE)opt )
          return asn1_template_ex_d2i((unsigned __int8 *)len, templates, 0, pval, in, ctx);
        ERR_put_error((int)pval, 0xDu, 120, 170, ".\\crypto\\asn1\\tasn_dec.c", 192);
        goto err_49;
      case 1:
      case 6:
        v46 = *in;
        v31 = tag;
        pval = (struct ASN1_VALUE_st **)len;
        if ( tag == -1 )
        {
          v31 = 16;
          v32 = 0;
        }
        else
        {
          v32 = aclass;
        }
        v33 = asn1_check_tlen(
                (const unsigned __int8 **)&len,
                0,
                0,
                (char *)&it,
                &v45,
                (ASN1_TLC_st **)&v46,
                len,
                v31,
                v32,
                opt,
                ctx);
        if ( !v33 )
        {
          ERR_put_error((int)v8, 0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 381);
          goto err_49;
        }
        if ( v33 == -1 )
          return -1;
        if ( funcs && ((_BYTE)funcs[1] & 4) != 0 )
        {
          v34 = (unsigned __int8 *)pval + *in - v46;
          LOBYTE(pval) = 1;
        }
        else
        {
          v34 = (unsigned __int8 *)len;
          LOBYTE(pval) = (_BYTE)it;
        }
        if ( !v45 )
        {
          ERR_put_error((int)v8, 0xDu, 120, 149, ".\\crypto\\asn1\\tasn_dec.c", 396);
          goto err_49;
        }
        if ( !*v8 && !ASN1_item_ex_new(v8, v9) )
        {
          ERR_put_error((int)v8, 0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 403);
          goto err_49;
        }
        if ( v49 && !((int (__cdecl *)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD))v49)(4, v8, v9, 0) )
          goto auxerr_0;
        v28 = v9->tcount <= 0;
        v35 = v9->templates;
        v48 = 0;
        tt = v35;
        if ( v28 )
          goto LABEL_87;
        while ( 1 )
        {
          v36 = asn1_do_adb(v8, tt, 1);
          v37 = v36;
          if ( !v36 )
            goto err_49;
          field_ptr = asn1_get_field_ptr(v8, v36);
          if ( !v34 )
            goto LABEL_87;
          v52 = v46;
          if ( asn1_check_eoc((int)v34) )
            break;
          if ( v48 == (unsigned __int8 *)(v9->tcount - 1) )
            v39 = 0;
          else
            v39 = v37->flags & 1;
          v40 = asn1_template_ex_d2i(v34, v37, v39, field_ptr, &v46, ctx);
          if ( !v40 )
          {
            v50 = v37;
            goto err_49;
          }
          if ( v40 == -1 )
            ASN1_template_free((const stack_st **)field_ptr, v37);
          else
            v34 += v52 - v46;
          ++tt;
          v28 = (int)++v48 < v9->tcount;
          if ( !v28 )
          {
LABEL_87:
            if ( (_BYTE)it && !asn1_check_eoc((int)v34) )
            {
              ERR_put_error((int)v8, 0xDu, 120, 137, ".\\crypto\\asn1\\tasn_dec.c", 470);
              goto err_49;
            }
LABEL_93:
            if ( !(_BYTE)pval && v34 )
            {
              ERR_put_error((int)v8, 0xDu, 120, 148, ".\\crypto\\asn1\\tasn_dec.c", 477);
              goto err_49;
            }
            if ( (int)v48 < v9->tcount )
            {
              do
              {
                v41 = asn1_do_adb(v8, tt, 1);
                v42 = v41;
                if ( !v41 )
                  goto err_49;
                if ( (v41->flags & 1) == 0 )
                {
                  v50 = v41;
                  ERR_put_error((int)v8, 0xDu, 120, 121, ".\\crypto\\asn1\\tasn_dec.c", 501);
                  goto err_49;
                }
                v43 = (const stack_st **)asn1_get_field_ptr(v8, v41);
                ASN1_template_free(v43, v42);
                ++tt;
                v28 = (int)++v48 < v9->tcount;
              }
              while ( v28 );
            }
            if ( asn1_enc_save(v8, *in, v46 - *in, v9) )
            {
              v44 = v49;
              *in = v46;
              if ( !v44
                || ((int (__cdecl *)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD))v44)(5, v8, v9, 0) )
              {
                return 1;
              }
            }
            goto auxerr_0;
          }
        }
        if ( !(_BYTE)it )
        {
          ERR_put_error((int)v8, 0xDu, 120, 159, ".\\crypto\\asn1\\tasn_dec.c", 428);
          goto err_49;
        }
        v34 += v38 - (_DWORD)v46;
        goto LABEL_93;
      case 2:
        if ( v12 && !((int (__cdecl *)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD))v12)(4, pval, v9, 0) )
          goto auxerr_0;
        if ( !*v8 && !ASN1_item_ex_new(v8, v9) )
        {
          ERR_put_error((int)v8, 0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 318);
          goto err_49;
        }
        v25 = v9->templates;
        v26 = 0;
        v27 = v9->tcount == 0;
        v28 = v9->tcount > 0;
        v46 = *in;
        if ( !v28 )
          goto LABEL_48;
        break;
      case 3:
        v18 = tag;
        v19 = in;
        if ( !(_BYTE)opt )
          goto LABEL_31;
        v46 = *in;
        if ( tag == -1 )
          utype = v9->utype;
        else
          utype = tag;
        v21 = asn1_check_tlen(0, 0, 0, 0, 0, (ASN1_TLC_st **)&v46, len, utype, aclass, 1, ctx);
        if ( !v21 )
        {
          ERR_put_error((int)v8, 0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 262);
          goto err_49;
        }
        if ( v21 == -1 )
          return -1;
        v11 = v46;
LABEL_31:
        if ( v18 == -1 )
          goto LABEL_35;
        v22 = *v19;
        v23 = **v19;
        v48 = *v19;
        LOBYTE(it) = v23;
        if ( !v11 )
        {
          ERR_put_error((int)v8, 0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 291);
          goto err_49;
        }
        *v22 = LOBYTE(v9->utype) | *v11 & 0x20;
LABEL_35:
        v24 = ((int (__cdecl *)(struct ASN1_VALUE_st **, unsigned __int8 **, const unsigned __int8 **))field_ptr[2])(
                v8,
                v19,
                len);
        if ( v18 != -1 )
          *v48 = (unsigned __int8)it;
        if ( v24 )
          return 1;
        ERR_put_error((int)v8, 0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 306);
        goto err_49;
      case 4:
        return ((int (__cdecl *)(struct ASN1_VALUE_st **, unsigned __int8 **, const unsigned __int8 **, const ASN1_ITEM_st *, int, int, int, ASN1_TLC_st *))funcs[4])(
                 pval,
                 in,
                 len,
                 v9,
                 tag,
                 aclass,
                 opt,
                 ctx);
      case 5:
        v15 = ctx;
        v16 = in;
        v46 = *in;
        if ( !asn1_check_tlen(0, (int *)&pval, (unsigned __int8 *)&it, 0, 0, (ASN1_TLC_st **)&v46, len, -1, 0, 1, ctx) )
        {
          ERR_put_error((int)v8, 0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 210);
          goto err_49;
        }
        if ( (_BYTE)it )
        {
          if ( (_BYTE)opt )
            return -1;
          ERR_put_error((int)v8, 0xDu, 120, 139, ".\\crypto\\asn1\\tasn_dec.c", 220);
        }
        else
        {
          if ( (ASN1_tag2bit((unsigned int)pval) & v9->utype) != 0 )
            return asn1_d2i_ex_primitive(v17, (int)v8, (asn1_type_st **)v8, v16, len, v9, 0, 0, v15);
          if ( (_BYTE)opt )
            return -1;
          ERR_put_error((int)v8, 0xDu, 120, 140, ".\\crypto\\asn1\\tasn_dec.c", 230);
        }
        goto err_49;
      default:
        return 0;
    }
    while ( 1 )
    {
      v29 = asn1_get_field_ptr(v8, v25);
      v30 = asn1_template_ex_d2i((unsigned __int8 *)len, v25, 1, v29, &v46, ctx);
      if ( v30 != -1 )
        break;
      ++v26;
      ++v25;
      if ( v26 >= v9->tcount )
        goto LABEL_47;
    }
    if ( v30 <= 0 )
    {
      v50 = v25;
      ERR_put_error((int)v8, 0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 339);
      goto err_49;
    }
LABEL_47:
    v27 = v26 == v9->tcount;
LABEL_48:
    if ( v27 )
    {
      if ( (_BYTE)opt )
      {
        ASN1_item_ex_free((stack_st **)v8, v9);
        return -1;
      }
      ERR_put_error((int)v8, 0xDu, 120, 143, ".\\crypto\\asn1\\tasn_dec.c", 354);
    }
    else
    {
      asn1_set_choice_selector(v8, v26, v9);
      *in = v46;
      if ( !v49 || ((int (__cdecl *)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD))v49)(5, v8, v9, 0) )
        return 1;
auxerr_0:
      ERR_put_error((int)v8, 0xDu, 120, 100, ".\\crypto\\asn1\\tasn_dec.c", 517);
    }
err_49:
    ASN1_item_ex_free((stack_st **)v8, v9);
    if ( v50 )
    {
      ERR_add_error_data(4, "Field=", v50->field_name, ", Type=", v9->sname);
      return 0;
    }
    ERR_add_error_data(2, "Type=", v9->sname);
  }
  return 0;
}
