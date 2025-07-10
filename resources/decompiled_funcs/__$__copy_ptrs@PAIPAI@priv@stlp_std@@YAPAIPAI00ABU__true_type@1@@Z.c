unsigned __int8 *__usercall stlp_std::priv::__copy_ptrs<unsigned int *,unsigned int *>@<eax>(
        char *__last@<ecx>,
        unsigned __int8 *__result@<eax>,
        unsigned int *__first)
{
  unsigned int v3; // ecx
  unsigned int v4; // esi
  int v5; // eax

  v3 = __last - (char *)__first;
  v4 = v3;
  if ( v3 )
  {
    memmove(__result, (unsigned __int8 *)__first, v3);
    return (unsigned __int8 *)(v4 + v5);
  }
  return __result;
}
