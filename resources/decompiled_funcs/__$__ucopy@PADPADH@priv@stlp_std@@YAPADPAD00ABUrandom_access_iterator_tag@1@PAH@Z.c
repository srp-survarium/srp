char *__cdecl stlp_std::priv::__ucopy<char *,char *,int>(const char *__first, const char *__last, char *__result)
{
  int __n; // [esp+4h] [ebp-8h]

  for ( __n = __last - __first; __n > 0; --__n )
  {
    survarium::generate_shaders_world::is_loading();
    survarium::generate_shaders_world::is_loading();
    *__result++ = *__first++;
  }
  return __result;
}
