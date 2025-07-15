BOOL __usercall OBJ_NAME_init@<eax>(int a1@<edi>, int a2@<ebx>)
{
  if ( names_lh )
    return 1;
  CRYPTO_mem_ctrl(a1, a2, 3);
  names_lh = (lhash_st_OBJ_NAME *)lh_new(
                                    (unsigned int (__cdecl *)(const char *))obj_name_LHASH_HASH,
                                    (void (__cdecl *)(unsigned __int8 *, unsigned __int8 *))obj_name_LHASH_COMP);
  CRYPTO_mem_ctrl(a1, a2, 2);
  return names_lh != 0;
}
