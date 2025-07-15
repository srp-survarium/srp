int __cdecl obj_name_LHASH_HASH(const char **arg)
{
  const char *v1; // edi
  char *v2; // eax

  if ( !name_funcs_stack )
    return lh_strhash(arg[2]) ^ (unsigned int)*arg;
  v1 = *arg;
  if ( sk_num(&name_funcs_stack->stack) <= (int)v1 )
    return lh_strhash(arg[2]) ^ (unsigned int)*arg;
  v2 = sk_value(&name_funcs_stack->stack, (int)v1);
  return (*(int (__cdecl **)(const char *))v2)(arg[2]) ^ (unsigned int)*arg;
}
