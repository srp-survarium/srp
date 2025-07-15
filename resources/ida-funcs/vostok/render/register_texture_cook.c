void vostok::render::register_texture_cook()
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v0; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v1; // [esp+0h] [ebp-Ch]
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v2; // [esp+0h] [ebp-Ch]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)7,
    (vostok::resources::cook_base *)&s_texture_wrapper_cook,
    reuse_true,
    0xFFFFFFFC,
    0,
    v1);
  *(_DWORD *)s_texture_wrapper_cook.m_static_memory = &vostok::render::texture_cook_wrapper::`vftable';
  _InterlockedExchange(&s_texture_wrapper_cook.m_initialized, 1);
  vostok::resources::resources_manager::register_cook(
    s_texture_wrapper_cook.m_variable,
    (vostok::buffer_vector<vostok::resources::cook_base *> *)&s_texture_wrapper_cook.m_initialized);
  vostok::resources::cook_base::cook_base(
    (vostok::resources::cook_base *)&s_texture_cook,
    texture_class,
    0xFFFFFFFC,
    reuse_false,
    (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)49,
    0xFFFFFFFF);
  *(_DWORD *)s_texture_cook.m_static_memory = &vostok::render::texture_cook::`vftable';
  _InterlockedExchange(&s_texture_cook.m_initialized, 1);
  vostok::resources::resources_manager::register_cook(
    s_texture_cook.m_variable,
    (vostok::buffer_vector<vostok::resources::cook_base *> *)&s_texture_cook.m_initialized);
  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x35,
    (vostok::resources::cook_base *)&s_texture_options_binary_cooker,
    reuse_true,
    0xFFFFFFFC,
    0,
    v2);
  *(_DWORD *)s_texture_options_binary_cooker.m_static_memory = &vostok::render::texture_options_binary_cooker::`vftable';
  _InterlockedExchange(&s_texture_options_binary_cooker.m_initialized, 1);
  vostok::resources::resources_manager::register_cook(s_texture_options_binary_cooker.m_variable, v0);
}
