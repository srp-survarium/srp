void __userpurge survarium::base_game_scene::show_movie(
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *movie@<eax>,
        survarium::base_game_scene *this)
{
  vostok::particle::particle_system_instance_impl *v3; // ecx
  vostok::render::game::renderer *v4; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp-4h] [ebp-14h] BYREF

  survarium::flash_movie::SetViewport(
    (survarium::flash_movie *)movie->m_object->m_lods[0].m_template.m_object,
    this->m_game->m_render_output_window.m_object->m_current_size.x,
    this->m_game->m_render_output_window.m_object->m_current_size.y);
  v5.m_object = v3;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v5,
    movie);
  vostok::render::game::renderer::show_movie(
    v4,
    (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)this->m_game->m_renderer,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_render_scene_view,
    v5);
}
