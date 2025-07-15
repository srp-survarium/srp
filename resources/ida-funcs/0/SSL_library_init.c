int __usercall SSL_library_init@<eax>(unsigned int a1@<edi>)
{
  const evp_cipher_st *v1; // eax
  const evp_cipher_st *v2; // eax
  const evp_cipher_st *v3; // eax
  const evp_cipher_st *v4; // eax
  const evp_cipher_st *v5; // eax
  const evp_cipher_st *v6; // eax
  const evp_cipher_st *v7; // eax
  const evp_cipher_st *v8; // eax
  const evp_cipher_st *v9; // eax
  const evp_cipher_st *v10; // eax
  const evp_cipher_st *v11; // eax
  const evp_cipher_st *v12; // eax
  const env_md_st *v13; // eax
  const env_md_st *v14; // eax
  const env_md_st *v15; // eax
  const env_md_st *v16; // eax
  const env_md_st *v17; // eax
  const env_md_st *v18; // eax
  const env_md_st *v19; // eax
  const env_md_st *v20; // eax

  v1 = EVP_des_cbc();
  EVP_add_cipher(v1);
  v2 = EVP_des_ede3_cbc();
  EVP_add_cipher(v2);
  v3 = EVP_idea_cbc();
  EVP_add_cipher(v3);
  v4 = EVP_rc4();
  EVP_add_cipher(v4);
  v5 = EVP_rc2_cbc();
  EVP_add_cipher(v5);
  v6 = EVP_rc2_40_cbc();
  EVP_add_cipher(v6);
  v7 = EVP_aes_128_cbc();
  EVP_add_cipher(v7);
  v8 = EVP_aes_192_cbc();
  EVP_add_cipher(v8);
  v9 = EVP_aes_256_cbc();
  EVP_add_cipher(v9);
  v10 = EVP_camellia_128_cbc();
  EVP_add_cipher(v10);
  v11 = EVP_camellia_256_cbc();
  EVP_add_cipher(v11);
  v12 = EVP_seed_cbc();
  EVP_add_cipher(v12);
  v13 = EVP_md5();
  EVP_add_digest(v13);
  OBJ_NAME_add(a1, "ssl2-md5", 32769, "MD5");
  OBJ_NAME_add(a1, "ssl3-md5", 32769, "MD5");
  v14 = EVP_sha1();
  EVP_add_digest(v14);
  OBJ_NAME_add(a1, "ssl3-sha1", 32769, "SHA1");
  OBJ_NAME_add(a1, "RSA-SHA1-2", 32769, "RSA-SHA1");
  v15 = EVP_sha224();
  EVP_add_digest(v15);
  v16 = EVP_sha256();
  EVP_add_digest(v16);
  v17 = EVP_sha384();
  EVP_add_digest(v17);
  v18 = EVP_sha512();
  EVP_add_digest(v18);
  v19 = EVP_dss1();
  EVP_add_digest(v19);
  OBJ_NAME_add(a1, "DSA-SHA1-old", 32769, "DSA-SHA1");
  OBJ_NAME_add(a1, "DSS1", 32769, "DSA-SHA1");
  OBJ_NAME_add(a1, "dss1", 32769, "DSA-SHA1");
  v20 = EVP_ecdsa();
  EVP_add_digest(v20);
  SSL_COMP_get_compression_methods();
  ssl_load_ciphers();
  return 1;
}
