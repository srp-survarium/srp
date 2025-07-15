void __thiscall survarium::gather_victory_items_rule_cook::delete_resource(
        survarium::gather_victory_items_rule_cook *this,
        vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *resource)
{
  char **m_object; // edi
  survarium::victory_items_container_core *v4; // edi
  survarium::victory_items_container_core *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // edi
  vostok::memory::doug_lea_allocator *v8; // ecx
  const char *v9; // [esp+0h] [ebp-14h]
  const char *v10; // [esp+4h] [ebp-10h]
  unsigned int v11; // [esp+8h] [ebp-Ch]
  vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v12; // [esp+10h] [ebp-4h]
  survarium::victory_items_container_core *i; // [esp+1Ch] [ebp+8h]
  survarium::victory_items_container_core *v14; // [esp+1Ch] [ebp+8h]

  m_object = (char **)resource[72].m_object;
  for ( i = resource[73].m_object; m_object != (char **)i; ++m_object )
  {
    if ( *m_object )
      vostok::memory::doug_lea_allocator::free_impl(
        (vostok::memory::doug_lea_allocator *)this,
        (int)survarium::g_allocator,
        *m_object,
        v9,
        v10,
        v11);
  }
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::erase(
    (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)&resource[72],
    (void **)&resource[72].m_object->__vftable,
    (void **)&resource[73].m_object->__vftable);
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::erase(
    (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)&resource[76],
    (void **)&resource[76].m_object->__vftable,
    (void **)&resource[77].m_object->__vftable);
  if ( resource[80].m_object != resource[81].m_object )
  {
    v14 = resource[80].m_object;
    v4 = resource[81].m_object;
    v12 = (vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v14;
    if ( v14 != v4 )
    {
      do
        vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v12++);
      while ( v12 != (vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v4 );
    }
    resource[81].m_object = v14;
  }
  v5 = resource[69].m_object;
  if ( resource[68].m_object != v5 )
    stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base>>>::_M_erase(
      (vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *)v5,
      (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> > > *)&resource[68],
      (vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *)resource[68].m_object,
      (const stlp_std::__false_type *)v9);
  v6 = survarium::g_allocator;
  v7 = __RTCastToVoid((void **)&resource->m_object);
  ((void (__thiscall *)(vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *, _DWORD))resource->m_object->__vftable)(
    resource,
    0);
  vostok::memory::doug_lea_allocator::free_impl(v8, (int)v6, v7, v9, v10, v11);
}
