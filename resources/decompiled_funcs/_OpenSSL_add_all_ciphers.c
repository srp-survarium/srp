int OpenSSL_add_all_ciphers()
{
  const evp_cipher_st *v0; // eax
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
  const evp_cipher_st *v13; // eax
  const evp_cipher_st *v14; // eax
  const evp_cipher_st *v15; // eax
  const evp_cipher_st *v16; // eax
  const evp_cipher_st *v17; // eax
  const evp_cipher_st *v18; // eax
  const evp_cipher_st *v19; // eax
  const evp_cipher_st *v20; // eax
  const evp_cipher_st *v21; // eax
  const evp_cipher_st *v22; // eax
  const evp_cipher_st *v23; // eax
  const evp_cipher_st *v24; // eax
  const evp_cipher_st *v25; // eax
  const evp_cipher_st *v26; // eax
  const evp_cipher_st *v27; // eax
  const evp_cipher_st *v28; // eax
  const evp_cipher_st *v29; // eax
  const evp_cipher_st *v30; // eax
  const evp_cipher_st *v31; // eax
  const evp_cipher_st *v32; // eax
  const evp_cipher_st *v33; // eax
  const evp_cipher_st *v34; // eax
  const evp_cipher_st *v35; // eax
  const evp_cipher_st *v36; // eax
  const evp_cipher_st *v37; // eax
  const evp_cipher_st *v38; // eax
  const evp_cipher_st *v39; // eax
  const evp_cipher_st *v40; // eax
  const evp_cipher_st *v41; // eax
  const evp_cipher_st *v42; // eax
  const evp_cipher_st *v43; // eax
  const evp_cipher_st *v44; // eax
  const evp_cipher_st *v45; // eax
  const evp_cipher_st *v46; // eax
  const evp_cipher_st *v47; // eax
  const evp_cipher_st *v48; // eax
  const evp_cipher_st *v49; // eax
  const evp_cipher_st *v50; // eax
  const evp_cipher_st *v51; // eax
  const evp_cipher_st *v52; // eax
  const evp_cipher_st *v53; // eax
  const evp_cipher_st *v54; // eax
  const evp_cipher_st *v55; // eax
  const evp_cipher_st *v56; // eax
  const evp_cipher_st *v57; // eax
  const evp_cipher_st *v58; // eax
  const evp_cipher_st *v59; // eax
  const evp_cipher_st *v60; // eax
  const evp_cipher_st *v61; // eax
  const evp_cipher_st *v62; // eax
  const evp_cipher_st *v63; // eax
  const evp_cipher_st *v64; // eax
  const evp_cipher_st *v65; // eax
  const evp_cipher_st *v66; // eax
  const evp_cipher_st *v67; // eax
  const evp_cipher_st *v68; // eax
  const evp_cipher_st *v69; // eax
  const evp_cipher_st *v70; // eax
  const evp_cipher_st *v71; // eax
  const evp_cipher_st *v72; // eax
  const evp_cipher_st *v73; // eax
  const evp_cipher_st *v74; // eax
  const evp_cipher_st *v75; // eax
  const evp_cipher_st *v76; // eax

  v0 = EVP_des_cfb64();
  EVP_add_cipher(v0);
  v1 = EVP_des_cfb1();
  EVP_add_cipher(v1);
  v2 = EVP_des_cfb8();
  EVP_add_cipher(v2);
  v3 = EVP_des_ede_cfb64();
  EVP_add_cipher(v3);
  v4 = EVP_des_ede3_cfb64();
  EVP_add_cipher(v4);
  v5 = EVP_des_ede3_cfb1();
  EVP_add_cipher(v5);
  v6 = EVP_des_ede3_cfb8();
  EVP_add_cipher(v6);
  v7 = EVP_des_ofb();
  EVP_add_cipher(v7);
  v8 = EVP_des_ede_ofb();
  EVP_add_cipher(v8);
  v9 = EVP_des_ede3_ofb();
  EVP_add_cipher(v9);
  v10 = EVP_desx_cbc();
  EVP_add_cipher(v10);
  OBJ_NAME_add("DESX", 32770, "DESX-CBC");
  OBJ_NAME_add("desx", 32770, "DESX-CBC");
  v11 = EVP_des_cbc();
  EVP_add_cipher(v11);
  OBJ_NAME_add("DES", 32770, "DES-CBC");
  OBJ_NAME_add("des", 32770, "DES-CBC");
  v12 = EVP_des_ede_cbc();
  EVP_add_cipher(v12);
  v13 = EVP_des_ede3_cbc();
  EVP_add_cipher(v13);
  OBJ_NAME_add("DES3", 32770, "DES-EDE3-CBC");
  OBJ_NAME_add("des3", 32770, "DES-EDE3-CBC");
  v14 = EVP_des_ecb();
  EVP_add_cipher(v14);
  v15 = EVP_des_ede();
  EVP_add_cipher(v15);
  v16 = EVP_des_ede3();
  EVP_add_cipher(v16);
  v17 = EVP_rc4();
  EVP_add_cipher(v17);
  v18 = EVP_rc4_40();
  EVP_add_cipher(v18);
  v19 = EVP_idea_ecb();
  EVP_add_cipher(v19);
  v20 = EVP_idea_cfb64();
  EVP_add_cipher(v20);
  v21 = EVP_idea_ofb();
  EVP_add_cipher(v21);
  v22 = EVP_idea_cbc();
  EVP_add_cipher(v22);
  OBJ_NAME_add("IDEA", 32770, "IDEA-CBC");
  OBJ_NAME_add("idea", 32770, "IDEA-CBC");
  v23 = EVP_seed_ecb();
  EVP_add_cipher(v23);
  v24 = EVP_seed_cfb128();
  EVP_add_cipher(v24);
  v25 = EVP_seed_ofb();
  EVP_add_cipher(v25);
  v26 = EVP_seed_cbc();
  EVP_add_cipher(v26);
  OBJ_NAME_add("SEED", 32770, "SEED-CBC");
  OBJ_NAME_add("seed", 32770, "SEED-CBC");
  v27 = EVP_rc2_ecb();
  EVP_add_cipher(v27);
  v28 = EVP_rc2_cfb64();
  EVP_add_cipher(v28);
  v29 = EVP_rc2_ofb();
  EVP_add_cipher(v29);
  v30 = EVP_rc2_cbc();
  EVP_add_cipher(v30);
  v31 = EVP_rc2_40_cbc();
  EVP_add_cipher(v31);
  v32 = EVP_rc2_64_cbc();
  EVP_add_cipher(v32);
  OBJ_NAME_add("RC2", 32770, "RC2-CBC");
  OBJ_NAME_add("rc2", 32770, "RC2-CBC");
  v33 = EVP_bf_ecb();
  EVP_add_cipher(v33);
  v34 = EVP_bf_cfb64();
  EVP_add_cipher(v34);
  v35 = EVP_bf_ofb();
  EVP_add_cipher(v35);
  v36 = EVP_bf_cbc();
  EVP_add_cipher(v36);
  OBJ_NAME_add("BF", 32770, "BF-CBC");
  OBJ_NAME_add("bf", 32770, "BF-CBC");
  OBJ_NAME_add("blowfish", 32770, "BF-CBC");
  v37 = EVP_cast5_ecb();
  EVP_add_cipher(v37);
  v38 = EVP_cast5_cfb64();
  EVP_add_cipher(v38);
  v39 = EVP_cast5_ofb();
  EVP_add_cipher(v39);
  v40 = EVP_cast5_cbc();
  EVP_add_cipher(v40);
  OBJ_NAME_add("CAST", 32770, "CAST5-CBC");
  OBJ_NAME_add("cast", 32770, "CAST5-CBC");
  OBJ_NAME_add("CAST-cbc", 32770, "CAST5-CBC");
  OBJ_NAME_add("cast-cbc", 32770, "CAST5-CBC");
  v41 = EVP_aes_128_ecb();
  EVP_add_cipher(v41);
  v42 = EVP_aes_128_cbc();
  EVP_add_cipher(v42);
  v43 = EVP_aes_128_cfb128();
  EVP_add_cipher(v43);
  v44 = EVP_aes_128_cfb1();
  EVP_add_cipher(v44);
  v45 = EVP_aes_128_cfb8();
  EVP_add_cipher(v45);
  v46 = EVP_aes_128_ofb();
  EVP_add_cipher(v46);
  OBJ_NAME_add("AES128", 32770, "AES-128-CBC");
  OBJ_NAME_add("aes128", 32770, "AES-128-CBC");
  v47 = EVP_aes_192_ecb();
  EVP_add_cipher(v47);
  v48 = EVP_aes_192_cbc();
  EVP_add_cipher(v48);
  v49 = EVP_aes_192_cfb128();
  EVP_add_cipher(v49);
  v50 = EVP_aes_192_cfb1();
  EVP_add_cipher(v50);
  v51 = EVP_aes_192_cfb8();
  EVP_add_cipher(v51);
  v52 = EVP_aes_192_ofb();
  EVP_add_cipher(v52);
  OBJ_NAME_add("AES192", 32770, "AES-192-CBC");
  OBJ_NAME_add("aes192", 32770, "AES-192-CBC");
  v53 = EVP_aes_256_ecb();
  EVP_add_cipher(v53);
  v54 = EVP_aes_256_cbc();
  EVP_add_cipher(v54);
  v55 = EVP_aes_256_cfb128();
  EVP_add_cipher(v55);
  v56 = EVP_aes_256_cfb1();
  EVP_add_cipher(v56);
  v57 = EVP_aes_256_cfb8();
  EVP_add_cipher(v57);
  v58 = EVP_aes_256_ofb();
  EVP_add_cipher(v58);
  OBJ_NAME_add("AES256", 32770, "AES-256-CBC");
  OBJ_NAME_add("aes256", 32770, "AES-256-CBC");
  v59 = EVP_camellia_128_ecb();
  EVP_add_cipher(v59);
  v60 = EVP_camellia_128_cbc();
  EVP_add_cipher(v60);
  v61 = EVP_camellia_128_cfb128();
  EVP_add_cipher(v61);
  v62 = EVP_camellia_128_cfb1();
  EVP_add_cipher(v62);
  v63 = EVP_camellia_128_cfb8();
  EVP_add_cipher(v63);
  v64 = EVP_camellia_128_ofb();
  EVP_add_cipher(v64);
  OBJ_NAME_add("CAMELLIA128", 32770, "CAMELLIA-128-CBC");
  OBJ_NAME_add("camellia128", 32770, "CAMELLIA-128-CBC");
  v65 = EVP_camellia_192_ecb();
  EVP_add_cipher(v65);
  v66 = EVP_camellia_192_cbc();
  EVP_add_cipher(v66);
  v67 = EVP_camellia_192_cfb128();
  EVP_add_cipher(v67);
  v68 = EVP_camellia_192_cfb1();
  EVP_add_cipher(v68);
  v69 = EVP_camellia_192_cfb8();
  EVP_add_cipher(v69);
  v70 = EVP_camellia_192_ofb();
  EVP_add_cipher(v70);
  OBJ_NAME_add("CAMELLIA192", 32770, "CAMELLIA-192-CBC");
  OBJ_NAME_add("camellia192", 32770, "CAMELLIA-192-CBC");
  v71 = EVP_camellia_256_ecb();
  EVP_add_cipher(v71);
  v72 = EVP_camellia_256_cbc();
  EVP_add_cipher(v72);
  v73 = EVP_camellia_256_cfb128();
  EVP_add_cipher(v73);
  v74 = EVP_camellia_256_cfb1();
  EVP_add_cipher(v74);
  v75 = EVP_camellia_256_cfb8();
  EVP_add_cipher(v75);
  v76 = EVP_camellia_256_ofb();
  EVP_add_cipher(v76);
  OBJ_NAME_add("CAMELLIA256", 32770, "CAMELLIA-256-CBC");
  return OBJ_NAME_add("camellia256", 32770, "CAMELLIA-256-CBC");
}
