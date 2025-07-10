void __cdecl ssl_set_cert_masks(cert_st *c, const ssl_cipher_st *cipher)
{
  rsa_st *rsa_tmp; // eax
  int v4; // esi
  int v5; // ecx
  unsigned int v6; // edi
  dh_st *dh_tmp; // eax
  int v8; // ecx
  BOOL v9; // edx
  int v10; // eax
  int v11; // ebx
  int v12; // ebx
  x509_st *x509; // esi
  evp_pkey_st *pubkey; // eax
  evp_pkey_st *v15; // edi
  const asn1_object_st **p_algorithm; // esi
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // [esp+8h] [ebp-3Ch]
  int v21; // [esp+Ch] [ebp-38h]
  int v22; // [esp+Ch] [ebp-38h]
  int v23; // [esp+10h] [ebp-34h]
  int v24; // [esp+10h] [ebp-34h]
  int v25; // [esp+14h] [ebp-30h]
  int v26; // [esp+18h] [ebp-2Ch]
  BOOL v27; // [esp+1Ch] [ebp-28h]
  BOOL v28; // [esp+20h] [ebp-24h]
  int v29; // [esp+24h] [ebp-20h]
  int v30; // [esp+28h] [ebp-1Ch]
  int v31; // [esp+2Ch] [ebp-18h]
  int v32; // [esp+30h] [ebp-14h]
  int v33; // [esp+30h] [ebp-14h]
  int v34; // [esp+34h] [ebp-10h]
  int v35; // [esp+34h] [ebp-10h]
  int ppkey_nid; // [esp+38h] [ebp-Ch] BYREF
  int v37; // [esp+3Ch] [ebp-8h]
  int pdig_nid; // [esp+40h] [ebp-4h] BYREF
  int v39; // [esp+48h] [ebp+4h]

  ppkey_nid = 0;
  pdig_nid = 0;
  if ( !c )
    return;
  rsa_tmp = c->rsa_tmp;
  v4 = (cipher->algo_strength & 8) != 0 ? 512 : 1024;
  if ( rsa_tmp || c->rsa_tmp_cb )
  {
    v6 = 1;
    v5 = 1;
    v25 = 1;
  }
  else
  {
    v5 = 0;
    v25 = 0;
    v6 = 1;
  }
  v27 = c->rsa_tmp_cb || v5 && 8 * RSA_size(rsa_tmp) <= v4;
  dh_tmp = c->dh_tmp;
  if ( dh_tmp || c->dh_tmp_cb )
  {
    v8 = 1;
    v29 = 1;
  }
  else
  {
    v8 = 0;
    v29 = 0;
  }
  v28 = c->dh_tmp_cb || v8 && 8 * DH_size(dh_tmp) <= v4;
  if ( c->ecdh_tmp || (v37 = 0, c->ecdh_tmp_cb) )
    v37 = 1;
  if ( !c->pkeys[0].x509 || !c->pkeys[0].privatekey )
  {
    v23 = 0;
    goto LABEL_26;
  }
  v23 = 1;
  v26 = 1;
  if ( 8 * EVP_PKEY_size(c->pkeys[0].privatekey) > v4 )
LABEL_26:
    v26 = 0;
  if ( !c->pkeys[1].x509 || (v21 = 1, !c->pkeys[1].privatekey) )
    v21 = 0;
  if ( !c->pkeys[2].x509 || (v34 = 1, !c->pkeys[2].privatekey) )
    v34 = 0;
  if ( !c->pkeys[3].x509 || !c->pkeys[3].privatekey )
  {
    v30 = 0;
    goto LABEL_36;
  }
  v30 = 1;
  v31 = 1;
  if ( 8 * EVP_PKEY_size(c->pkeys[3].privatekey) > v4 )
LABEL_36:
    v31 = 0;
  if ( c->pkeys[4].x509 && c->pkeys[4].privatekey )
  {
    v32 = 1;
    if ( 8 * EVP_PKEY_size(c->pkeys[4].privatekey) <= v4 )
      goto LABEL_44;
  }
  else
  {
    v6 = 0;
  }
  v32 = 0;
LABEL_44:
  v9 = c->pkeys[5].x509 && c->pkeys[5].privatekey;
  v10 = 0;
  v11 = 0;
  v39 = 0;
  v20 = 0;
  if ( c->pkeys[7].x509 && c->pkeys[7].privatekey )
  {
    v39 = 512;
    v11 = 512;
  }
  if ( c->pkeys[6].x509 && c->pkeys[6].privatekey )
  {
    v39 |= 0x200u;
    v11 |= 0x100u;
  }
  if ( v23 || v25 && v21 )
    v39 |= 1u;
  if ( v26 || v27 && (v21 || v23) )
    v20 = 1;
  if ( v28 )
    v20 |= 8u;
  if ( v29 )
    v39 |= 8u;
  if ( v30 )
    v39 |= 2u;
  if ( v31 )
    v20 |= 2u;
  if ( v6 )
    v39 |= 4u;
  if ( v32 )
    v20 |= 4u;
  if ( v23 || v21 )
  {
    v11 |= 1u;
    v10 = 1;
  }
  if ( v34 )
  {
    v11 |= 2u;
    v10 |= 2u;
  }
  v12 = v11 | 4;
  v22 = v10 | 4;
  if ( v9 )
  {
    x509 = c->pkeys[5].x509;
    X509_check_purpose(v6, x509, -1, 0);
    if ( (x509->ex_flags & 2) != 0 )
      v35 = x509->ex_kusage & 8;
    else
      v35 = 1;
    if ( (x509->ex_flags & 2) != 0 )
      v33 = x509->ex_kusage & 0x80;
    else
      v33 = 1;
    pubkey = X509_get_pubkey(x509);
    v15 = pubkey;
    if ( pubkey )
      v24 = EVP_PKEY_bits(pubkey);
    else
      v24 = 0;
    EVP_PKEY_free(v15);
    p_algorithm = (const asn1_object_st **)&x509->sig_alg->algorithm;
    if ( p_algorithm && *p_algorithm )
    {
      v17 = OBJ_obj2nid(*p_algorithm);
      OBJ_find_sigid_algs(v17, &pdig_nid, &ppkey_nid);
    }
    if ( v35 )
    {
      if ( ppkey_nid == 6 || ppkey_nid == 19 )
      {
        v39 |= 0x20u;
        v12 |= 0x10u;
        if ( v24 <= 163 )
        {
          v20 |= 0x20u;
          v22 |= 0x10u;
        }
      }
      if ( ppkey_nid == 408 )
      {
        v39 |= 0x40u;
        v12 |= 0x10u;
        if ( v24 <= 163 )
        {
          v20 |= 0x40u;
          v22 |= 0x10u;
        }
      }
    }
    if ( v33 )
    {
      v12 |= 0x40u;
      v22 |= 0x40u;
    }
  }
  v18 = v39;
  v19 = v20;
  if ( v37 )
  {
    v18 = v39 | 0x80;
    v19 = v20 | 0x80;
  }
  c->mask_k = v18 | 0x100;
  c->mask_a = v12 | 0x80;
  c->export_mask_k = v19 | 0x100;
  c->export_mask_a = v22 | 0x80;
  c->valid = 1;
}
