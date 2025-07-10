int __cdecl ssl3_get_finished(ssl_st *s, int a, int b)
{
  ssl_st *v3; // esi
  int result; // eax
  ssl3_state_st *s3; // ecx
  int v6; // edi
  ssl3_state_st *v7; // ecx
  signed int peer_finish_md_len; // ebx
  char *init_msg; // ebp
  unsigned __int8 *peer_finish_md; // eax
  unsigned int v11; // edi

  v3 = s;
  result = s->method->ssl_get_message(s, a, b, 20, 64, (int *)&s);
  if ( s )
  {
    s3 = v3->s3;
    if ( !s3->change_cipher_spec )
    {
      v6 = 10;
      ERR_put_error(0x14u, 140, 154, ".\\ssl\\s3_both.c", 228);
LABEL_16:
      ssl3_send_alert(v3, 2, v6);
      return 0;
    }
    s3->change_cipher_spec = 0;
    v7 = v3->s3;
    peer_finish_md_len = v7->tmp.peer_finish_md_len;
    init_msg = (char *)v3->init_msg;
    if ( peer_finish_md_len != result )
    {
      v6 = 50;
      ERR_put_error(0x14u, 140, 111, ".\\ssl\\s3_both.c", 239);
      goto LABEL_16;
    }
    peer_finish_md = v7->tmp.peer_finish_md;
    v11 = v7->tmp.peer_finish_md_len;
    if ( (unsigned int)peer_finish_md_len >= 4 )
    {
      while ( *(_DWORD *)init_msg == *(_DWORD *)peer_finish_md )
      {
        v11 -= 4;
        peer_finish_md += 4;
        init_msg += 4;
        if ( v11 < 4 )
          goto LABEL_9;
      }
      goto LABEL_15;
    }
LABEL_9:
    if ( v11
      && (*peer_finish_md != *init_msg
       || v11 > 1 && (peer_finish_md[1] != init_msg[1] || v11 > 2 && peer_finish_md[2] != init_msg[2])) )
    {
LABEL_15:
      v6 = 51;
      ERR_put_error(0x14u, 140, 149, ".\\ssl\\s3_both.c", 246);
      goto LABEL_16;
    }
    if ( v3->type == 0x2000 )
    {
      if ( peer_finish_md_len > 64 )
        OpenSSLDie(v11, (unsigned int)v3, ".\\ssl\\s3_both.c", 254, "i <= EVP_MAX_MD_SIZE");
      memcpy(v3->s3->previous_client_finished, v3->s3->tmp.peer_finish_md, peer_finish_md_len);
      v3->s3->previous_client_finished_len = peer_finish_md_len;
      return 1;
    }
    else
    {
      if ( peer_finish_md_len > 64 )
        OpenSSLDie(v11, (unsigned int)v3, ".\\ssl\\s3_both.c", 261, "i <= EVP_MAX_MD_SIZE");
      memcpy(v3->s3->previous_server_finished, v3->s3->tmp.peer_finish_md, peer_finish_md_len);
      v3->s3->previous_server_finished_len = peer_finish_md_len;
      return 1;
    }
  }
  return result;
}
