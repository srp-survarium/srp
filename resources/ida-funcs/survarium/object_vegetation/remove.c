void __thiscall survarium::object_vegetation::remove(survarium::object_vegetation *this)
{
  survarium::base_game_scene **p_m_game_scene; // ebx
  vostok::render::scene_renderer *v2; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v3; // [esp-8h] [ebp-14h] BYREF
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *p_m_render_scene; // [esp-4h] [ebp-10h]

  p_m_game_scene = &this->m_game_scene;
  p_m_render_scene = &this->m_game_scene->m_render_scene;
  v3.m_object = (survarium::pure_game_effect_emitter_base *)this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v3,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_grass);
  vostok::render::scene_renderer::reset_grass(
    v2,
    *(vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)((char *)&dword_200060 + (unsigned int)(*p_m_game_scene)->m_game->m_renderer),
    (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)v3.m_object,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_render_scene);
}
