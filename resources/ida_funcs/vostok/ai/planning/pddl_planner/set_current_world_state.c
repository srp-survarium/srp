void __thiscall vostok::ai::planning::pddl_planner::set_current_world_state(
        vostok::ai::planning::pddl_planner *this,
        vostok::ai::planning::specified_problem *actual_problem)
{
  unsigned int world_state_size; // eax
  survarium::game_camera *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // eax
  vostok::ai::planning::oracle *v5; // eax
  int *_Where; // [esp+8h] [ebp-114h]
  vostok::ai::planning::pddl_predicate_redirector *v8; // [esp+10h] [ebp-10Ch]
  char oracle_caption[256]; // [esp+14h] [ebp-108h] BYREF
  unsigned int i; // [esp+118h] [ebp-4h] BYREF

  for ( i = 0; ; ++i )
  {
    world_state_size = vostok::ai::planning::specified_problem::get_world_state_size(actual_problem);
    if ( i >= world_state_size )
      break;
    vostok::sprintf<256>((char (*)[256])oracle_caption, "oracle#%d", i);
    survarium::weapon_user_dead_state::finalize(v3);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v4, 0x38u);
    v8 = (vostok::ai::planning::pddl_predicate_redirector *)operator new(0x38u, _Where);
    if ( v8 )
    {
      vostok::ai::planning::pddl_predicate_redirector::pddl_predicate_redirector(v8, oracle_caption, actual_problem, &i);
      vostok::ai::planning::oracle_holder::add(&this->m_planner.m_oracles, &i, v5);
    }
    else
    {
      vostok::ai::planning::oracle_holder::add(&this->m_planner.m_oracles, &i, 0);
    }
  }
}
