vostok::core::configs::binary_config_cook *__thiscall vostok::resources::resources_manager::get_binary_config_cook(
        vostok::resources::resources_manager *this)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v1; // ecx
  vostok::resources::resources_manager *v3; // [esp-4h] [ebp-10h]
  vostok::resources::resources_manager *v4; // [esp-4h] [ebp-10h]
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v5; // [esp+0h] [ebp-Ch]

  if ( (_S6_3 & 1) == 0 )
  {
    _S6_3 |= 1u;
    vostok::resources::cook_base::cook_base(&cook2, binary_config_class_impl, 0xFFFFFFFC, reuse_true, 0, 0xFFFFFFFC);
    cook2.__vftable = (vostok::core::configs::binary_config_cook_impl_vtbl *)&vostok::core::configs::binary_config_cook_impl::`vftable';
    atexit((int (__cdecl *)())vostok::resources::resources_manager::get_binary_config_cook_::_2_::_dynamic_atexit_destructor_for__cook2__);
    this = v3;
  }
  if ( (_S6_3 & 2) == 0 )
  {
    _S6_3 |= 2u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x205,
      &cook,
      reuse_true,
      0xFFFFFFFC,
      0,
      v5);
    cook.__vftable = (vostok::core::configs::binary_config_cook_vtbl *)&vostok::core::configs::binary_config_cook::`vftable';
    atexit((int (__cdecl *)())vostok::resources::resources_manager::get_binary_config_cook_::_2_::_dynamic_atexit_destructor_for__cook__);
    this = v4;
  }
  if ( !initialized_2 )
  {
    initialized_2 = 1;
    vostok::resources::resources_manager::register_cook(
      &cook2,
      (vostok::buffer_vector<vostok::resources::cook_base *> *)this);
    vostok::resources::resources_manager::register_cook(&cook, v1);
  }
  return &cook;
}
