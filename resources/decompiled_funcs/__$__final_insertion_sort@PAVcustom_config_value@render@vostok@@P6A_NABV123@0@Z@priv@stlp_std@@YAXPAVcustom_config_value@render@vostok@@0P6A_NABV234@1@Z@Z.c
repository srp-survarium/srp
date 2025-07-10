void __usercall stlp_std::priv::__final_insertion_sort<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first@<esi>,
        vostok::render::custom_config_value *__last@<eax>,
        vostok::render::custom_config_value *a3@<ebx>)
{
  bool (__cdecl *v4)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *); // [esp+0h] [ebp-4h]

  if ( __last - __first <= 16 )
  {
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        __first,
        __last);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      __first,
      __first + 16);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      __first + 16,
      __last,
      a3,
      v4);
  }
}
