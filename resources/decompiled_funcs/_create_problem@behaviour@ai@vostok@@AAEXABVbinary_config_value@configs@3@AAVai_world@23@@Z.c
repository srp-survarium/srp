void __thiscall vostok::ai::behaviour::create_problem(
        vostok::ai::behaviour *this,
        vostok::configs::binary_config_value *options,
        survarium::weapon_core_animation_end_aware_state *world)
{
  survarium::game_camera *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // eax
  vostok::ai::planning::pddl_problem *v5; // [esp+0h] [ebp-24h]
  vostok::ai::planning::pddl_domain *m_domain; // [esp+8h] [ebp-1Ch]
  int *_Where; // [esp+14h] [ebp-10h]
  survarium::game_options *v9; // [esp+1Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v3);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v4, 0x8Cu);
  v9 = (survarium::game_options *)operator new(0x8Cu, _Where);
  if ( v9 )
  {
    m_domain = this->m_domain;
    survarium::weapon_core::cast_weapon_core(v9);
    vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)v9);
    v9[1].m_waiting_for_bind_action = (survarium::game_action_id)m_domain;
    v5 = (vostok::ai::planning::pddl_problem *)v9;
  }
  else
  {
    v5 = 0;
  }
  this->m_problem = v5;
  vostok::ai::fill_action_instances(options, world, this->m_domain, this->m_problem);
}
