BOOL __usercall do_pkcs7_signed_attrib@<eax>(pkcs7_signer_info_st *si@<esi>, env_md_ctx_st *mctx@<edi>)
{
  int v2; // ebx
  int v4; // [esp+0h] [ebp-4Ch]
  int mdlen; // [esp+4h] [ebp-48h] BYREF
  unsigned __int8 md[64]; // [esp+8h] [ebp-44h] BYREF

  v2 = v4;
  if ( !get_attribute(si->auth_attr, 0x34u) && !PKCS7_add0_attrib_signing_time(si, 0) )
  {
    ERR_put_error(v2, 0x21u, 136, 65, ".\\crypto\\pkcs7\\pk7_doit.c", 673);
    return 0;
  }
  EVP_DigestFinal_ex((int)mctx, v2, mctx, md, (unsigned int *)&mdlen);
  if ( !PKCS7_add1_attrib_digest(si, md, mdlen) )
  {
    ERR_put_error(v2, 0x21u, 136, 65, ".\\crypto\\pkcs7\\pk7_doit.c", 682);
    return 0;
  }
  return PKCS7_SIGNER_INFO_sign(v2, si) != 0;
}
