void __thiscall survarium::player::on_fire(survarium::player *this)
{
  void (__stdcall ****v2)(vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *, int, _DWORD); // esi
  void (__stdcall ****i)(vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *, int, _DWORD); // edi
  vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *p_m_inventory; // eax

  v2 = *(void (__stdcall *****)(vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *, int, _DWORD))((char *)&dword_10DE0 + (_DWORD)this);
  for ( i = *(void (__stdcall *****)(vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *, int, _DWORD))((char *)&dword_10DE4 + (_DWORD)this);
        v2 != i;
        ++v2 )
  {
    if ( this == (survarium::player *)48 )
      p_m_inventory = 0;
    else
      p_m_inventory = &this->m_inventory;
    (***v2)(p_m_inventory, 3, 0.0);
  }
}
