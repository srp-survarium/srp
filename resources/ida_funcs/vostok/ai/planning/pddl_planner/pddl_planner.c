void __thiscall vostok::ai::planning::pddl_planner::pddl_planner(vostok::ai::planning::pddl_planner *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  vostok::ai::planning::plan_tracker *v3; // [esp+0h] [ebp-28h]
  int *_Where; // [esp+1Ch] [ebp-Ch]
  survarium::game_options *v6; // [esp+24h] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  vostok::ai::planning::propositional_planner::propositional_planner(&this->m_planner);
  survarium::weapon_user_dead_state::finalize(v1);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v2, 0x24u);
  v6 = (survarium::game_options *)operator new(0x24u, _Where);
  if ( v6 )
  {
    survarium::weapon_core::cast_weapon_core(v6);
    v6->vostok::input::handler::__vftable = (survarium::game_options_vtbl *)this;
    vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&v6->impl);
    LOBYTE(v6->m_options[2]) = 1;
    BYTE1(v6->m_options[2]) = 0;
    v3 = (vostok::ai::planning::plan_tracker *)v6;
  }
  else
  {
    v3 = 0;
  }
  this->m_plan_tracker = v3;
  vostok::fixed_vector<vostok::ai::planning::plan_item,32>::fixed_vector<vostok::ai::planning::plan_item,32>(&this->m_current_plan);
  this->m_failed = 0;
}
