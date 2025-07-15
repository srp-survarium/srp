int __cdecl PEM_def_callback(char *buf, int num, int w, const __m128i *key)
{
  signed int v4; // esi
  int result; // eax
  char *pw_prompt; // edi
  _iobuf *v7; // eax

  if ( key )
  {
    v4 = strlen(key->m128i_i8);
    if ( v4 > num )
      v4 = num;
    memcpy((int)buf, key, v4);
    return v4;
  }
  else
  {
    pw_prompt = EVP_get_pw_prompt();
    if ( !pw_prompt )
      pw_prompt = "Enter PEM pass phrase:";
    if ( EVP_read_pw_string_min(buf, 4, num, pw_prompt, w) )
    {
LABEL_10:
      ERR_put_error(num, 9u, 100, 109, ".\\crypto\\pem\\pem_lib.c", 111);
      memset((int)buf, 0, num);
      return -1;
    }
    else
    {
      while ( 1 )
      {
        result = strlen(buf);
        if ( result >= 4 )
          break;
        v7 = __iob_func();
        fprintf((int)pw_prompt, v7 + 2, "phrase is too short, needs to be at least %d chars\n", 4);
        if ( EVP_read_pw_string_min(buf, 4, num, pw_prompt, w) )
          goto LABEL_10;
      }
    }
  }
  return result;
}
