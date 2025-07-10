void __usercall stlp_std::priv::__partial_sort<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first@<eax>,
        vostok::render::custom_config_value *__middle,
        vostok::render::custom_config_value *__last,
        vostok::render::custom_config_value *__formal)
{
  vostok::render::custom_config_value *i; // edi
  int *v6; // [esp+0h] [ebp-10h]

  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &),vostok::render::custom_config_value,int>(
      __first,
      __middle,
      (bool (__cdecl *)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))__formal);
  for ( i = __middle; i < __last; ++i )
  {
    if ( ((unsigned __int8 (__cdecl *)(vostok::render::custom_config_value *, vostok::render::custom_config_value *))__formal)(
           i,
           __first) )
    {
      stlp_std::__pop_heap<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &),int>(
        __first,
        __middle,
        i,
        *i,
        (bool (__cdecl *)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))__formal,
        v6);
    }
  }
  stlp_std::sort_heap<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
    __first,
    __middle,
    (bool (__cdecl *)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))__formal);
}
