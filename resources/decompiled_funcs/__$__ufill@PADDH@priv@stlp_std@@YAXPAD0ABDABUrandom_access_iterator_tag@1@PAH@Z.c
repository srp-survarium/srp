void __cdecl stlp_std::priv::__ufill<char *,char,int>(char *__first, char *__last, const char *__x)
{
  int __n; // [esp+4h] [ebp-8h]
  char *__cur; // [esp+8h] [ebp-4h]

  __cur = __first;
  for ( __n = __last - __first; __n > 0; --__n )
  {
    survarium::generate_shaders_world::is_loading();
    survarium::generate_shaders_world::is_loading();
    *__cur++ = *__x;
  }
}
