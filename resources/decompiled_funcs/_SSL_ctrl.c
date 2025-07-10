int __cdecl SSL_ctrl(ssl_st *s, int cmd, int larg, void *parg)
{
  int result; // eax
  ssl3_state_st *s3; // eax

  switch ( cmd )
  {
    case 16:
      s->msg_callback_arg = parg;
      result = 1;
      break;
    case 17:
      if ( larg < (int)dtls1_min_mtu() || s->version != 65279 && s->version != 256 )
        goto LABEL_12;
      s->d1->mtu = larg;
      result = larg;
      break;
    case 32:
      s->options |= larg;
      result = s->options;
      break;
    case 33:
      s->mode |= larg;
      result = s->mode;
      break;
    case 40:
      result = s->read_ahead;
      break;
    case 41:
      result = s->read_ahead;
      s->read_ahead = larg;
      break;
    case 50:
      result = s->max_cert_list;
      break;
    case 51:
      result = s->max_cert_list;
      s->max_cert_list = larg;
      break;
    case 52:
      if ( (unsigned int)(larg - 512) > 0x3E00 )
        goto LABEL_12;
      s->max_send_fragment = larg;
      result = 1;
      break;
    case 76:
      s3 = s->s3;
      if ( s3 )
        result = s3->send_connection_binding;
      else
LABEL_12:
        result = 0;
      break;
    case 77:
      s->options &= ~larg;
      result = s->options;
      break;
    case 78:
      s->mode &= ~larg;
      result = s->mode;
      break;
    default:
      result = s->method->ssl_ctrl(s, cmd, larg, parg);
      break;
  }
  return result;
}
