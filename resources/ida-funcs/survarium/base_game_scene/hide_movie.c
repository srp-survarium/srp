void __userpurge survarium::base_game_scene::hide_movie(
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *movie@<eax>,
        vostok::particle::particle_system_instance_impl *a2@<ecx>,
        survarium::base_game_scene *this)
{
  vostok::render::game::renderer *v3; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp-4h] [ebp-14h] BYREF

  if ( movie->m_object )
  {
    v4.m_object = a2;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v4,
      movie);
    vostok::render::game::renderer::hide_movie(
      v3,
      (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)this->m_game->m_renderer,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_render_scene_view,
      v4);
  }
}
