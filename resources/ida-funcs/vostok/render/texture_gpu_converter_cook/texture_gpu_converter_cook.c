void __thiscall vostok::render::texture_gpu_converter_cook::texture_gpu_converter_cook(
        vostok::render::texture_gpu_converter_cook *this)
{
  char v1; // [esp+1Fh] [ebp-1h]

  vostok::resources::unmanaged_cook::unmanaged_cook(
    texture_gpu_converter_class,
    0xFFFFFFFD,
    &texture_gpu_converter_cooker,
    reuse_false,
    0,
    (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)2);
  texture_gpu_converter_cooker.__vftable = (vostok::render::texture_gpu_converter_cook_vtbl *)&vostok::render::texture_gpu_converter_cook::`vftable';
  *(_DWORD *)&texture_gpu_converter_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_color = 0;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_parent = 0;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_left = 0;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_right = 0;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_left = &texture_gpu_converter_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_right = &texture_gpu_converter_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_key_compare.gap0 = v1;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_color = 0;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_header._M_data._M_parent = 0;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_render_targets._M_t._M_node_count = 0;
  *(_DWORD *)&texture_gpu_converter_cooker.m_surfaces_cache.m_cached_textures._M_t._M_header._M_data._M_color = 0;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_textures._M_t._M_header._M_data._M_parent = 0;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_textures._M_t._M_header._M_data._M_left = 0;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_textures._M_t._M_header._M_data._M_right = 0;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_textures._M_t._M_header._M_data._M_left = &texture_gpu_converter_cooker.m_surfaces_cache.m_cached_textures._M_t._M_header._M_data;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_textures._M_t._M_header._M_data._M_right = &texture_gpu_converter_cooker.m_surfaces_cache.m_cached_textures._M_t._M_header._M_data;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_textures._M_t._M_header._M_data._M_color = 0;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_textures._M_t._M_header._M_data._M_parent = 0;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_textures._M_t._M_node_count = 0;
  texture_gpu_converter_cooker.m_surfaces_cache.m_cached_textures._M_t._M_key_compare.gap0 = v1;
  texture_gpu_converter_cooker.m_screen_vertex_ib.m_object = 0;
  texture_gpu_converter_cooker.m_screen_vertex_geometry.m_object = 0;
}
