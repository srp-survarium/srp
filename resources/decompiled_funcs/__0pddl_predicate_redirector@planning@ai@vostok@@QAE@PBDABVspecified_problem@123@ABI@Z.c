void __thiscall vostok::ai::planning::pddl_predicate_redirector::pddl_predicate_redirector(
        vostok::ai::planning::pddl_predicate_redirector *this,
        const char *caption,
        const vostok::ai::planning::specified_problem *problem,
        unsigned int *id)
{
  this->__vftable = (vostok::ai::planning::pddl_predicate_redirector_vtbl *)&vostok::ai::planning::oracle::`vftable';
  vostok::fixed_string<32>::fixed_string<32>(&this->vostok::ai::planning::oracle::m_id, caption);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_problem);
  this->__vftable = (vostok::ai::planning::pddl_predicate_redirector_vtbl *)&vostok::ai::planning::pddl_predicate_redirector::`vftable';
  this->m_problem = problem;
  this->m_id = *id;
}
