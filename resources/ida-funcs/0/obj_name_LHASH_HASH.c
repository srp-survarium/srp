unsigned int __cdecl obj_name_LHASH_HASH(const char **arg)
{
  int v1; // edi
  char *v2; // eax

  if ( !name_funcs_stack )
    return lh_strhash(arg[2]) ^ (unsigned int)*arg;
  v1 = (int)*arg;
  if ( sk_num(&name_funcs_stack->stack) <= v1 )
    return lh_strhash(arg[2]) ^ (unsigned int)*arg;
  v2 = sk_value(&name_funcs_stack->stack, v1);
  return (*(int (__cdecl **)(const char *))v2)(arg[2]) ^ (unsigned int)*arg;
}
