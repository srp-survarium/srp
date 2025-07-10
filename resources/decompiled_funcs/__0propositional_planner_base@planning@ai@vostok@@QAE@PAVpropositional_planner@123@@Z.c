void __thiscall vostok::ai::planning::propositional_planner_base::propositional_planner_base(
        vostok::ai::planning::propositional_planner_base *this,
        vostok::ai::planning::propositional_planner *actual_planner)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->m_operators.m_objects._M_impl._M_start = 0;
  this->m_operators.m_objects._M_impl._M_finish = 0;
  this->m_operators.m_objects._M_impl._M_end_of_storage._M_data = 0;
  this->m_operators.m_planner = actual_planner;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_oracles);
  stlp_std::map<unsigned int,vostok::ai::planning::pddl_predicate *,stlp_std::less<unsigned int>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::pddl_predicate *>>>::map<unsigned int,vostok::ai::planning::pddl_predicate *,stlp_std::less<unsigned int>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::pddl_predicate *>>>(&this->m_oracles.m_objects);
  this->m_oracles.m_planner = actual_planner;
  this->m_actual = 1;
}
