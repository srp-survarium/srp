void __thiscall survarium::object_light::remove(survarium::object_light *this)
{
  vostok::render::scene_renderer::remove_light(
    (vostok::render::scene_renderer *)&this->m_game_scene->m_render_scene,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_game_scene->m_game->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_scene->m_render_scene,
    (vostok::particle::particle_system_instance_impl *)this->m_light_id);
}
