void __usercall survarium::chat_handler::hide(
        survarium::chat_handler *this@<esi>,
        survarium::base_game_scene *scene@<edx>,
        int a3@<ecx>)
{
  vostok::render::game::renderer *v3; // ecx
  survarium::flash_movie_resource *m_object; // eax
  _DWORD v5[2]; // [esp-8h] [ebp-8h] BYREF

  v5[1] = a3;
  if ( this->m_chat_ui.m_object )
  {
    v3 = (vostok::render::game::renderer *)v5;
    v5[0] = 0;
    m_object = this->m_chat_ui.m_object;
    if ( m_object )
    {
      v5[0] = this->m_chat_ui.m_object;
      v3 = (vostok::render::game::renderer *)_InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::render::game::renderer::hide_movie(
      v3,
      (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)scene->m_game->m_renderer,
      (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>)&scene->m_render_scene_view);
  }
  this->m_active = 0;
}
