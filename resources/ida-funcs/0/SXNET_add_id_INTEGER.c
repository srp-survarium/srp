int __cdecl SXNET_add_id_INTEGER(asn1_string_st ***psx, asn1_string_st *zone, const __m128i *user, int userlen)
{
  struct ASN1_VALUE_st *v4; // ebx
  int v5; // edi
  asn1_string_st **v7; // esi
  asn1_string_st **v8; // eax

  v4 = 0;
  if ( psx && zone && user )
  {
    v5 = userlen;
    if ( userlen == -1 )
      v5 = strlen(user->m128i_i8);
    if ( v5 > 64 )
    {
      ERR_put_error(0, 0x22u, 126, 132, ".\\crypto\\x509v3\\v3_sxnet.c", 194);
      return 0;
    }
    v7 = *psx;
    if ( !*psx )
    {
      v8 = (asn1_string_st **)ASN1_item_new(&local_it_74);
      v7 = v8;
      if ( !v8 || !ASN1_INTEGER_set(0, *v8, 0) )
      {
err_97:
        ERR_put_error((int)v4, 0x22u, 126, 65, ".\\crypto\\x509v3\\v3_sxnet.c", 216);
        ASN1_item_free(v4, &local_it_73);
        ASN1_item_free((struct ASN1_VALUE_st *)v7, &local_it_74);
        *psx = 0;
        return 0;
      }
      *psx = v7;
    }
    if ( SXNET_get_id_INTEGER((SXNET_st *)v7, zone) )
    {
      ERR_put_error(0, 0x22u, 126, 133, ".\\crypto\\x509v3\\v3_sxnet.c", 203);
      return 0;
    }
    v4 = ASN1_item_new(&local_it_73);
    if ( !v4 )
      goto err_97;
    if ( v5 == -1 )
      v5 = strlen(user->m128i_i8);
    if ( !ASN1_STRING_set(*((asn1_string_st **)v4 + 1), user, v5) || !sk_push((stack_st *)v7[1], (char *)v4) )
      goto err_97;
    *(_DWORD *)v4 = zone;
    return 1;
  }
  else
  {
    ERR_put_error(0, 0x22u, 126, 107, ".\\crypto\\x509v3\\v3_sxnet.c", 189);
    return 0;
  }
}
