void __thiscall vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::clear(
        vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> > *this)
{
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *i; // [esp+4h] [ebp-8h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  this->m_end = this->m_begin;
}
