void __thiscall vostok::ai::planning::operator_holder::clear(vostok::ai::planning::operator_holder *this)
{
  while ( this->m_objects._M_impl._M_start != this->m_objects._M_impl._M_finish )
    vostok::ai::planning::operator_holder::remove_impl(this, &this->m_objects._M_impl._M_finish[-1].m_id, 1);
}
