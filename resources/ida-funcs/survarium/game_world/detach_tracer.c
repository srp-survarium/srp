void __thiscall survarium::game_world::detach_tracer(survarium::game_world *this, survarium::bullet *bullet)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v2; // esi

  v2 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)&this->m_third_person_game_effect_presenters[10964] + 8 * bullet->m_tracer_idx);
  vostok::render::scene_renderer::remove_tracer(
    (vostok::render::scene_renderer *)this,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)&this[-1].m_third_person_game_effect_presenters[11180] + 172)),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this[-1].m_third_person_game_effect_presenters[11024],
    v2 + 1);
  v2->m_object = 0;
  bullet->m_tracer_idx = -1;
}
