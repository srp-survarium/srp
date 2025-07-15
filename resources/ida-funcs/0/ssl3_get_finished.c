int __usercall ssl3_get_finished@<eax>(int a1@<ebx>, ssl_st *s, int a, int b)
{
  ssl_st *v4; // esi
  int result; // eax
  ssl3_state_st *s3; // ecx
  int v7; // edi
  ssl3_state_st *v8; // ecx
  int peer_finish_md_len; // ebx
  char *init_msg; // ebp
  unsigned __int8 *peer_finish_md; // eax
  unsigned int v12; // edi

  v4 = s;
  result = s->method->ssl_get_message(s, a, b, 20, 64, (int *)&s);
  if ( s )
  {
    s3 = v4->s3;
    if ( !s3->change_cipher_spec )
    {
      v7 = 10;
      ERR_put_error(a1, 0x14u, 140, 154, ".\\ssl\\s3_both.c", 228);
LABEL_16:
      ssl3_send_alert(v4, 2, v7);
      return 0;
    }
    s3->change_cipher_spec = 0;
    v8 = v4->s3;
    peer_finish_md_len = v8->tmp.peer_finish_md_len;
    init_msg = (char *)v4->init_msg;
    if ( peer_finish_md_len != result )
    {
      v7 = 50;
      ERR_put_error(peer_finish_md_len, 0x14u, 140, 111, ".\\ssl\\s3_both.c", 239);
      goto LABEL_16;
    }
    peer_finish_md = v8->tmp.peer_finish_md;
    v12 = v8->tmp.peer_finish_md_len;
    if ( (unsigned int)peer_finish_md_len >= 4 )
    {
      while ( *(_DWORD *)init_msg == *(_DWORD *)peer_finish_md )
      {
        v12 -= 4;
        peer_finish_md += 4;
        init_msg += 4;
        if ( v12 < 4 )
          goto LABEL_9;
      }
      goto LABEL_15;
    }
LABEL_9:
    if ( v12
      && (*peer_finish_md != *init_msg
       || v12 > 1 && (peer_finish_md[1] != init_msg[1] || v12 > 2 && peer_finish_md[2] != init_msg[2])) )
    {
LABEL_15:
      v7 = 51;
      ERR_put_error(peer_finish_md_len, 0x14u, 140, 149, ".\\ssl\\s3_both.c", 246);
      goto LABEL_16;
    }
    if ( v4->type == 0x2000 )
    {
      if ( peer_finish_md_len > 64 )
        OpenSSLDie(v12, (int)v4, peer_finish_md_len, ".\\ssl\\s3_both.c", 254, "i <= EVP_MAX_MD_SIZE");
      memcpy((int)v4->s3->previous_client_finished, (const __m128i *)v4->s3->tmp.peer_finish_md, peer_finish_md_len);
      v4->s3->previous_client_finished_len = peer_finish_md_len;
      return 1;
    }
    else
    {
      if ( peer_finish_md_len > 64 )
        OpenSSLDie(v12, (int)v4, peer_finish_md_len, ".\\ssl\\s3_both.c", 261, "i <= EVP_MAX_MD_SIZE");
      memcpy((int)v4->s3->previous_server_finished, (const __m128i *)v4->s3->tmp.peer_finish_md, peer_finish_md_len);
      v4->s3->previous_server_finished_len = peer_finish_md_len;
      return 1;
    }
  }
  return result;
}
