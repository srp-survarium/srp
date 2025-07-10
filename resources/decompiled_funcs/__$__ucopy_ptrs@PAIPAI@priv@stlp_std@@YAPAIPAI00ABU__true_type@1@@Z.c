unsigned __int8 *__usercall stlp_std::priv::__ucopy_ptrs<unsigned int *,unsigned int *>@<eax>(
        char *__first@<ecx>,
        unsigned __int8 *__result@<eax>,
        char *__last)
{
  int v3; // esi
  int v4; // eax

  if ( __last != __first )
  {
    v3 = __last - __first;
    memcpy(__result, (unsigned __int8 *)__first, __last - __first);
    return (unsigned __int8 *)(v3 + v4);
  }
  return __result;
}
