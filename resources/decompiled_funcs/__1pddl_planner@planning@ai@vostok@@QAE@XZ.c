void __thiscall vostok::ai::planning::pddl_planner::~pddl_planner(vostok::ai::planning::pddl_planner *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  vostok::ai::planning::plan_tracker **p_m_plan_tracker; // [esp-4h] [ebp-30h]
  vostok::ai::planning::plan_item *p; // [esp+8h] [ebp-24h]

  p_m_plan_tracker = &this->m_plan_tracker;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::plan_tracker>(
    v1,
    p_m_plan_tracker);
  for ( p = this->m_current_plan.m_begin; p != this->m_current_plan.m_end; ++p )
    vostok::buffer_vector<vostok::ai::planning::plan_item>::destroy(p);
  this->m_current_plan.m_end = this->m_current_plan.m_begin;
  vostok::ai::planning::propositional_planner::~propositional_planner(&this->m_planner);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
