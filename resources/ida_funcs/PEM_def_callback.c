int __cdecl PEM_def_callback(char *buf, int num, int w, char *key)
{
  signed int v4; // esi
  int result; // eax
  const char *pw_prompt; // edi
  _iobuf *v7; // eax

  if ( key )
  {
    v4 = strlen(key);
    if ( v4 > num )
      v4 = num;
    memcpy((unsigned __int8 *)buf, (unsigned __int8 *)key, v4);
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
      ERR_put_error(9u, 100, 109, ".\\crypto\\pem\\pem_lib.c", 111);
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
        fprintf(v7 + 2, "phrase is too short, needs to be at least %d chars\n", 4);
        if ( EVP_read_pw_string_min(buf, 4, num, pw_prompt, w) )
          goto LABEL_10;
      }
    }
  }
  return result;
}
