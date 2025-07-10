int __cdecl SSL_CTX_ctrl(ssl_ctx_st *ctx, int cmd, int larg, void *parg)
{
  int result; // eax

  switch ( cmd )
  {
    case 16:
      ctx->msg_callback_arg = parg;
      result = 1;
      break;
    case 20:
      result = lh_num_items((const lhash_st *)ctx->sessions);
      break;
    case 21:
      result = ctx->stats.sess_connect;
      break;
    case 22:
      result = ctx->stats.sess_connect_good;
      break;
    case 23:
      result = ctx->stats.sess_connect_renegotiate;
      break;
    case 24:
      result = ctx->stats.sess_accept;
      break;
    case 25:
      result = ctx->stats.sess_accept_good;
      break;
    case 26:
      result = ctx->stats.sess_accept_renegotiate;
      break;
    case 27:
      result = ctx->stats.sess_hit;
      break;
    case 28:
      result = ctx->stats.sess_cb_hit;
      break;
    case 29:
      result = ctx->stats.sess_miss;
      break;
    case 30:
      result = ctx->stats.sess_timeout;
      break;
    case 31:
      result = ctx->stats.sess_cache_full;
      break;
    case 32:
      ctx->options |= larg;
      result = ctx->options;
      break;
    case 33:
      ctx->mode |= larg;
      result = ctx->mode;
      break;
    case 40:
      result = ctx->read_ahead;
      break;
    case 41:
      result = ctx->read_ahead;
      ctx->read_ahead = larg;
      break;
    case 42:
      result = ctx->session_cache_size;
      ctx->session_cache_size = larg;
      break;
    case 43:
      result = ctx->session_cache_size;
      break;
    case 44:
      result = ctx->session_cache_mode;
      ctx->session_cache_mode = larg;
      break;
    case 45:
      result = ctx->session_cache_mode;
      break;
    case 50:
      result = ctx->max_cert_list;
      break;
    case 51:
      result = ctx->max_cert_list;
      ctx->max_cert_list = larg;
      break;
    case 52:
      if ( (unsigned int)(larg - 512) > 0x3E00 )
      {
        result = 0;
      }
      else
      {
        ctx->max_send_fragment = larg;
        result = 1;
      }
      break;
    case 77:
      ctx->options &= ~larg;
      result = ctx->options;
      break;
    case 78:
      ctx->mode &= ~larg;
      result = ctx->mode;
      break;
    default:
      result = ctx->method->ssl_ctx_ctrl(ctx, cmd, larg, parg);
      break;
  }
  return result;
}
