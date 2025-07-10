void __thiscall survarium::weapon_core::instant_show(survarium::weapon_core *this)
{
  this->m_aimed = 0;
  ((void (__thiscall *)(survarium::weapon_core *, survarium::weapon_core *))this->on_show)(this, this);
}
