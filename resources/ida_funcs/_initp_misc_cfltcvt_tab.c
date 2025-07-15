void (__cdecl *_initp_misc_cfltcvt_tab())()
{
  unsigned int i; // edi
  void (__cdecl **v1)(); // esi
  void (__cdecl *result)(); // eax

  for ( i = 0; i < 10; ++i )
  {
    v1 = &_cfltcvt_tab[i];
    result = (void (__cdecl *)())_encode_pointer(_cfltcvt_tab[i]);
    *v1 = result;
  }
  return result;
}
