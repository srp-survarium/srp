void __usercall stlp_std::sort<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first@<eax>,
        vostok::render::custom_config_value *__last@<edi>)
{
  int v3; // eax
  int i; // ecx
  bool (__cdecl *v5)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *); // [esp+0h] [ebp-4h]

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::render::custom_config_value *,vostok::render::custom_config_value,int,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      __first,
      __last,
      0,
      2 * i,
      vostok::render::sort_by_crc_vostok::render::custom_config_value__::_5_::predicate::compare);
    stlp_std::priv::__final_insertion_sort<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      __first,
      __last,
      v5);
  }
}
