void *__cdecl default_realloc_ex(void *str, unsigned int num)
{
  return realloc_func(str, num);
}
