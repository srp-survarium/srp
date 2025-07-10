int __cdecl ssl3_read_bytes(ssl_st *s, int type, unsigned __int8 *buf, int len, int peek)
{
  int result; // eax
  ssl3_state_st *s3; // eax
  int v7; // edi
  unsigned __int8 *handshake_fragment; // ecx
  unsigned int i; // edi
  ssl3_record_st *p_rrec; // edi
  ssl3_state_st *v11; // eax
  int v12; // ecx
  unsigned int v13; // edx
  unsigned __int8 *alert_fragment; // ecx
  unsigned int *p_handshake_fragment_len; // eax
  unsigned int v16; // ecx
  ssl3_state_st *v17; // eax
  ssl_session_st *v18; // ecx
  ssl3_state_st *v19; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // ecx
  ssl3_state_st *v21; // eax
  bool v22; // zf
  bio_st *v23; // esi
  ssl3_state_st *v24; // eax
  ssl_session_st *session; // eax
  ssl3_state_st *v26; // eax
  int v27; // ebp
  int v28; // edi
  void (__cdecl *v29)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  void (__cdecl *info_callback)(const ssl_st *, int, int); // eax
  int v31; // edi
  int v32; // ecx
  unsigned __int8 *data; // ecx
  void (__cdecl *v34)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  unsigned int length; // ebp
  unsigned int v36; // eax
  ssl3_state_st *v37; // ecx
  ssl_session_st *v38; // edx
  ssl_ctx_st *ctx; // eax
  ssl3_state_st *v40; // ecx
  int state; // eax
  __int16 v42; // [esp-14h] [ebp-40h]
  int v43; // [esp-Ch] [ebp-38h]
  void (__cdecl *v44)(const ssl_st *, int, int); // [esp+8h] [ebp-24h]
  unsigned __int8 *v45; // [esp+14h] [ebp-18h]
  char bufa[16]; // [esp+18h] [ebp-14h] BYREF

  v44 = 0;
  if ( !s->s3->rbuf.buf && !ssl3_setup_read_buffer(s) )
    return -1;
  if ( type && type != 23 && type != 22 || peek && type != 23 )
  {
    ERR_put_error(0x14u, 148, 68, ".\\ssl\\s3_pkt.c", 911);
    return -1;
  }
  if ( type == 22 )
  {
    s3 = s->s3;
    if ( s3->handshake_fragment_len )
    {
      v7 = len;
      handshake_fragment = s3->handshake_fragment;
      for ( result = 0; v7 > 0; ++result )
      {
        if ( !s->s3->handshake_fragment_len )
          break;
        buf[result] = *handshake_fragment;
        --s->s3->handshake_fragment_len;
        --v7;
        ++handshake_fragment;
      }
      for ( i = 0; i < s->s3->handshake_fragment_len; ++handshake_fragment )
        s->s3->handshake_fragment[i++] = *handshake_fragment;
      return result;
    }
  }
  if ( s->in_handshake || (SSL_state(s) & 0x3000) == 0 )
    goto start_12;
  result = s->handshake_func(s);
  if ( result >= 0 )
  {
    if ( !result )
    {
      ERR_put_error(0x14u, 148, 229, ".\\ssl\\s3_pkt.c", 945);
      return -1;
    }
    while ( 1 )
    {
      while ( 1 )
      {
start_12:
        p_rrec = &s->s3->rrec;
        s->rwstate = 1;
        if ( !p_rrec->length || s->rstate == 241 )
        {
          result = ssl3_get_record(s);
          if ( result <= 0 )
            return result;
        }
        v11 = s->s3;
        if ( v11->change_cipher_spec && p_rrec->type != 22 )
        {
          v43 = 972;
          v42 = 145;
LABEL_142:
          v31 = 10;
          ERR_put_error(0x14u, 148, v42, ".\\ssl\\s3_pkt.c", v43);
          goto LABEL_143;
        }
        if ( (s->shutdown & 2) != 0 )
        {
          p_rrec->length = 0;
          s->rwstate = 1;
          return 0;
        }
        v12 = p_rrec->type;
        if ( type == p_rrec->type )
        {
          if ( (SSL_state(s) & 0x3000) != 0 && type == 23 && !s->enc_read_ctx )
          {
            v43 = 994;
            v42 = 100;
            goto LABEL_142;
          }
          result = len;
          if ( len > 0 )
          {
            length = p_rrec->length;
            if ( len <= length )
              length = len;
            memcpy(buf, &p_rrec->data[p_rrec->off], length);
            if ( !peek )
            {
              p_rrec->length -= length;
              v36 = p_rrec->length;
              p_rrec->off += length;
              if ( !v36 )
              {
                s->rstate = 240;
                p_rrec->off = 0;
                if ( (s->mode & 0x10) != 0 )
                  ssl3_release_read_buffer(s);
              }
            }
            return length;
          }
          return result;
        }
        if ( v12 != 22 )
          break;
        v13 = 4;
        alert_fragment = v11->handshake_fragment;
        p_handshake_fragment_len = &v11->handshake_fragment_len;
LABEL_34:
        v45 = alert_fragment;
        v16 = v13 - *p_handshake_fragment_len;
        if ( p_rrec->length < v16 )
          v16 = p_rrec->length;
        for ( ; v16; --v16 )
        {
          v45[(*p_handshake_fragment_len)++] = p_rrec->data[p_rrec->off++];
          --p_rrec->length;
        }
        if ( *p_handshake_fragment_len >= v13 )
          goto LABEL_39;
      }
      if ( v12 == 21 )
      {
        alert_fragment = v11->alert_fragment;
        v13 = 2;
        p_handshake_fragment_len = &v11->alert_fragment_len;
        goto LABEL_34;
      }
LABEL_39:
      if ( s->server )
      {
        if ( SSL_state(s) != 3 )
          goto LABEL_69;
        v24 = s->s3;
        if ( v24->send_connection_binding )
          goto LABEL_69;
        if ( s->version <= 768 )
          goto LABEL_69;
        if ( v24->handshake_fragment_len < 4 )
          goto LABEL_69;
        if ( v24->handshake_fragment[0] != 1 )
          goto LABEL_69;
        session = s->session;
        if ( !session || !session->cipher || (s->ctx->options & 0x40000) != 0 )
          goto LABEL_69;
        p_rrec->length = 0;
        ssl3_send_alert(s, 1, 100);
      }
      else
      {
        v17 = s->s3;
        if ( v17->handshake_fragment_len >= 4 && !v17->handshake_fragment[0] && (v18 = s->session) != 0 && v18->cipher )
        {
          v17->handshake_fragment_len = 0;
          v19 = s->s3;
          if ( v19->handshake_fragment[1] || v19->handshake_fragment[2] || v19->handshake_fragment[3] )
          {
            v31 = 50;
            ERR_put_error(0x14u, 148, 105, ".\\ssl\\s3_pkt.c", 1081);
            goto LABEL_143;
          }
          msg_callback = s->msg_callback;
          if ( msg_callback )
            msg_callback(0, s->version, 22, v19->handshake_fragment, 4u, s, s->msg_callback_arg);
          if ( SSL_state(s) == 3 )
          {
            v21 = s->s3;
            if ( (v21->flags & 1) == 0 && !v21->renegotiate )
            {
              ssl3_renegotiate(s);
              if ( ssl3_renegotiate_check(s) )
              {
                result = s->handshake_func(s);
                if ( result < 0 )
                  return result;
                if ( !result )
                {
                  ERR_put_error(0x14u, 148, 229, ".\\ssl\\s3_pkt.c", 1099);
                  return -1;
                }
                if ( (s->mode & 4) == 0 )
                {
                  v22 = s->s3->rbuf.left == 0;
LABEL_57:
                  if ( v22 )
                  {
                    s->rwstate = 3;
                    v23 = EC_KEY_get0_private_key(s);
                    BIO_clear_flags(v23, 15);
                    BIO_set_flags(v23, 9);
                    return -1;
                  }
                }
              }
            }
          }
        }
        else
        {
LABEL_69:
          v26 = s->s3;
          if ( v26->alert_fragment_len < 2 )
          {
            if ( (s->shutdown & 1) != 0 )
            {
              s->rwstate = 1;
              p_rrec->length = 0;
              return 0;
            }
            v32 = p_rrec->type;
            if ( p_rrec->type == 20 )
            {
              if ( p_rrec->length != 1 || p_rrec->off || (data = p_rrec->data, *data != 1) )
              {
                v31 = 47;
                ERR_put_error(0x14u, 148, 103, ".\\ssl\\s3_pkt.c", 1227);
                goto LABEL_143;
              }
              if ( !v26->tmp.new_cipher )
              {
                v43 = 1235;
                v42 = 133;
                goto LABEL_142;
              }
              p_rrec->length = 0;
              v34 = s->msg_callback;
              if ( v34 )
                v34(0, s->version, 20, data, 1u, s, s->msg_callback_arg);
              s->s3->change_cipher_spec = 1;
              if ( !ssl3_do_change_cipher_spec(s) )
                return -1;
            }
            else if ( v26->handshake_fragment_len < 4 || s->in_handshake )
            {
              if ( v32 >= 20 )
              {
                if ( v32 <= 22 )
                {
                  v43 = 1316;
                  v42 = 68;
                  goto LABEL_142;
                }
                if ( v32 == 23 )
                {
                  v40 = s->s3;
                  if ( v40->in_read_app_data && v40->total_renegotiations )
                  {
                    if ( (state = s->state, (state & 0x1000) != 0) && state >= 4368 && state <= 4384
                      || (state & 0x2000) != 0 && state <= 8480 && state >= 8464 )
                    {
                      v40->in_read_app_data = 2;
                      return -1;
                    }
                  }
                  v43 = 1345;
                  goto LABEL_141;
                }
              }
              if ( s->version != 769 )
              {
                v43 = 1307;
LABEL_141:
                v42 = 245;
                goto LABEL_142;
              }
              p_rrec->length = 0;
            }
            else
            {
              if ( (s->state & 0xFFF) == 3 && (v26->flags & 1) == 0 )
              {
                s->state = s->server != 0 ? 0x2000 : 4096;
                s->new_session = 1;
              }
              result = s->handshake_func(s);
              if ( result < 0 )
                return result;
              if ( !result )
              {
                ERR_put_error(0x14u, 148, 229, ".\\ssl\\s3_pkt.c", 1272);
                return -1;
              }
              if ( (s->mode & 4) == 0 )
              {
                v22 = s->s3->rbuf.left == 0;
                goto LABEL_57;
              }
            }
          }
          else
          {
            v27 = v26->alert_fragment[0];
            v28 = v26->alert_fragment[1];
            v26->alert_fragment_len = 0;
            v29 = s->msg_callback;
            if ( v29 )
              v29(0, s->version, 21, s->s3->alert_fragment, 2u, s, s->msg_callback_arg);
            info_callback = s->info_callback;
            if ( info_callback || (info_callback = s->ctx->info_callback) != 0 )
              v44 = info_callback;
            if ( v44 )
              v44(s, 16388, v28 | (v27 << 8));
            if ( v27 != 1 )
            {
              if ( v27 == 2 )
              {
                v37 = s->s3;
                s->rwstate = 1;
                v37->fatal_alert = v28;
                ERR_put_error(0x14u, 148, v28 + 1000, ".\\ssl\\s3_pkt.c", 1195);
                BIO_snprintf(bufa, 0x10u, "%d", v28);
                ERR_add_error_data(2, "SSL alert number ", bufa);
                v38 = s->session;
                ctx = s->ctx;
                s->shutdown |= 2u;
                SSL_CTX_remove_session(ctx, v38);
                return 0;
              }
              v31 = 47;
              ERR_put_error(0x14u, 148, 246, ".\\ssl\\s3_pkt.c", 1205);
              goto LABEL_143;
            }
            s->s3->warn_alert = v28;
            if ( !v28 )
            {
              s->shutdown |= 2u;
              return 0;
            }
            if ( v28 == 100 )
            {
              v31 = 40;
              ERR_put_error(0x14u, 148, 339, ".\\ssl\\s3_pkt.c", 1185);
LABEL_143:
              ssl3_send_alert(s, 2, v31);
              return -1;
            }
          }
        }
      }
    }
  }
  return result;
}
