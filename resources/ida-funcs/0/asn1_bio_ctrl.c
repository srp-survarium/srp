int __cdecl asn1_bio_ctrl(bio_st *b, int cmd, int arg1, void **arg2)
{
  BIO_ASN1_BUF_CTX_t *ptr; // esi
  int result; // eax
  bio_st *next_bio; // edi

  ptr = (BIO_ASN1_BUF_CTX_t *)b->ptr;
  if ( !ptr )
    return 0;
  switch ( cmd )
  {
    case 11:
      if ( !b->next_bio
        || ptr->state == ASN1_STATE_HEADER
        && !asn1_bio_setup_ex(b, ptr, ptr->suffix, ASN1_STATE_POST_COPY, ASN1_STATE_DONE) )
      {
        goto LABEL_18;
      }
      if ( ptr->state != ASN1_STATE_POST_COPY
        || (result = asn1_bio_flush_ex(ptr, b, ptr->suffix_free, ASN1_STATE_DONE), result > 0) )
      {
        if ( ptr->state != ASN1_STATE_DONE )
        {
          BIO_clear_flags(b, 15);
          goto LABEL_18;
        }
        result = BIO_ctrl(b->next_bio, cmd, arg1, arg2);
      }
      break;
    case 149:
      ptr->prefix = (int (__cdecl *)(bio_st *, unsigned __int8 **, int *, void *))*arg2;
      ptr->prefix_free = (int (__cdecl *)(bio_st *, unsigned __int8 **, int *, void *))arg2[1];
      result = 1;
      break;
    case 150:
      *arg2 = ptr->prefix;
      arg2[1] = ptr->prefix_free;
      result = 1;
      break;
    case 151:
      ptr->suffix = (int (__cdecl *)(bio_st *, unsigned __int8 **, int *, void *))*arg2;
      ptr->suffix_free = (int (__cdecl *)(bio_st *, unsigned __int8 **, int *, void *))arg2[1];
      result = 1;
      break;
    case 152:
      *arg2 = ptr->suffix;
      arg2[1] = ptr->suffix_free;
      result = 1;
      break;
    case 153:
      ptr->ex_arg = arg2;
      result = 1;
      break;
    case 154:
      *arg2 = ptr->ex_arg;
      result = 1;
      break;
    default:
      next_bio = b->next_bio;
      if ( next_bio )
        result = BIO_ctrl(next_bio, cmd, arg1, arg2);
      else
LABEL_18:
        result = 0;
      break;
  }
  return result;
}
