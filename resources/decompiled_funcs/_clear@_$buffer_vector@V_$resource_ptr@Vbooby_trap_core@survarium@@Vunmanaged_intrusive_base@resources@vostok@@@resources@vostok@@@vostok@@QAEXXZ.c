void __thiscall vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>>::clear(
        vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> > *this)
{
  vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *i; // [esp+4h] [ebp-8h]

  for ( i = (vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)this->m_begin;
        i != (vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)this->m_end;
        ++i )
  {
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>(i);
  }
  this->m_end = this->m_begin;
}
