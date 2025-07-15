void __thiscall vostok::render::bake_decal_cook::bake_decal_cook(vostok::render::bake_decal_cook *this)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v1; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v2; // [esp+0h] [ebp-20h]
  char v3; // [esp+1Fh] [ebp-1h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x69,
    &bake_decal_cooker,
    reuse_false,
    0xFFFFFFFD,
    0,
    v2);
  bake_decal_cooker.__vftable = (vostok::render::bake_decal_cook_vtbl *)&vostok::render::bake_decal_cook::`vftable';
  *(_DWORD *)&bake_decal_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_color = 0;
  bake_decal_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_parent = 0;
  bake_decal_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_left = 0;
  bake_decal_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_right = 0;
  bake_decal_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_parent = 0;
  bake_decal_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_node_count = 0;
  bake_decal_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_left = &bake_decal_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data;
  bake_decal_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_right = &bake_decal_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data;
  bake_decal_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_color = 0;
  bake_decal_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_key_compare.gap0 = v3;
  bake_decal_cooker.m_constants_registered = 0;
  vostok::resources::resources_manager::register_cook(&bake_decal_cooker, v1);
}
