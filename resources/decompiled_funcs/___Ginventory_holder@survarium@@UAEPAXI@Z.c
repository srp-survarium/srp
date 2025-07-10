survarium::inventory_holder *__thiscall survarium::inventory_holder::`scalar deleting destructor'(
        survarium::inventory_holder *this,
        char a2)
{
  this->__vftable = (survarium::inventory_holder_vtbl *)&survarium::inventory_holder::`vftable';
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>(&this->m_inventory);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_scheduler);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
