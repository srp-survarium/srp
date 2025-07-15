vostok::physics::bt_animated_rigid_body *__thiscall vostok::physics::bt_animated_rigid_body::`scalar deleting destructor'(
        vostok::physics::bt_animated_rigid_body *this,
        char a2)
{
  vostok::loose_ptr_data *m_pointer; // eax

  this->__vftable = (vostok::physics::bt_animated_rigid_body_vtbl *)&vostok::physics::bt_rigid_body_base::`vftable';
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
