int __cdecl ASN1_item_ex_d2i(
        struct ASN1_VALUE_st **pval,
        unsigned __int8 **in,
        unsigned __int8 *len,
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
  int v17; // esi
  unsigned __int8 **v18; // ebp
  int utype; // eax
  int v20; // eax
  unsigned __int8 *v21; // eax
  unsigned __int8 v22; // dl
  int v23; // eax
  const ASN1_TEMPLATE_st *v24; // esi
  int v25; // ebp
  bool v26; // zf
  bool v27; // cc
  struct ASN1_VALUE_st **v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // ecx
  int v32; // eax
  unsigned __int8 *v33; // ebp
  const ASN1_TEMPLATE_st *v34; // ecx
  const ASN1_TEMPLATE_st *v35; // eax
  const ASN1_TEMPLATE_st *v36; // esi
  int v37; // edx
  char v38; // cl
  int v39; // eax
  const ASN1_TEMPLATE_st *v40; // eax
  const ASN1_TEMPLATE_st *v41; // esi
  struct ASN1_VALUE_st **field_ptr; // eax
  struct ASN1_VALUE_st *v43; // eax
  char cst; // [esp+13h] [ebp-1Dh] BYREF
  unsigned __int8 *v45; // [esp+14h] [ebp-1Ch] BYREF
  const ASN1_TEMPLATE_st *tt; // [esp+18h] [ebp-18h]
  unsigned __int8 *v47; // [esp+1Ch] [ebp-14h]
  struct ASN1_VALUE_st *v48; // [esp+20h] [ebp-10h]
  const ASN1_TEMPLATE_st *v49; // [esp+24h] [ebp-Ch]
  struct ASN1_VALUE_st **pvala; // [esp+28h] [ebp-8h]
  unsigned __int8 *v51; // [esp+2Ch] [ebp-4h]

  v8 = pval;
  v9 = it;
  funcs = (struct ASN1_VALUE_st **)it->funcs;
  v11 = 0;
  v49 = 0;
  pvala = funcs;
  v45 = 0;
  v47 = 0;
  LOBYTE(it) = 0;
  if ( pval )
  {
    if ( funcs && funcs[4] )
    {
      v12 = funcs[4];
      v48 = v12;
    }
    else
    {
      v12 = 0;
      v48 = 0;
    }
    switch ( v9->itype )
    {
      case 0:
        templates = v9->templates;
        if ( !templates )
          return asn1_d2i_ex_primitive(pval, in, len, v9, aclass, opt, ctx);
        if ( tag == -1 && !(_BYTE)opt )
          return asn1_template_ex_d2i(len, templates, 0, pval, in, ctx);
        ERR_put_error(0xDu, 120, 170, ".\\crypto\\asn1\\tasn_dec.c", 192);
        goto err_47;
      case 1:
      case 6:
        v45 = *in;
        v30 = tag;
        pval = (struct ASN1_VALUE_st **)len;
        if ( tag == -1 )
        {
          v30 = 16;
          v31 = 0;
        }
        else
        {
          v31 = aclass;
        }
        v32 = asn1_check_tlen((int *)&len, 0, 0, (char *)&it, &cst, (ASN1_TLC_st **)&v45, len, v30, v31, opt, ctx);
        if ( !v32 )
        {
          ERR_put_error(0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 381);
          goto err_47;
        }
        if ( v32 == -1 )
          return -1;
        if ( funcs && ((_BYTE)funcs[1] & 4) != 0 )
        {
          v33 = (unsigned __int8 *)pval + *in - v45;
          LOBYTE(pval) = 1;
        }
        else
        {
          v33 = len;
          LOBYTE(pval) = (_BYTE)it;
        }
        if ( !cst )
        {
          ERR_put_error(0xDu, 120, 149, ".\\crypto\\asn1\\tasn_dec.c", 396);
          goto err_47;
        }
        if ( !*v8 && !ASN1_item_ex_new(v8, v9) )
        {
          ERR_put_error(0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 403);
          goto err_47;
        }
        if ( v48 && !((int (__cdecl *)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD))v48)(4, v8, v9, 0) )
          goto auxerr_0;
        v27 = v9->tcount <= 0;
        v34 = v9->templates;
        v47 = 0;
        tt = v34;
        if ( v27 )
          goto LABEL_87;
        while ( 1 )
        {
          v35 = asn1_do_adb(v8, tt, 1);
          v36 = v35;
          if ( !v35 )
            goto err_47;
          pvala = asn1_get_field_ptr(v8, v35);
          if ( !v33 )
            goto LABEL_87;
          v51 = v45;
          if ( asn1_check_eoc((int)v33) )
            break;
          if ( v47 == (unsigned __int8 *)(v9->tcount - 1) )
            v38 = 0;
          else
            v38 = v36->flags & 1;
          v39 = asn1_template_ex_d2i(v33, v36, v38, pvala, &v45, ctx);
          if ( !v39 )
          {
            v49 = v36;
            goto err_47;
          }
          if ( v39 == -1 )
            ASN1_template_free(pvala, v36);
          else
            v33 += v51 - v45;
          ++tt;
          v27 = (int)++v47 < v9->tcount;
          if ( !v27 )
          {
LABEL_87:
            if ( (_BYTE)it && !asn1_check_eoc((int)v33) )
            {
              ERR_put_error(0xDu, 120, 137, ".\\crypto\\asn1\\tasn_dec.c", 470);
              goto err_47;
            }
LABEL_93:
            if ( !(_BYTE)pval && v33 )
            {
              ERR_put_error(0xDu, 120, 148, ".\\crypto\\asn1\\tasn_dec.c", 477);
              goto err_47;
            }
            if ( (int)v47 < v9->tcount )
            {
              do
              {
                v40 = asn1_do_adb(v8, tt, 1);
                v41 = v40;
                if ( !v40 )
                  goto err_47;
                if ( (v40->flags & 1) == 0 )
                {
                  v49 = v40;
                  ERR_put_error(0xDu, 120, 121, ".\\crypto\\asn1\\tasn_dec.c", 501);
                  goto err_47;
                }
                field_ptr = asn1_get_field_ptr(v8, v40);
                ASN1_template_free(field_ptr, v41);
                ++tt;
                v27 = (int)++v47 < v9->tcount;
              }
              while ( v27 );
            }
            if ( asn1_enc_save(v8, *in, v45 - *in, v9) )
            {
              v43 = v48;
              *in = v45;
              if ( !v43
                || ((int (__cdecl *)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD))v43)(5, v8, v9, 0) )
              {
                return 1;
              }
            }
            goto auxerr_0;
          }
        }
        if ( !(_BYTE)it )
        {
          ERR_put_error(0xDu, 120, 159, ".\\crypto\\asn1\\tasn_dec.c", 428);
          goto err_47;
        }
        v33 += v37 - (_DWORD)v45;
        goto LABEL_93;
      case 2:
        if ( v12 && !((int (__cdecl *)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD))v12)(4, pval, v9, 0) )
          goto auxerr_0;
        if ( !*v8 && !ASN1_item_ex_new(v8, v9) )
        {
          ERR_put_error(0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 318);
          goto err_47;
        }
        v24 = v9->templates;
        v25 = 0;
        v26 = v9->tcount == 0;
        v27 = v9->tcount > 0;
        v45 = *in;
        if ( !v27 )
          goto LABEL_48;
        break;
      case 3:
        v17 = tag;
        v18 = in;
        if ( !(_BYTE)opt )
          goto LABEL_31;
        v45 = *in;
        if ( tag == -1 )
          utype = v9->utype;
        else
          utype = tag;
        v20 = asn1_check_tlen(0, 0, 0, 0, 0, (ASN1_TLC_st **)&v45, len, utype, aclass, 1, ctx);
        if ( !v20 )
        {
          ERR_put_error(0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 262);
          goto err_47;
        }
        if ( v20 == -1 )
          return -1;
        v11 = v45;
