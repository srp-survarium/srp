void __userpurge survarium::base_game_scene::show_movie(
        vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *movie@<edi>,
        survarium::base_game_scene *a2@<ecx>,
        survarium::base_game_scene *this)
{
  unsigned int *v3; // eax
  vostok::render::game::renderer *v4; // ecx
  survarium::flash_movie_resource *m_object; // eax
  survarium::flash_movie_resource *v6; // [esp-4h] [ebp-Ch] BYREF

  v3 = (unsigned int *)survarium::base_game_scene::output_window_size(a2, (int)this);
  survarium::flash_movie::SetViewport(movie->m_object->movie, *v3, v3[1]);
  v4 = (vostok::render::game::renderer *)&v6;
  v6 = 0;
  m_object = movie->m_object;
  if ( movie->m_object )
  {
    v6 = movie->m_object;
    v4 = (vostok::render::game::renderer *)_InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::render::game::renderer::show_movie(
    v4,
    (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)this->m_game->m_renderer,
    (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>)&this->m_render_scene_view);
}
