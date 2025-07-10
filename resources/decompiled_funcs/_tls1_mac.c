unsigned int __cdecl tls1_mac(ssl_st *ssl, unsigned __int8 *md, int send)
{
  env_md_ctx_st *write_hash; // edi
  ssl3_state_st *s3; // eax
  ssl3_record_st *p_wrec; // ebx
  unsigned __int8 *write_sequence; // eax
  ssl3_state_st *v7; // eax
  ui_string_st *object; // eax
  signed int v9; // ebp
  int version; // edx
  char v11; // al
  env_md_ctx_st *p_out; // ebp
  _BYTE *v13; // edi
  dtls1_state_st *d1; // eax
  unsigned __int16 w_epoch; // di
  unsigned __int16 r_epoch; // ax
  __int16 v17; // dx
  int i; // eax
  unsigned int siglen; // [esp+10h] [ebp-3Ch] BYREF
  void *data; // [esp+14h] [ebp-38h]
  int v23; // [esp+18h] [ebp-34h]
  unsigned __int8 *sigret; // [esp+1Ch] [ebp-30h]
  env_md_ctx_st out; // [esp+20h] [ebp-2Ch] BYREF
  char type; // [esp+38h] [ebp-14h]
  char v27; // [esp+39h] [ebp-13h]
  char v28; // [esp+3Ah] [ebp-12h]
  char v29; // [esp+3Bh] [ebp-11h]
  char length; // [esp+3Ch] [ebp-10h]
  char v31; // [esp+40h] [ebp-Ch]
  char v32; // [esp+41h] [ebp-Bh]
  int v33; // [esp+42h] [ebp-Ah]
  __int16 v34; // [esp+46h] [ebp-6h]

  sigret = md;
  if ( send )
  {
    write_hash = ssl->write_hash;
    v23 = ssl->mac_flags & 2;
    s3 = ssl->s3;
    p_wrec = &s3->wrec;
    write_sequence = s3->write_sequence;
  }
  else
  {
    write_hash = ssl->read_hash;
    v23 = ssl->mac_flags & 1;
    v7 = ssl->s3;
    p_wrec = &v7->rrec;
    write_sequence = v7->read_sequence;
  }
  data = write_sequence;
  object = X509_EXTENSION_get_object((ui_string_st *)write_hash);
  v9 = EVP_MD_size((const env_md_st *)object);
  if ( v9 < 0 )
    OpenSSLDie((unsigned int)write_hash, (unsigned int)ssl, ".\\ssl\\t1_enc.c", 902, "t >= 0");
  version = ssl->version;
  v11 = ssl->version;
  siglen = v9;
  type = p_wrec->type;
  v27 = BYTE1(version);
  v28 = v11;
  v29 = BYTE1(p_wrec->length);
  length = p_wrec->length;
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
    v17 = *((_WORD *)data + 3);
    v33 = *(_DWORD *)((char *)data + 2);
    v34 = v17;
    EVP_DigestUpdate(p_out);
    v13 = data;
  }
  else
  {
    v13 = data;
    EVP_DigestUpdate(p_out);
  }
  EVP_DigestUpdate(p_out);
  EVP_DigestUpdate(p_out);
  if ( EVP_DigestSignFinal(p_out, sigret, &siglen) <= 0 )
    OpenSSLDie((unsigned int)v13, (unsigned int)ssl, ".\\ssl\\t1_enc.c", 937, "t > 0");
  if ( !v23 )
    EVP_MD_CTX_cleanup((unsigned int)v13, &out);
  if ( ssl->version != 65279 && ssl->version != 256 )
  {
    for ( i = 7; i >= 0; --i )
    {
      if ( v13[i]++ != 0xFF )
        break;
    }
  }
  return siglen;
}
