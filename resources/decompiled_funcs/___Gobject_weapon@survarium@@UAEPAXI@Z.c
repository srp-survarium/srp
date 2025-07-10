survarium::object_weapon *__thiscall survarium::object_weapon::`scalar deleting destructor'(
        survarium::object_weapon *this,
        char a2)
{
  vostok::loose_ptr_data *m_pointer; // eax

  this->vostok::ai::weapon::__vftable = (survarium::object_weapon_vtbl *)&survarium::object_weapon::`vftable'{for `vostok::ai::weapon'};
  this->vostok::ai::game_object::__vftable = (vostok::ai::game_object_vtbl *)&survarium::object_weapon::`vftable'{for `vostok::ai::game_object'};
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
