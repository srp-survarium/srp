int __usercall ssl3_do_change_cipher_spec@<eax>(int a1@<ebx>, ssl_st *s)
{
  ssl3_state_st *s3; // eax
  int v3; // edi
  ssl_session_st *session; // ecx
  ssl3_enc_method *ssl3_enc; // eax
  const char *server_finished_label; // ecx
  int server_finished_label_len; // eax

  s3 = s->s3;
  v3 = (s->state & 0x2000) != 0 ? 33 : 17;
  if ( !s3->tmp.key_block )
  {
    session = s->session;
    if ( !session )
    {
      ERR_put_error(a1, 0x14u, 292, 133, ".\\ssl\\s3_pkt.c", 1373);
      return 0;
    }
    session->cipher = s3->tmp.new_cipher;
    if ( !s->method->ssl3_enc->setup_key_block(s) )
      return 0;
  }
  if ( !s->method->ssl3_enc->change_cipher_state(s, v3) )
    return 0;
  ssl3_enc = s->method->ssl3_enc;
  if ( (s->state & 0x1000) != 0 )
  {
    server_finished_label = ssl3_enc->server_finished_label;
    server_finished_label_len = ssl3_enc->server_finished_label_len;
  }
  else
  {
    server_finished_label = ssl3_enc->client_finished_label;
    server_finished_label_len = ssl3_enc->client_finished_label_len;
  }
  s->s3->tmp.peer_finish_md_len = s->method->ssl3_enc->final_finish_mac(
                                    s,
                                    server_finished_label,
                                    server_finished_label_len,
                                    s->s3->tmp.peer_finish_md);
  return 1;
}
