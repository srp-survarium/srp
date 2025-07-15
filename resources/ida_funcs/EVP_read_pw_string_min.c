int __cdecl EVP_read_pw_string_min(char *buf, int min, int len, char *prompt, int verify)
{
  const char *v5; // edi
  ui_st *v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // edi
  char v11[512]; // [esp+10h] [ebp-204h] BYREF

  v5 = prompt;
  if ( !prompt && prompt_string[0] )
    v5 = prompt_string;
  v6 = UI_new();
  v7 = len;
  if ( len >= 512 )
    v7 = 511;
  UI_add_input_string(v6, v5, 0, buf, min, v7);
  if ( verify )
  {
    v8 = len;
    if ( len >= 512 )
      v8 = 511;
    UI_add_verify_string(v6, v5, 0, v11, min, v8, buf);
  }
  v9 = UI_process(v6);
  UI_free(v6);
  OPENSSL_cleanse(v11, 512);
  return v9;
}
