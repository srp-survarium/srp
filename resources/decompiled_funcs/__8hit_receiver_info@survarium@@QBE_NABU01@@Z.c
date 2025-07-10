bool __thiscall survarium::hit_receiver_info::operator==(
        survarium::hit_receiver_info *this,
        const survarium::hit_receiver_info *rhs)
{
  return this->m_receiver->m_pointer->m_pointer == rhs->m_receiver->m_pointer->m_pointer;
}
