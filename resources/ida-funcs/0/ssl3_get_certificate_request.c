int __cdecl ssl3_get_certificate_request(ssl_st *s)
{
  int (__cdecl *ssl_get_message)(ssl_st *, int, int, int, int, int *); // eax
  int result; // eax
  int v4; // edi
  ssl3_state_st *s3; // edx
  unsigned __int8 *init_msg; // esi
  unsigned int v7; // ecx
  unsigned __int8 *v8; // esi
  unsigned int i; // eax
  unsigned int v10; // ebx
  unsigned __int8 *v11; // esi
  unsigned int v12; // eax
  const unsigned __int8 *v13; // edi
  unsigned __int8 *v14; // esi
  char *v15; // eax
  ssl3_state_st *v16; // ecx
  ssl3_state_st *v17; // ecx
  int max_cert_list; // [esp-8h] [ebp-28h]
  stack_st *st; // [esp+Ch] [ebp-14h]
  unsigned __int8 *v20; // [esp+10h] [ebp-10h] BYREF
  int v21; // [esp+14h] [ebp-Ch]
  int v22; // [esp+18h] [ebp-8h] BYREF
  unsigned int v23; // [esp+1Ch] [ebp-4h]
  int sa; // [esp+24h] [ebp+4h]

  ssl_get_message = s->method->ssl_get_message;
  max_cert_list = s->max_cert_list;
  v21 = 0;
  result = ssl_get_message(s, 4432, 4433, -1, max_cert_list, &v22);
  v4 = result;
  if ( v22 )
  {
    s->s3->tmp.cert_req = 0;
    s3 = s->s3;
    if ( s3->tmp.message_type == 14 )
    {
      result = 1;
      s3->tmp.reuse_message = 1;
    }
    else if ( s3->tmp.message_type == 13 )
    {
      if ( s->version > 768 && (s3->tmp.new_cipher->algorithm_auth & 4) != 0 )
      {
        ssl3_send_alert(s, 2, 10);
        ERR_put_error(0, 0x14u, 135, 232, ".\\ssl\\s3_clnt.c", 1702);
        return v21;
      }
      else
      {
        init_msg = (unsigned __int8 *)s->init_msg;
        st = sk_new((int (__cdecl *)(const void *, const void *))ca_dn_cmp);
        if ( st )
        {
          v7 = *init_msg;
          v8 = init_msg + 1;
          sa = v7;
          if ( v7 > 9 )
          {
            sa = 9;
            v7 = 9;
          }
          for ( i = 0; i < v7; ++i )
            s->s3->tmp.ctype[i] = v8[i];
          v10 = v8[v7 + 1] | (v8[v7] << 8);
          v11 = &v8[v7 + 2];
          if ( v10 + v7 + 3 != v4 )
          {
            ssl3_send_alert(s, 2, 50);
            ERR_put_error(v10, 0x14u, 135, 159, ".\\ssl\\s3_clnt.c", 1737);
            goto err_225;
          }
          v12 = 0;
          if ( v10 )
          {
            while ( 1 )
            {
              v13 = (const unsigned __int8 *)(v11[1] | (*v11 << 8));
              v14 = v11 + 2;
              v23 = (unsigned int)&v13[v12 + 2];
              if ( v23 > v10 )
                break;
              v20 = v14;
              v15 = (char *)d2i_X509_NAME(0, &v20, v13);
              if ( !v15 )
              {
                if ( (s->options & 0x20000000) == 0 )
                {
                  ssl3_send_alert(s, 2, 50);
                  ERR_put_error(v10, 0x14u, 135, 13, ".\\ssl\\s3_clnt.c", 1763);
                  goto err_225;
                }
cont:
                ERR_clear_error(v10);
LABEL_28:
                v7 = sa;
                goto LABEL_29;
              }
              v11 = &v14[(_DWORD)v13];
              if ( v20 != v11 )
              {
                ssl3_send_alert(s, 2, 50);
                ERR_put_error(v10, 0x14u, 135, 131, ".\\ssl\\s3_clnt.c", 1771);
                goto err_225;
              }
              if ( !sk_push(st, v15) )
              {
                ERR_put_error(v10, 0x14u, 135, 65, ".\\ssl\\s3_clnt.c", 1776);
                goto err_225;
              }
              v12 = v23;
              if ( v23 >= v10 )
                goto LABEL_28;
            }
            if ( (s->options & 0x20000000) == 0 )
            {
              ssl3_send_alert(s, 2, 50);
              ERR_put_error(v10, 0x14u, 135, 132, ".\\ssl\\s3_clnt.c", 1749);
              goto err_225;
            }
            goto cont;
          }
LABEL_29:
          s->s3->tmp.cert_req = 1;
          s->s3->tmp.ctype_num = v7;
          v16 = s->s3;
          if ( v16->tmp.ca_names )
            sk_pop_free(&v16->tmp.ca_names->stack, (void (__cdecl *)(void *))X509_NAME_free);
          v17 = s->s3;
          v21 = 1;
          result = 1;
          v17->tmp.ca_names = (stack_st_X509_NAME *)st;
        }
        else
        {
          ERR_put_error(0, 0x14u, 135, 65, ".\\ssl\\s3_clnt.c", 1711);
err_225:
          if ( st )
            sk_pop_free(st, (void (__cdecl *)(void *))X509_NAME_free);
          return v21;
        }
      }
    }
    else
    {
      ssl3_send_alert(s, 2, 10);
      ERR_put_error(0, 0x14u, 135, 262, ".\\ssl\\s3_clnt.c", 1692);
      return v21;
    }
  }
  return result;
}
