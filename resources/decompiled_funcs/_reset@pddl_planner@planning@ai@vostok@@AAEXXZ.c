void __thiscall vostok::ai::planning::pddl_planner::reset(vostok::ai::planning::pddl_planner *this)
{
  vostok::ai::planning::plan_item *p; // [esp+8h] [ebp-10h]
  vostok::ai::planning::propositional_planner_base *v3; // [esp+14h] [ebp-4h]

  v3 = &this->m_planner.vostok::ai::planning::propositional_planner_base;
  vostok::ai::planning::operator_holder::clear(&this->m_planner.m_operators);
  vostok::ai::planning::oracle_holder::clear(&v3->m_oracles);
  for ( p = this->m_current_plan.m_begin; p != this->m_current_plan.m_end; ++p )
    vostok::buffer_vector<vostok::ai::planning::plan_item>::destroy(p);
  this->m_current_plan.m_end = this->m_current_plan.m_begin;
  this->m_failed = 0;
}
