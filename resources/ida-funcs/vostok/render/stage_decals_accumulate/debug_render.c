void __thiscall vostok::render::stage_decals_accumulate::debug_render(vostok::render::stage_decals_accumulate *this)
{
  vostok::render::base_scene_view *m_object; // eax
  vostok::resources::unmanaged_resource *m_next_in_global_delay_delete_list; // ecx
  void **it; // [esp+28h] [ebp-30h]
  vostok::math::color color; // [esp+38h] [ebp-20h] BYREF
  vostok::render::vector<vostok::render::decal_instance *> *visible_decals; // [esp+3Ch] [ebp-1Ch]
  vostok::math::aabb aabb; // [esp+40h] [ebp-18h] BYREF

  if ( s_render_debug )
  {
    m_object = this->m_context->m_scene_view.m_object;
    m_next_in_global_delay_delete_list = m_object[4].m_next_in_global_delay_delete_list;
    visible_decals = (vostok::render::vector<vostok::render::decal_instance *> *)&m_object[4].m_next_in_global_delay_delete_list;
    it = (void **)&m_next_in_global_delay_delete_list->__vftable;
    if ( m_next_in_global_delay_delete_list != m_object[4].m_prev_in_global_delay_delete_list )
    {
      do
      {
        color = (vostok::math::color)-16776961;
        aabb = *(vostok::math::aabb *)((char *)*it + 104);
        vostok::render::system_renderer::draw_aabb(
          (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          &aabb,
          &color);
        ++it;
      }
      while ( it != visible_decals->_M_impl._M_finish );
    }
  }
}
