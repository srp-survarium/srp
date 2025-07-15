void __thiscall survarium::game_world::remove_decal(
        survarium::game_world *this,
        vostok::particle::particle_system_instance_impl *id)
{
  vostok::render::scene_renderer::remove_decal(
    (vostok::render::scene_renderer *)this,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)&this[-1].m_third_person_game_effect_presenters[11180] + 172)),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this[-1].m_third_person_game_effect_presenters[11024],
    id);
}
