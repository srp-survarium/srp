int __cdecl ec_wNAF_mul(
        const ec_group_st *group,
        ec_point_st *r,
        const bignum_st *scalar,
        unsigned int num,
        const ec_point_st **points,
        const bignum_st **scalars,
        bignum_ctx *ctx)
{
  const env_md_st *v7; // ebx
  const ec_method_st *meth; // eax
  unsigned int v9; // esi
  int v11; // ecx
  const ec_point_st *v12; // esi
  const ec_point_st ***data; // eax
  const ec_point_st ***v14; // ebx
  unsigned int v15; // esi
  unsigned int v16; // eax
  int v17; // eax
  unsigned int v18; // eax
  int v19; // esi
  void *v20; // ebx
  unsigned __int8 *v21; // edx
  char *v22; // ecx
  char *v23; // edi
  int *v24; // esi
  unsigned int v25; // eax
  int v26; // eax
  const bignum_st *v27; // eax
  unsigned int *v28; // ebx
  char *v29; // eax
  unsigned int v30; // ebx
  const ec_point_st ***v31; // esi
  int v32; // edi
  void *v33; // ecx
  unsigned int v34; // eax
  _DWORD *v35; // edx
  _DWORD *v36; // ecx
  unsigned int v37; // eax
  const ec_point_st **v38; // edi
  unsigned int v39; // ebx
  int *v40; // esi
  int v41; // ebp
  unsigned int v42; // eax
  unsigned __int8 *v43; // eax
  int v44; // ecx
  ec_point_st **v45; // edi
  ec_point_st **v46; // eax
  unsigned int v47; // ebp
  _BYTE *v48; // esi
  int v49; // eax
  unsigned int v50; // ebx
  ec_point_st *v51; // eax
  unsigned int v52; // ebp
  ec_point_st ***v53; // esi
  char *v54; // edi
  char *v55; // ebx
  const ec_point_st *v56; // ecx
  int v57; // edi
  unsigned int v58; // ebx
  int v59; // esi
  _DWORD *v60; // edi
  int v61; // ebp
  char *v62; // eax
  char *v63; // eax
  int v64; // eax
  int v65; // esi
  int v66; // eax
  int v67; // esi
  int v68; // eax
  void *v69; // edi
  void *v70; // eax
  _DWORD *v71; // esi
  ec_point_st **v72; // edi
  ec_point_st *v73; // eax
  ec_point_st **i; // esi
  int v75; // [esp-8h] [ebp-70h]
  void *v76; // [esp+Ch] [ebp-5Ch]
  unsigned int ret_len; // [esp+10h] [ebp-58h] BYREF
  unsigned int v78; // [esp+14h] [ebp-54h]
  void *v79; // [esp+18h] [ebp-50h]
  void *v80; // [esp+1Ch] [ebp-4Ch]
  unsigned int v81; // [esp+20h] [ebp-48h]
  int v82; // [esp+24h] [ebp-44h]
  unsigned int v83; // [esp+28h] [ebp-40h]
  unsigned int numa; // [esp+2Ch] [ebp-3Ch]
  void *v85; // [esp+30h] [ebp-38h]
  unsigned __int8 *src; // [esp+34h] [ebp-34h]
  const ec_point_st ***v87; // [esp+38h] [ebp-30h]
  unsigned int v88; // [esp+3Ch] [ebp-2Ch]
  int v89; // [esp+40h] [ebp-28h]
  ec_point_st *ra; // [esp+44h] [ebp-24h]
  ec_point_st **pointsa; // [esp+48h] [ebp-20h]
  void *str; // [esp+4Ch] [ebp-1Ch]
  char *v93; // [esp+50h] [ebp-18h]
  int v94; // [esp+54h] [ebp-14h]
  const ec_point_st *v95; // [esp+58h] [ebp-10h]
  bignum_ctx *v96; // [esp+5Ch] [ebp-Ch]
  int v97; // [esp+60h] [ebp-8h]
  char *j; // [esp+64h] [ebp-4h]

  v7 = (const env_md_st *)group;
  meth = group->meth;
  v9 = 0;
  v96 = 0;
  v95 = 0;
  ra = 0;
  v88 = 0;
  v82 = 0;
  v94 = 0;
  v89 = 0;
  v85 = 0;
  v80 = 0;
  v79 = 0;
  v81 = 0;
  pointsa = 0;
  v76 = 0;
  v87 = 0;
  src = 0;
  v97 = 0;
  if ( meth != r->meth )
  {
    ERR_put_error(0x10u, 187, 101, ".\\crypto\\ec\\ec_mult.c", 374);
    return 0;
  }
  if ( !scalar && !num )
    return EC_POINT_set_to_infinity(group, r);
  v11 = 0;
  if ( !num )
  {
LABEL_10:
    if ( !ctx )
    {
      v96 = BN_CTX_new();
      ctx = v96;
      if ( !v96 )
        return v97;
    }
    if ( scalar )
    {
      v12 = (const ec_point_st *)EVP_CIPHER_block_size(v7);
      v95 = v12;
      if ( !v12 )
      {
        ERR_put_error(0x10u, 187, 113, ".\\crypto\\ec\\ec_mult.c", 404);
err_162:
        if ( v96 )
          BN_CTX_free(v96);
        if ( ra )
          EC_POINT_free(ra);
        if ( v85 )
          CRYPTO_free(v85);
        if ( v79 )
          CRYPTO_free(v79);
        v69 = v80;
        if ( v80 )
        {
          v70 = *(void **)v80;
          v71 = v80;
          if ( *(_DWORD *)v80 )
          {
            do
            {
              CRYPTO_free(v70);
              v70 = (void *)v71[1];
              ++v71;
            }
            while ( v70 );
          }
          CRYPTO_free(v69);
        }
        v72 = pointsa;
        if ( pointsa )
        {
          v73 = *pointsa;
          for ( i = pointsa; v73; ++i )
          {
            EC_POINT_clear_free(v73);
            v73 = i[1];
          }
          CRYPTO_free(v72);
        }
        if ( v76 )
          CRYPTO_free(v76);
        return v97;
      }
      data = (const ec_point_st ***)EC_EX_DATA_get_data(
                                      group->extra_data,
                                      (void *(__cdecl *)(void *))ec_pre_comp_dup,
                                      ec_pre_comp_free,
                                      ec_pre_comp_clear_free);
      v14 = data;
      v87 = data;
      if ( data && data[2] && !EC_POINT_cmp(group, v12, *data[4], ctx) )
      {
        v88 = (unsigned int)v14[1];
        v15 = BN_num_bits(scalar) / v88;
        v16 = (unsigned int)v14[2];
        v9 = v15 + 1;
        v82 = v9;
        if ( v9 > v16 )
        {
          v9 = v16;
          v82 = v16;
        }
        v17 = (1 << (*((_BYTE *)v14 + 12) - 1)) * v16;
        v94 = 1 << (*((_BYTE *)v14 + 12) - 1);
        if ( v14[5] != (const ec_point_st **)v17 )
        {
          ERR_put_error(0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 429);
          goto err_162;
        }
      }
      else
      {
        v9 = 1;
        v87 = 0;
        v82 = 1;
        src = (unsigned __int8 *)1;
      }
    }
    v18 = v9 + num;
    v19 = 4 * (v9 + num);
    v78 = v18;
    v20 = CRYPTO_malloc(v19, ".\\crypto\\ec\\ec_mult.c", 444);
    v85 = v20;
    v79 = CRYPTO_malloc(v19, ".\\crypto\\ec\\ec_mult.c", 445);
    v80 = CRYPTO_malloc(v19 + 4, ".\\crypto\\ec\\ec_mult.c", 446);
    v76 = CRYPTO_malloc(v19, ".\\crypto\\ec\\ec_mult.c", 447);
    if ( v20 && v79 && v80 && v76 )
    {
      v21 = src;
      *(_DWORD *)v80 = 0;
      numa = 0;
      ret_len = 0;
      v83 = (unsigned int)&v21[num];
      if ( &v21[num] )
      {
        v22 = (char *)((char *)scalars - (_BYTE *)v20);
        v23 = (char *)((_BYTE *)v80 - (_BYTE *)v20);
        v24 = (int *)v20;
        str = (void *)((char *)scalars - (_BYTE *)v20);
        v93 = (char *)((_BYTE *)v80 - (_BYTE *)v20);
        j = (char *)((_BYTE *)v79 - (_BYTE *)v20);
        while ( 1 )
        {
          v25 = ret_len >= num ? BN_num_bits(scalar) : BN_num_bits(*(const bignum_st **)((char *)v24 + (_DWORD)v22));
          if ( v25 < 0x7D0 )
          {
            if ( v25 < 0x320 )
            {
              if ( v25 < 0x12C )
                v26 = v25 < 0x46 ? 2 - (v25 < 0x14) : 3;
              else
                v26 = 4;
            }
            else
            {
              v26 = 5;
            }
          }
          else
          {
            v26 = 6;
          }
          *v24 = v26;
          *(int *)((char *)v24 + (_DWORD)v23 + 4) = 0;
          numa += 1 << (v26 - 1);
          v27 = ret_len >= num ? scalar : *(const bignum_st **)((char *)v24 + (_DWORD)str);
          v28 = (unsigned int *)((char *)v24 + (_DWORD)j);
          v29 = compute_wNAF(*v24, v27, (unsigned int *)((char *)v24 + (_DWORD)j));
          *(int *)((char *)v24 + (_DWORD)v93) = (int)v29;
          if ( !v29 )
            goto err_162;
          v30 = *v28;
          if ( v30 > v81 )
            v81 = v30;
          ++v24;
          if ( ++ret_len >= v83 )
          {
            v20 = v85;
            break;
          }
          v23 = v93;
          v22 = (char *)str;
        }
      }
      if ( v82 )
      {
        v31 = v87;
        if ( v87 )
        {
          ret_len = 0;
          if ( src )
          {
            ERR_put_error(0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 495);
            goto err_162;
          }
          v32 = (int)v87[3];
          *((_DWORD *)v20 + num) = v32;
          v33 = compute_wNAF(v32, scalar, &ret_len);
          str = v33;
          if ( !v33 )
            goto err_162;
          v34 = ret_len;
          if ( ret_len > v81 )
          {
            if ( ret_len < v88 * v82 )
            {
              v37 = (ret_len + v88 - 1) / v88;
              if ( v37 > (unsigned int)v31[2] )
              {
                ERR_put_error(0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 535);
                goto err_162;
              }
              v78 = num + v37;
            }
            v38 = v87[4];
            src = (unsigned __int8 *)v33;
            v39 = num;
            if ( num < v78 )
            {
              v40 = (int *)((char *)v79 + 4 * num);
              v41 = (_BYTE *)v80 - (_BYTE *)v79;
              j = (char *)((_BYTE *)v76 - (_BYTE *)v79);
              while ( 1 )
              {
                if ( v39 >= v78 - 1 )
                {
                  *v40 = ret_len;
                }
                else
                {
                  v42 = v88;
                  *v40 = v88;
                  if ( ret_len < v42 )
                  {
                    ERR_put_error(0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 552);
                    goto err_162;
                  }
                  ret_len -= v42;
                }
                *(int *)((char *)v40 + v41 + 4) = 0;
                v43 = (unsigned __int8 *)CRYPTO_malloc(*v40, ".\\crypto\\ec\\ec_mult.c", 563);
                *(int *)((char *)v40 + v41) = (int)v43;
                if ( !v43 )
                {
                  ERR_put_error(0x10u, 187, 65, ".\\crypto\\ec\\ec_mult.c", 566);
                  CRYPTO_free(str);
                  goto err_162;
                }
                memcpy(v43, src, *v40);
                if ( *v40 > v81 )
                  v81 = *v40;
                if ( !*v38 )
                  break;
                v44 = v94;
                src += v88;
                *(int *)((char *)v40 + (_DWORD)j) = (int)v38;
                ++v39;
                ++v40;
                v38 += v44;
                if ( v39 >= v78 )
                {
                  v33 = str;
                  goto LABEL_76;
                }
              }
              ERR_put_error(0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 576);
              CRYPTO_free(str);
              goto err_162;
            }
LABEL_76:
            CRYPTO_free(v33);
          }
          else
          {
            v78 = num + 1;
            v35 = v80;
            *((_DWORD *)v80 + num) = v33;
            v36 = v79;
            v35[num + 1] = 0;
            v36[num] = v34;
            *((_DWORD *)v76 + num) = v31[4];
          }
        }
        else if ( src != (unsigned __int8 *)1 )
        {
          ERR_put_error(0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 483);
          goto err_162;
        }
      }
      pointsa = (ec_point_st **)CRYPTO_malloc(4 * numa + 4, ".\\crypto\\ec\\ec_mult.c", 592);
      if ( pointsa )
      {
        v45 = pointsa;
        v46 = &pointsa[numa];
        v47 = 0;
        v94 = (int)v46;
        *v46 = 0;
        if ( v83 )
        {
          v48 = v85;
          v49 = (_BYTE *)v76 - (_BYTE *)v85;
          j = (char *)((_BYTE *)v76 - (_BYTE *)v85);
          while ( 1 )
          {
            *(_DWORD *)&v48[v49] = v45;
            v50 = 0;
            if ( 1 << (*v48 - 1) )
              break;
LABEL_88:
            ++v47;
            v48 += 4;
            if ( v47 >= v83 )
            {
              v46 = (ec_point_st **)v94;
              goto LABEL_90;
            }
          }
          while ( 1 )
          {
            v51 = EC_POINT_new(group);
            *v45 = v51;
            if ( !v51 )
              break;
            ++v50;
            ++v45;
            if ( v50 >= 1 << (*v48 - 1) )
            {
              v49 = (int)j;
              goto LABEL_88;
            }
          }
        }
        else
        {
LABEL_90:
          if ( v45 == v46 )
          {
            ra = EC_POINT_new(group);
            if ( ra )
            {
              v52 = 0;
              if ( v83 )
              {
                v53 = (ec_point_st ***)v76;
                v54 = (char *)((char *)points - (_BYTE *)v76);
                j = (char *)((char *)points - (_BYTE *)v76);
                v55 = (char *)((_BYTE *)v85 - (_BYTE *)v76);
                while ( 1 )
                {
                  v56 = v52 >= num ? v95 : *(const ec_point_st **)((char *)v53 + (_DWORD)v54);
                  if ( !EC_POINT_copy(**v53, v56) )
                    break;
                  if ( *(ec_point_st ***)((char *)v53 + (_DWORD)v55) > (ec_point_st **)1 )
                  {
                    if ( !EC_POINT_dbl(group, ra, **v53, ctx) )
                      goto err_162;
                    v57 = 1;
                    if ( (unsigned int)(1 << (*((_BYTE *)v53 + (_DWORD)v55) - 1)) > 1 )
                    {
                      while ( EC_POINT_add(group, (*v53)[v57], (*v53)[v57 - 1], ra, ctx) )
                      {
                        if ( ++v57 >= (unsigned int)(1 << (*((_BYTE *)v53 + (_DWORD)v55) - 1)) )
                          goto LABEL_104;
                      }
                      goto err_162;
                    }
LABEL_104:
                    v54 = j;
                  }
                  ++v52;
                  ++v53;
                  if ( v52 >= v83 )
                    goto LABEL_106;
                }
              }
              else
              {
LABEL_106:
                if ( EC_POINTs_make_affine(group, numa, pointsa, ctx) )
                {
                  v58 = v81 - 1;
                  v59 = 1;
                  v88 = 1;
                  if ( (int)(v81 - 1) < 0 )
                  {
LABEL_129:
                    v68 = EC_POINT_set_to_infinity(group, r);
LABEL_132:
                    if ( v68 )
LABEL_133:
                      v97 = 1;
                  }
                  else
                  {
                    while ( v59 || EC_POINT_dbl(group, r, r, ctx) )
                    {
                      ret_len = 0;
                      if ( v78 )
                      {
                        v60 = v76;
                        v61 = (_BYTE *)v79 - (_BYTE *)v80;
                        v62 = (char *)((_BYTE *)v80 - (_BYTE *)v76);
                        for ( j = (char *)((_BYTE *)v80 - (_BYTE *)v76); ; v62 = j )
                        {
                          v63 = &v62[(_DWORD)v60];
                          if ( *(_DWORD *)&v63[v61] > v58 )
                          {
                            v64 = *(_DWORD *)v63;
                            v65 = *(char *)(v64 + v58);
                            if ( *(_BYTE *)(v64 + v58) )
                            {
                              v66 = v65 < 0;
                              if ( v65 < 0 )
                                v65 = -v65;
                              if ( v66 != v89 )
                              {
                                if ( !v88 && !EC_POINT_invert(group, r, ctx) )
                                  goto err_162;
                                v89 = v89 == 0;
                              }
                              v67 = v65 >> 1;
                              if ( v88 )
                              {
                                if ( !EC_POINT_copy(r, *(const ec_point_st **)(*v60 + 4 * v67)) )
                                  goto err_162;
                                v88 = 0;
                              }
                              else if ( !EC_POINT_add(group, r, r, *(const ec_point_st **)(*v60 + 4 * v67), ctx) )
                              {
                                goto err_162;
                              }
                            }
                          }
                          ++v60;
                          if ( ++ret_len >= v78 )
                            break;
                        }
                        v59 = v88;
                      }
                      if ( (--v58 & 0x80000000) != 0 )
                      {
                        if ( v59 )
                          goto LABEL_129;
                        if ( v89 )
                        {
                          v68 = EC_POINT_invert(group, r, ctx);
                          goto LABEL_132;
                        }
                        goto LABEL_133;
                      }
                    }
                  }
                }
              }
            }
          }
          else
          {
            ERR_put_error(0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 614);
          }
        }
        goto err_162;
      }
      v75 = 595;
    }
    else
    {
      v75 = 451;
    }
    ERR_put_error(0x10u, 187, 65, ".\\crypto\\ec\\ec_mult.c", v75);
    goto err_162;
  }
  while ( meth == points[v11]->meth )
  {
    if ( ++v11 >= num )
    {
      v7 = (const env_md_st *)group;
      goto LABEL_10;
    }
  }
  ERR_put_error(0x10u, 187, 101, ".\\crypto\\ec\\ec_mult.c", 387);
  return 0;
}
