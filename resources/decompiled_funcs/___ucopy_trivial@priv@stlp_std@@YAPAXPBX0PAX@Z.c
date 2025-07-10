unsigned __int8 *__cdecl stlp_std::priv::__ucopy_trivial(
        unsigned __int8 *__first,
        unsigned __int8 *__last,
        unsigned __int8 *__result)
{
  int v4; // eax

  if ( __last == __first )
    return __result;
  memcpy(__result, __first, __last - __first);
  return (unsigned __int8 *)(__last - __first + v4);
}
