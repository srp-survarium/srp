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
  const ec_point_st *v12; // ebx
  const ec_point_st *v13; // esi
  const ec_point_st ***data; // eax
  int v15; // ebx
  unsigned int v16; // esi
  unsigned int v17; // eax
  int v18; // eax
  unsigned int v19; // eax
  int v20; // esi
  char *v21; // ebx
  unsigned __int8 *v22; // edx
  char *v23; // ecx
  char *v24; // edi
  int *v25; // esi
  unsigned int v26; // eax
  int v27; // eax
  const bignum_st *v28; // eax
  unsigned int *v29; // ebx
  char *v30; // eax
  unsigned int v31; // ebx
  const ec_point_st ***v32; // esi
  int v33; // edi
  void *v34; // ecx
  unsigned int v35; // eax
  _DWORD *v36; // edx
  _DWORD *v37; // ecx
  unsigned int v38; // eax
  const ec_point_st **v39; // edi
  int *v40; // esi
  int v41; // ebp
  unsigned int v42; // eax
  void *v43; // eax
  int v44; // ecx
  ec_point_st **v45; // edi
  ec_point_st **v46; // eax
  unsigned int v47; // ebp
  _BYTE *v48; // esi
  int v49; // eax
  ec_point_st *v50; // eax
  unsigned int v51; // ebp
  ec_point_st ***v52; // esi
  char *v53; // edi
  char *v54; // ebx
  const ec_point_st *v55; // ecx
  int v56; // edi
  unsigned int v57; // ebx
  int v58; // esi
  _DWORD *v59; // edi
  int v60; // ebp
  char *v61; // eax
  char *v62; // eax
  int v63; // eax
  int v64; // esi
  int v65; // eax
  int v66; // esi
  int v67; // eax
  void *v68; // edi
  void *v69; // eax
  _DWORD *v70; // esi
  ec_point_st **v71; // edi
  ec_point_st *v72; // eax
  ec_point_st **i; // esi
  int v74; // [esp-8h] [ebp-70h]
  void *v75; // [esp+Ch] [ebp-5Ch]
  unsigned int v76; // [esp+10h] [ebp-58h] BYREF
  unsigned int v77; // [esp+14h] [ebp-54h]
  void *v78; // [esp+18h] [ebp-50h]
  void *v79; // [esp+1Ch] [ebp-4Ch]
  unsigned int v80; // [esp+20h] [ebp-48h]
  int v81; // [esp+24h] [ebp-44h]
  unsigned int v82; // [esp+28h] [ebp-40h]
  unsigned int numa; // [esp+2Ch] [ebp-3Ch]
  void *v84; // [esp+30h] [ebp-38h]
  unsigned __int8 *src; // [esp+34h] [ebp-34h]
  const ec_point_st ***v86; // [esp+38h] [ebp-30h]
  unsigned int v87; // [esp+3Ch] [ebp-2Ch]
  int v88; // [esp+40h] [ebp-28h]
  ec_point_st *ra; // [esp+44h] [ebp-24h]
  ec_point_st **pointsa; // [esp+48h] [ebp-20h]
  void *str; // [esp+4Ch] [ebp-1Ch]
  char *v92; // [esp+50h] [ebp-18h]
  int v93; // [esp+54h] [ebp-14h]
  const ec_point_st *v94; // [esp+58h] [ebp-10h]
  bignum_ctx *v95; // [esp+5Ch] [ebp-Ch]
  int v96; // [esp+60h] [ebp-8h]
  char *j; // [esp+64h] [ebp-4h]

  v7 = (const env_md_st *)group;
  meth = group->meth;
  v9 = 0;
  v95 = 0;
  v94 = 0;
  ra = 0;
  v87 = 0;
  v81 = 0;
  v93 = 0;
  v88 = 0;
  v84 = 0;
  v79 = 0;
  v78 = 0;
  v80 = 0;
  pointsa = 0;
  v75 = 0;
  v86 = 0;
  src = 0;
  v96 = 0;
  if ( meth != r->meth )
  {
    ERR_put_error((int)group, 0x10u, 187, 101, ".\\crypto\\ec\\ec_mult.c", 374);
    return 0;
  }
  if ( !scalar && !num )
    return EC_POINT_set_to_infinity((int)group, group, r);
  v11 = 0;
  if ( !num )
  {
LABEL_10:
    if ( !ctx )
    {
      v95 = BN_CTX_new((int)v7);
      ctx = v95;
      if ( !v95 )
        return v96;
    }
    if ( scalar )
    {
      v13 = (const ec_point_st *)EVP_CIPHER_block_size(v7);
      v94 = v13;
      if ( !v13 )
      {
        ERR_put_error((int)v7, 0x10u, 187, 113, ".\\crypto\\ec\\ec_mult.c", 404);
err_164:
        if ( v95 )
          BN_CTX_free(v95);
        if ( ra )
          EC_POINT_free(ra);
        if ( v84 )
          CRYPTO_free(v84);
        if ( v78 )
          CRYPTO_free(v78);
        v68 = v79;
        if ( v79 )
        {
          v69 = *(void **)v79;
          v70 = v79;
          if ( *(_DWORD *)v79 )
          {
            do
            {
              CRYPTO_free(v69);
              v69 = (void *)v70[1];
              ++v70;
            }
            while ( v69 );
          }
          CRYPTO_free(v68);
        }
        v71 = pointsa;
        if ( pointsa )
        {
          v72 = *pointsa;
          for ( i = pointsa; v72; ++i )
          {
            EC_POINT_clear_free(v72);
            v72 = i[1];
          }
          CRYPTO_free(v71);
        }
        if ( v75 )
          CRYPTO_free(v75);
        return v96;
      }
      data = (const ec_point_st ***)EC_EX_DATA_get_data(
                                      group->extra_data,
                                      (void *(__cdecl *)(void *))ec_pre_comp_dup,
                                      ec_pre_comp_free,
                                      ec_pre_comp_clear_free);
      v15 = (int)data;
      v86 = data;
      if ( data && data[2] && !EC_POINT_cmp((int)data, group, v13, *data[4], ctx) )
      {
        v87 = *(_DWORD *)(v15 + 4);
        v16 = BN_num_bits(scalar) / v87;
        v17 = *(_DWORD *)(v15 + 8);
        v9 = v16 + 1;
        v81 = v9;
        if ( v9 > v17 )
        {
          v9 = v17;
          v81 = v17;
        }
        v18 = (1 << (*(_BYTE *)(v15 + 12) - 1)) * v17;
        v93 = 1 << (*(_BYTE *)(v15 + 12) - 1);
        if ( *(_DWORD *)(v15 + 20) != v18 )
        {
          ERR_put_error(v15, 0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 429);
          goto err_164;
        }
      }
      else
      {
        v9 = 1;
        v86 = 0;
        v81 = 1;
        src = (unsigned __int8 *)1;
      }
    }
    v19 = v9 + num;
    v20 = 4 * (v9 + num);
    v77 = v19;
    v21 = (char *)CRYPTO_malloc(v20, ".\\crypto\\ec\\ec_mult.c", 444);
    v84 = v21;
    v78 = CRYPTO_malloc(v20, ".\\crypto\\ec\\ec_mult.c", 445);
    v79 = CRYPTO_malloc(v20 + 4, ".\\crypto\\ec\\ec_mult.c", 446);
    v75 = CRYPTO_malloc(v20, ".\\crypto\\ec\\ec_mult.c", 447);
    if ( v21 && v78 && v79 && v75 )
    {
      v22 = src;
      *(_DWORD *)v79 = 0;
      numa = 0;
      v76 = 0;
      v82 = (unsigned int)&v22[num];
      if ( &v22[num] )
      {
        v23 = (char *)((char *)scalars - v21);
        v24 = (char *)((_BYTE *)v79 - v21);
        v25 = (int *)v21;
        str = (void *)((char *)scalars - v21);
        v92 = (char *)((_BYTE *)v79 - v21);
        j = (char *)((_BYTE *)v78 - v21);
        while ( 1 )
        {
          v26 = v76 >= num ? BN_num_bits(scalar) : BN_num_bits(*(const bignum_st **)((char *)v25 + (_DWORD)v23));
          if ( v26 < 0x7D0 )
          {
            if ( v26 < 0x320 )
            {
              if ( v26 < 0x12C )
                v27 = v26 < 0x46 ? 2 - (v26 < 0x14) : 3;
              else
                v27 = 4;
            }
            else
            {
              v27 = 5;
            }
          }
          else
          {
            v27 = 6;
          }
          *v25 = v27;
          *(int *)((char *)v25 + (_DWORD)v24 + 4) = 0;
          numa += 1 << (v27 - 1);
          v28 = v76 >= num ? scalar : *(const bignum_st **)((char *)v25 + (_DWORD)str);
          v29 = (unsigned int *)((char *)v25 + (_DWORD)j);
          v30 = compute_wNAF(*v25, v28, (unsigned int *)((char *)v25 + (_DWORD)j));
          *(int *)((char *)v25 + (_DWORD)v92) = (int)v30;
          if ( !v30 )
            goto err_164;
          v31 = *v29;
          if ( v31 > v80 )
            v80 = v31;
          ++v25;
          if ( ++v76 >= v82 )
          {
            v21 = (char *)v84;
            break;
          }
          v24 = v92;
          v23 = (char *)str;
        }
      }
      if ( v81 )
      {
        v32 = v86;
        if ( v86 )
        {
          v76 = 0;
          if ( src )
          {
            ERR_put_error((int)v21, 0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 495);
            goto err_164;
          }
          v33 = (int)v86[3];
          *(_DWORD *)&v21[4 * num] = v33;
          v34 = compute_wNAF(v33, scalar, &v76);
          str = v34;
          if ( !v34 )
            goto err_164;
          v35 = v76;
          if ( v76 > v80 )
          {
            if ( v76 < v87 * v81 )
            {
              v38 = (v76 + v87 - 1) / v87;
              if ( v38 > (unsigned int)v32[2] )
              {
                ERR_put_error((int)v21, 0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 535);
                goto err_164;
              }
              v77 = num + v38;
            }
            v39 = v86[4];
            src = (unsigned __int8 *)v34;
            v21 = (char *)num;
            if ( num < v77 )
            {
              v40 = (int *)((char *)v78 + 4 * num);
              v41 = (_BYTE *)v79 - (_BYTE *)v78;
              j = (char *)((_BYTE *)v75 - (_BYTE *)v78);
              while ( 1 )
              {
                if ( (unsigned int)v21 >= v77 - 1 )
                {
                  *v40 = v76;
                }
                else
                {
                  v42 = v87;
                  *v40 = v87;
                  if ( v76 < v42 )
                  {
                    ERR_put_error((int)v21, 0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 552);
                    goto err_164;
                  }
                  v76 -= v42;
                }
                *(int *)((char *)v40 + v41 + 4) = 0;
                v43 = CRYPTO_malloc(*v40, ".\\crypto\\ec\\ec_mult.c", 563);
                *(int *)((char *)v40 + v41) = (int)v43;
                if ( !v43 )
                {
                  ERR_put_error((int)v21, 0x10u, 187, 65, ".\\crypto\\ec\\ec_mult.c", 566);
                  CRYPTO_free(str);
                  goto err_164;
                }
                memcpy((int)v43, (const __m128i *)src, *v40);
                if ( *v40 > v80 )
                  v80 = *v40;
                if ( !*v39 )
                  break;
                v44 = v93;
                src += v87;
                *(int *)((char *)v40 + (_DWORD)j) = (int)v39;
                ++v21;
                ++v40;
                v39 += v44;
                if ( (unsigned int)v21 >= v77 )
                {
                  v34 = str;
                  goto LABEL_76;
                }
              }
              ERR_put_error((int)v21, 0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 576);
              CRYPTO_free(str);
              goto err_164;
            }
LABEL_76:
            CRYPTO_free(v34);
          }
          else
          {
            v77 = num + 1;
            v36 = v79;
            *((_DWORD *)v79 + num) = v34;
            v37 = v78;
            v36[num + 1] = 0;
            v37[num] = v35;
            *((_DWORD *)v75 + num) = v32[4];
          }
        }
        else if ( src != (unsigned __int8 *)1 )
        {
          ERR_put_error((int)v21, 0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 483);
          goto err_164;
        }
      }
      pointsa = (ec_point_st **)CRYPTO_malloc(4 * numa + 4, ".\\crypto\\ec\\ec_mult.c", 592);
      if ( pointsa )
      {
        v45 = pointsa;
        v46 = &pointsa[numa];
        v47 = 0;
        v93 = (int)v46;
        *v46 = 0;
        if ( v82 )
        {
          v48 = v84;
          v49 = (_BYTE *)v75 - (_BYTE *)v84;
          j = (char *)((_BYTE *)v75 - (_BYTE *)v84);
          while ( 1 )
          {
            *(_DWORD *)&v48[v49] = v45;
            v21 = 0;
            if ( 1 << (*v48 - 1) )
              break;
LABEL_88:
            ++v47;
            v48 += 4;
            if ( v47 >= v82 )
            {
              v46 = (ec_point_st **)v93;
              goto LABEL_90;
            }
          }
          while ( 1 )
          {
            v50 = EC_POINT_new((int)v21, group);
            *v45 = v50;
            if ( !v50 )
              break;
            ++v21;
            ++v45;
            if ( (unsigned int)v21 >= 1 << (*v48 - 1) )
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
            ra = EC_POINT_new((int)v21, group);
            if ( ra )
            {
              v51 = 0;
              if ( v82 )
              {
                v52 = (ec_point_st ***)v75;
                v53 = (char *)((char *)points - (_BYTE *)v75);
                j = (char *)((char *)points - (_BYTE *)v75);
                v54 = (char *)((_BYTE *)v84 - (_BYTE *)v75);
                while ( 1 )
                {
                  v55 = v51 >= num ? v94 : *(const ec_point_st **)((char *)v52 + (_DWORD)v53);
                  if ( !EC_POINT_copy((int)v54, **v52, v55) )
                    break;
                  if ( *(ec_point_st ***)((char *)v52 + (_DWORD)v54) > (ec_point_st **)1 )
                  {
                    if ( !EC_POINT_dbl((int)v54, group, ra, **v52, ctx) )
                      goto err_164;
                    v56 = 1;
                    if ( (unsigned int)(1 << (*((_BYTE *)v52 + (_DWORD)v54) - 1)) > 1 )
                    {
                      while ( EC_POINT_add(group, (*v52)[v56], (*v52)[v56 - 1], ra, ctx) )
                      {
                        if ( ++v56 >= (unsigned int)(1 << (*((_BYTE *)v52 + (_DWORD)v54) - 1)) )
                          goto LABEL_104;
                      }
                      goto err_164;
                    }
LABEL_104:
                    v53 = j;
                  }
                  ++v51;
                  ++v52;
                  if ( v51 >= v82 )
                    goto LABEL_106;
                }
              }
              else
              {
LABEL_106:
                if ( EC_POINTs_make_affine(group, numa, pointsa, ctx) )
                {
                  v57 = v80 - 1;
                  v58 = 1;
                  v87 = 1;
                  if ( (int)(v80 - 1) < 0 )
                  {
LABEL_129:
                    v67 = EC_POINT_set_to_infinity(v57, group, r);
LABEL_132:
                    if ( v67 )
LABEL_133:
                      v96 = 1;
                  }
                  else
                  {
                    while ( v58 || EC_POINT_dbl(v57, group, r, r, ctx) )
                    {
                      v76 = 0;
                      if ( v77 )
                      {
                        v59 = v75;
                        v60 = (_BYTE *)v78 - (_BYTE *)v79;
                        v61 = (char *)((_BYTE *)v79 - (_BYTE *)v75);
                        for ( j = (char *)((_BYTE *)v79 - (_BYTE *)v75); ; v61 = j )
                        {
                          v62 = &v61[(_DWORD)v59];
                          if ( *(_DWORD *)&v62[v60] > v57 )
                          {
                            v63 = *(_DWORD *)v62;
                            v64 = *(char *)(v63 + v57);
                            if ( *(_BYTE *)(v63 + v57) )
                            {
                              v65 = v64 < 0;
                              if ( v64 < 0 )
                                v64 = -v64;
                              if ( v65 != v88 )
                              {
                                if ( !v87 && !EC_POINT_invert(v57, group, r, ctx) )
                                  goto err_164;
                                v88 = v88 == 0;
                              }
                              v66 = v64 >> 1;
                              if ( v87 )
                              {
                                if ( !EC_POINT_copy(v57, r, *(const ec_point_st **)(*v59 + 4 * v66)) )
                                  goto err_164;
                                v87 = 0;
                              }
                              else if ( !EC_POINT_add(group, r, r, *(const ec_point_st **)(*v59 + 4 * v66), ctx) )
                              {
                                goto err_164;
                              }
                            }
                          }
                          ++v59;
                          if ( ++v76 >= v77 )
                            break;
                        }
                        v58 = v87;
                      }
                      if ( (--v57 & 0x80000000) != 0 )
                      {
                        if ( v58 )
                          goto LABEL_129;
                        if ( v88 )
                        {
                          v67 = EC_POINT_invert(v57, group, r, ctx);
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
            ERR_put_error((int)v21, 0x10u, 187, 68, ".\\crypto\\ec\\ec_mult.c", 614);
          }
        }
        goto err_164;
      }
      v74 = 595;
    }
    else
    {
      v74 = 451;
    }
    ERR_put_error((int)v21, 0x10u, 187, 65, ".\\crypto\\ec\\ec_mult.c", v74);
    goto err_164;
  }
  while ( 1 )
  {
    v12 = points[v11];
    if ( meth != v12->meth )
      break;
    if ( ++v11 >= num )
    {
      v7 = (const env_md_st *)group;
      goto LABEL_10;
    }
  }
  ERR_put_error((int)v12, 0x10u, 187, 101, ".\\crypto\\ec\\ec_mult.c", 387);
  return 0;
}
