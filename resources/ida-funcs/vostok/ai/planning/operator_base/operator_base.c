void __thiscall vostok::ai::planning::operator_base::operator_base(vostok::ai::planning::operator_base *this)
{
  this->__vftable = (vostok::ai::planning::operator_base_vtbl *)&vostok::ai::planning::operator_base::`vftable';
  this->m_preconditions.m_properties._M_impl._M_start = 0;
  this->m_preconditions.m_properties._M_impl._M_finish = 0;
  this->m_preconditions.m_properties._M_impl._M_end_of_storage._M_data = 0;
  this->m_preconditions.m_hash = 0;
  this->m_effects.m_properties._M_impl._M_start = 0;
  this->m_effects.m_properties._M_impl._M_finish = 0;
  this->m_effects.m_properties._M_impl._M_end_of_storage._M_data = 0;
  this->m_effects.m_hash = 0;
  this->m_preconditions_hash = this->m_preconditions.m_hash;
  this->m_effects_hash = this->m_effects.m_hash;
  this->m_min_weight = 0;
}
