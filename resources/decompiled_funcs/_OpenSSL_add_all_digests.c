int OpenSSL_add_all_digests()
{
  const env_md_st *v0; // eax
  const env_md_st *v1; // eax
  const env_md_st *v2; // eax
  const env_md_st *v3; // eax
  const env_md_st *v4; // eax
  const env_md_st *v5; // eax
  const env_md_st *v6; // eax
  const env_md_st *v7; // eax
  const env_md_st *v8; // eax
  const env_md_st *v9; // eax
  const env_md_st *v10; // eax
  const env_md_st *v11; // eax
  const env_md_st *v12; // eax
  const env_md_st *v13; // eax

  v0 = EVP_md4();
  EVP_add_digest(v0);
  v1 = EVP_md5();
  EVP_add_digest(v1);
  OBJ_NAME_add("ssl2-md5", 32769, "MD5");
  OBJ_NAME_add("ssl3-md5", 32769, "MD5");
  v2 = EVP_sha();
  EVP_add_digest(v2);
  v3 = EVP_dss();
  EVP_add_digest(v3);
  v4 = EVP_sha1();
  EVP_add_digest(v4);
  OBJ_NAME_add("ssl3-sha1", 32769, "SHA1");
  OBJ_NAME_add("RSA-SHA1-2", 32769, "RSA-SHA1");
  v5 = EVP_dss1();
  EVP_add_digest(v5);
  OBJ_NAME_add("DSA-SHA1-old", 32769, "DSA-SHA1");
  OBJ_NAME_add("DSS1", 32769, "DSA-SHA1");
  OBJ_NAME_add("dss1", 32769, "DSA-SHA1");
  v6 = EVP_ecdsa();
  EVP_add_digest(v6);
  v7 = EVP_mdc2();
  EVP_add_digest(v7);
  v8 = EVP_ripemd160();
  EVP_add_digest(v8);
  OBJ_NAME_add("ripemd", 32769, "RIPEMD160");
  OBJ_NAME_add("rmd160", 32769, "RIPEMD160");
  v9 = EVP_sha224();
  EVP_add_digest(v9);
  v10 = EVP_sha256();
  EVP_add_digest(v10);
  v11 = EVP_sha384();
  EVP_add_digest(v11);
  v12 = EVP_sha512();
  EVP_add_digest(v12);
  v13 = EVP_whirlpool();
  return EVP_add_digest(v13);
}
