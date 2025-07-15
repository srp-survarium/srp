void __thiscall vostok::ai::planning::generalized_action::generalized_action(
        vostok::ai::planning::generalized_action *this,
        const vostok::ai::planning::pddl_domain *domain,
        unsigned int type,
        const char *name,
        unsigned int cost)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->next = 0;
  this->m_preconditions._M_impl._M_start = 0;
  this->m_preconditions._M_impl._M_finish = 0;
  this->m_preconditions._M_impl._M_end_of_storage._M_data = 0;
  this->m_effects._M_impl._M_start = 0;
  this->m_effects._M_impl._M_finish = 0;
  this->m_effects._M_impl._M_end_of_storage._M_data = 0;
  vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
    &this->m_parameter_types,
    (unsigned int *)this->m_parameter_types.m_buffer,
    4u,
    0);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_clones);
  this->m_parent = 0;
  vostok::fixed_string<32>::fixed_string<32>(&this->m_caption, name);
  this->m_type = type;
  this->m_cost = cost;
  this->m_domain = domain;
}
