void __thiscall vostok::ai::brain_unit::set_behaviour(
        vostok::ai::brain_unit *this,
        const vostok::resources::resource_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base> *new_behaviour)
{
  vostok::memory::doug_lea_allocator *v2; // eax
  survarium::game_camera *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // eax
  survarium::game_camera *v5; // ecx
  vostok::ai::planning::specified_problem *v6; // eax
  vostok::ai::planning::specified_problem *v7; // [esp+0h] [ebp-48h]
  vostok::ai::planning::pddl_problem *problem; // [esp+14h] [ebp-34h]
  survarium::game_camera *v10; // [esp+18h] [ebp-30h]
  void *_Where; // [esp+20h] [ebp-28h]
  vostok::ai::behaviour *m_object; // [esp+2Ch] [ebp-1Ch]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+30h] [ebp-18h] BYREF
  vostok::ai::planning::specified_problem *v14; // [esp+44h] [ebp-4h]

  vostok::ai::brain_unit::stop_activity(this);
  if ( this->m_specified_problem )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_specified_problem);
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::specified_problem>(
      v2,
      &this->m_specified_problem);
  }
  v13.m_object = 0;
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v13,
    new_behaviour);
  m_object = v13.m_object;
  v13.m_object = this->m_behaviour.m_object;
  this->m_behaviour.m_object = m_object;
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v13);
  vostok::ai::brain_unit::set_sensors_parameters(this);
  survarium::weapon_user_dead_state::finalize(v3);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v4, 0x118u);
  v14 = (vostok::ai::planning::specified_problem *)operator new(0x118u, _Where);
  if ( v14 )
  {
    survarium::weapon_user_dead_state::finalize(v5);
    v10 = (survarium::game_camera *)this->m_behaviour.m_object;
    problem = (vostok::ai::planning::pddl_problem *)LODWORD(v10[6].m_far_plane);
    survarium::weapon_user_dead_state::finalize(v10);
    vostok::ai::planning::specified_problem::specified_problem(v14, this->m_behaviour.m_object->m_domain, problem, this);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  this->m_specified_problem = v7;
  this->m_is_activity_suspended = 0;
}
