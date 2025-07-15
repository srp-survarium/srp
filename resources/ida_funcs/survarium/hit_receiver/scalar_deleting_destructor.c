survarium::hit_receiver *__thiscall survarium::hit_receiver::`scalar deleting destructor'(
        survarium::hit_receiver *this,
        char a2)
{
  vostok::loose_ptr_data *m_pointer; // eax

  this->__vftable = (survarium::hit_receiver_vtbl *)&survarium::hit_receiver::`vftable';
  if ( --this->m_pointer->m_reference_count )
  {
    this->m_pointer->m_pointer = 0;
  }
  else
  {
    m_pointer = this->m_pointer;
    if ( m_pointer )
    {
      pt3free(m_pointer);
      this->m_pointer = 0;
    }
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
