void __userpurge survarium::weapon_user_animations_container::register_animations(
        survarium::weapon_user_animations_container *this@<ecx>,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *a2@<esi>,
        survarium::animations_registry *animations_registry)
{
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *i; // edi
  vostok::resources::managed_resource *m_object; // ebx
  unsigned int v5; // edi

  for ( i = a2 + 66; i != &a2[296]; ++i )
    survarium::animations_registry::register_animation(i, animations_registry, i + 232);
  m_object = a2[297].m_object;
  v5 = 0;
  if ( m_object )
  {
    do
    {
      survarium::animations_registry::register_animation(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&a2[296].m_object->__vftable
      + v5,
        animations_registry,
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&a2[528].m_object->__vftable
      + v5);
      ++v5;
    }
    while ( v5 < (unsigned int)m_object );
  }
}
