void __usercall stlp_std::priv::__insertion_sort<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first@<eax>,
        vostok::render::custom_config_value *__last)
{
  vostok::render::custom_config_value *i; // edi
  bool (__cdecl *v4)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *); // [esp+0h] [ebp-Ch]

  for ( i = __first + 1; i != __last; ++i )
    stlp_std::priv::__linear_insert<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      __first,
      i,
      *i,
      v4);
}
