void __thiscall survarium::game::build_lpv_geometry(survarium::game *this)
{
  vostok::render::scene_renderer::build_lpv_geometry(
    (vostok::render::scene_renderer *)this,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world.m_render_scene);
}