LABEL_31:
        if ( v17 == -1 )
          goto LABEL_35;
        v21 = *v18;
        v22 = **v18;
        v47 = *v18;
        LOBYTE(it) = v22;
        if ( !v11 )
        {
          ERR_put_error(0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 291);
          goto err_47;
        }
        *v21 = LOBYTE(v9->utype) | *v11 & 0x20;
LABEL_35:
        v23 = ((int (__cdecl *)(struct ASN1_VALUE_st **, unsigned __int8 **, unsigned __int8 *))pvala[2])(v8, v18, len);
        if ( v17 != -1 )
          *v47 = (unsigned __int8)it;
        if ( v23 )
          return 1;
        ERR_put_error(0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 306);
        goto err_47;
      case 4:
        return ((int (__cdecl *)(struct ASN1_VALUE_st **, unsigned __int8 **, unsigned __int8 *, const ASN1_ITEM_st *, int, int, int, ASN1_TLC_st *))funcs[4])(
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
        v45 = *in;
        if ( !asn1_check_tlen(0, (int *)&pval, (unsigned __int8 *)&it, 0, 0, (ASN1_TLC_st **)&v45, len, -1, 0, 1, ctx) )
        {
          ERR_put_error(0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 210);
          goto err_47;
        }
        if ( (_BYTE)it )
        {
          if ( (_BYTE)opt )
            return -1;
          ERR_put_error(0xDu, 120, 139, ".\\crypto\\asn1\\tasn_dec.c", 220);
        }
        else
        {
          if ( (ASN1_tag2bit((unsigned int)pval) & v9->utype) != 0 )
            return asn1_d2i_ex_primitive(v8, v16, len, v9, 0, 0, v15);
          if ( (_BYTE)opt )
            return -1;
          ERR_put_error(0xDu, 120, 140, ".\\crypto\\asn1\\tasn_dec.c", 230);
        }
        goto err_47;
      default:
        return 0;
    }
    while ( 1 )
    {
      v28 = asn1_get_field_ptr(v8, v24);
      v29 = asn1_template_ex_d2i(len, v24, 1, v28, &v45, ctx);
      if ( v29 != -1 )
        break;
      ++v25;
      ++v24;
      if ( v25 >= v9->tcount )
        goto LABEL_47;
    }
    if ( v29 <= 0 )
    {
      v49 = v24;
      ERR_put_error(0xDu, 120, 58, ".\\crypto\\asn1\\tasn_dec.c", 339);
      goto err_47;
    }
LABEL_47:
    v26 = v25 == v9->tcount;
LABEL_48:
    if ( v26 )
    {
      if ( (_BYTE)opt )
      {
        ASN1_item_ex_free(v8, v9);
        return -1;
      }
      ERR_put_error(0xDu, 120, 143, ".\\crypto\\asn1\\tasn_dec.c", 354);
    }
    else
    {
      asn1_set_choice_selector(v8, v25, v9);
      *in = v45;
      if ( !v48 || ((int (__cdecl *)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD))v48)(5, v8, v9, 0) )
        return 1;
auxerr_0:
      ERR_put_error(0xDu, 120, 100, ".\\crypto\\asn1\\tasn_dec.c", 517);
    }
err_47:
    ASN1_item_ex_free(v8, v9);
    if ( v49 )
    {
      ERR_add_error_data(4, "Field=", v49->field_name, ", Type=", v9->sname);
      return 0;
    }
    ERR_add_error_data(2, "Type=", v9->sname);
  }
  return 0;
}
