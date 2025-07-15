int __cdecl ssl_check_srvr_ecc_cert_and_alg(x509_st *x, const ssl_cipher_st *cs)
{
  unsigned int algorithm_auth; // ecx
  unsigned int algorithm_mkey; // ebx
  int v4; // edi
  bool v5; // zf
  evp_pkey_st *pubkey; // eax
  evp_pkey_st *v7; // esi
  X509_algor_st *sig_alg; // eax
  void *v9; // eax
  int ppkey_nid; // [esp+10h] [ebp-8h] BYREF
  int pdig_nid; // [esp+14h] [ebp-4h] BYREF
  char v13; // [esp+20h] [ebp+8h]

  algorithm_auth = cs->algorithm_auth;
  algorithm_mkey = cs->algorithm_mkey;
  v4 = 0;
  v5 = (cs->algo_strength & 2) == 0;
  pdig_nid = 0;
  ppkey_nid = 0;
  v13 = algorithm_auth;
  if ( !v5 )
  {
    pubkey = X509_get_pubkey(x);
    v7 = pubkey;
    if ( !pubkey )
      return 0;
    v4 = EVP_PKEY_bits(pubkey);
    EVP_PKEY_free(v4, v7);
    if ( v4 > 163 )
      return 0;
  }
  X509_check_purpose(v4, algorithm_mkey, x, -1, 0);
  sig_alg = x->sig_alg;
  if ( sig_alg && sig_alg->algorithm )
  {
    v9 = OBJ_obj2nid(sig_alg->algorithm);
    OBJ_find_sigid_algs(v4, (int)v9, &pdig_nid, &ppkey_nid);
  }
  if ( (algorithm_mkey & 0x40) != 0 || (algorithm_mkey & 0x20) != 0 )
  {
    if ( (x->ex_flags & 2) != 0 && (x->ex_kusage & 8) == 0 )
    {
      ERR_put_error(algorithm_mkey, 0x14u, 279, 317, ".\\ssl\\ssl_lib.c", 2071);
      return 0;
    }
    if ( (algorithm_mkey & 0x40) != 0 && ppkey_nid != 408 )
    {
      ERR_put_error(algorithm_mkey, 0x14u, 279, 323, ".\\ssl\\ssl_lib.c", 2079);
      return 0;
    }
    if ( (algorithm_mkey & 0x20) != 0 && ppkey_nid != 6 && ppkey_nid != 19 )
    {
      ERR_put_error(algorithm_mkey, 0x14u, 279, 322, ".\\ssl\\ssl_lib.c", 2089);
      return 0;
    }
  }
  if ( (v13 & 0x40) != 0 && (x->ex_flags & 2) != 0 && SLOBYTE(x->ex_kusage) >= 0 )
  {
    ERR_put_error(algorithm_mkey, 0x14u, 279, 318, ".\\ssl\\ssl_lib.c", 2099);
    return 0;
  }
  return 1;
}
