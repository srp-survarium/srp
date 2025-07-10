void __thiscall vostok::ai::planning::specified_action::specified_action(vostok::ai::planning::specified_action *this)
{
  this->m_preconditions._M_impl._M_start = 0;
  this->m_preconditions._M_impl._M_finish = 0;
  this->m_preconditions._M_impl._M_end_of_storage._M_data = 0;
  this->m_effects._M_impl._M_start = 0;
  this->m_effects._M_impl._M_finish = 0;
  this->m_effects._M_impl._M_end_of_storage._M_data = 0;
  vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
    &this->m_parameters_instances,
    (unsigned int *)this->m_parameters_instances.m_buffer,
    4u,
    0);
  this->m_prototype = 0;
}
