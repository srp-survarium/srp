int __cdecl tls1_mac(ssl_st *ssl, unsigned __int8 *md, int send)
{
  env_md_ctx_st *write_hash; // edi
  ssl3_state_st *s3; // eax
  int p_wrec; // ebx
  unsigned __int8 *write_sequence; // eax
  ssl3_state_st *v7; // eax
  ui_string_st *object; // eax
  int v9; // ebp
  int version; // edx
  char v11; // al
  env_md_ctx_st *p_out; // ebp
  int v13; // edi
  dtls1_state_st *d1; // eax
  unsigned __int16 w_epoch; // di
  unsigned __int16 r_epoch; // ax
  __int16 v17; // dx
  int i; // eax
  int v21; // [esp+10h] [ebp-3Ch] BYREF
  int v22; // [esp+14h] [ebp-38h]
  int v23; // [esp+18h] [ebp-34h]
  unsigned __int8 *v24; // [esp+1Ch] [ebp-30h]
  env_md_ctx_st out; // [esp+20h] [ebp-2Ch] BYREF
  char v26; // [esp+38h] [ebp-14h]
  char v27; // [esp+39h] [ebp-13h]
  char v28; // [esp+3Ah] [ebp-12h]
  char v29; // [esp+3Bh] [ebp-11h]
  char v30; // [esp+3Ch] [ebp-10h]
  char v31; // [esp+40h] [ebp-Ch]
  char v32; // [esp+41h] [ebp-Bh]
  int v33; // [esp+42h] [ebp-Ah]
  __int16 v34; // [esp+46h] [ebp-6h]

  v24 = md;
  if ( send )
  {
    write_hash = ssl->write_hash;
    v23 = ssl->mac_flags & 2;
    s3 = ssl->s3;
    p_wrec = (int)&s3->wrec;
    write_sequence = s3->write_sequence;
  }
  else
  {
    write_hash = ssl->read_hash;
    v23 = ssl->mac_flags & 1;
    v7 = ssl->s3;
    p_wrec = (int)&v7->rrec;
    write_sequence = v7->read_sequence;
  }
  v22 = (int)write_sequence;
  object = X509_EXTENSION_get_object((ui_string_st *)write_hash);
  v9 = EVP_MD_size(p_wrec, (const env_md_st *)object);
  if ( v9 < 0 )
    OpenSSLDie((int)write_hash, (int)ssl, p_wrec, ".\\ssl\\t1_enc.c", 902, "t >= 0");
  version = ssl->version;
  v11 = ssl->version;
  v21 = v9;
  v26 = *(_BYTE *)p_wrec;
  v27 = BYTE1(version);
  v28 = v11;
  v29 = BYTE1(*(_DWORD *)(p_wrec + 4));
  v30 = *(_BYTE *)(p_wrec + 4);
  if ( v23 )
  {
    p_out = write_hash;
  }
  else
  {
    EVP_MD_CTX_copy(&out, write_hash);
    p_out = &out;
  }
  if ( ssl->version == 65279 || ssl->version == 256 )
  {
    d1 = ssl->d1;
    if ( send )
      w_epoch = d1->w_epoch;
    else
      w_epoch = d1->r_epoch;
    v31 = HIBYTE(w_epoch);
    if ( send )
      r_epoch = d1->w_epoch;
    else
      r_epoch = d1->r_epoch;
    v32 = r_epoch;
    v17 = *(_WORD *)(v22 + 6);
    v33 = *(_DWORD *)(v22 + 2);
    v34 = v17;
    EVP_DigestUpdate(p_out);
    v13 = v22;
  }
  else
  {
    v13 = v22;
    EVP_DigestUpdate(p_out);
  }
  EVP_DigestUpdate(p_out);
  EVP_DigestUpdate(p_out);
  if ( EVP_DigestSignFinal(p_out, v24, (unsigned int *)&v21) <= 0 )
    OpenSSLDie(v13, (int)ssl, p_wrec, ".\\ssl\\t1_enc.c", 937, "t > 0");
  if ( !v23 )
    EVP_MD_CTX_cleanup(v13, p_wrec, &out);
  if ( ssl->version != 65279 && ssl->version != 256 )
  {
    for ( i = 7; i >= 0; --i )
    {
      if ( (*(_BYTE *)(i + v13))++ != 0xFF )
        break;
    }
  }
  return v21;
}
