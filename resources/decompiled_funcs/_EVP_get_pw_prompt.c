char *__cdecl EVP_get_pw_prompt()
{
  return prompt_string[0] != 0 ? prompt_string : 0;
}
