vostok::ai::planning::pddl_predicate_redirector *__thiscall vostok::ai::planning::pddl_predicate_redirector::`scalar deleting destructor'(
        vostok::ai::planning::pddl_predicate_redirector *this,
        char a2)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_problem);
  vostok::ai::planning::oracle::~oracle(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
