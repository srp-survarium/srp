void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first@<eax>,
        vostok::render::custom_config_value *__last@<edi>)
{
  vostok::render::custom_config_value *i; // esi
  bool (__cdecl *v3)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *); // [esp+0h] [ebp-4h]

  for ( i = __first; i != __last; ++i )
    stlp_std::priv::__unguarded_linear_insert<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      i,
      *i,
      v3);
}
