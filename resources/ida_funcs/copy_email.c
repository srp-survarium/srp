int __cdecl copy_email(X509_name_st *ctx, stack_st_GENERAL_NAME *gens, int move_p)
{
  asn1_string_st *v3; // ebx
  GENERAL_NAME_st *v4; // edi
  int index_by_NID; // esi
  ui_string_st *entry; // ebp
  const asn1_string_st *v8; // eax
  X509_name_st *nm; // [esp+14h] [ebp+4h]

  v3 = 0;
  v4 = 0;
  if ( !ctx )
    goto LABEL_19;
  if ( ctx->entries == (stack_st_X509_NAME_ENTRY *)1 )
    return 1;
  if ( !ctx->bytes )
  {
    if ( ctx->canon_enc )
    {
      nm = *(X509_name_st **)(*(_DWORD *)ctx->canon_enc + 16);
      goto LABEL_9;
    }
LABEL_19:
    ERR_put_error(0x22u, 122, 125, ".\\crypto\\x509v3\\v3_alt.c", 353);
    goto LABEL_20;
  }
  nm = X509_get_subject_name((x509_st *)ctx->bytes);
LABEL_9:
  index_by_NID = X509_NAME_get_index_by_NID(nm, 48, -1);
  if ( index_by_NID < 0 )
    return 1;
  while ( 1 )
  {
    entry = (ui_string_st *)X509_NAME_get_entry(nm, index_by_NID);
    v8 = (const asn1_string_st *)UI_get0_output_string(entry);
    v3 = ASN1_STRING_dup(v8);
    if ( move_p )
    {
      X509_NAME_delete_entry(nm, index_by_NID);
      X509_NAME_ENTRY_free((X509_name_entry_st *)entry);
      --index_by_NID;
    }
    if ( !v3 )
      break;
    v4 = GENERAL_NAME_new();
    if ( !v4 )
      break;
    v4->d.ptr = (char *)v3;
    v3 = 0;
    v4->type = 1;
    if ( !sk_push(&gens->stack, (char *)v4) )
    {
      ERR_put_error(0x22u, 122, 65, ".\\crypto\\x509v3\\v3_alt.c", 380);
      goto LABEL_20;
    }
    v4 = 0;
    index_by_NID = X509_NAME_get_index_by_NID(nm, 48, index_by_NID);
    if ( index_by_NID < 0 )
      return 1;
  }
  ERR_put_error(0x22u, 122, 65, ".\\crypto\\x509v3\\v3_alt.c", 373);
LABEL_20:
  GENERAL_NAME_free(v4);
  ASN1_STRING_free(v3);
  return 0;
}
