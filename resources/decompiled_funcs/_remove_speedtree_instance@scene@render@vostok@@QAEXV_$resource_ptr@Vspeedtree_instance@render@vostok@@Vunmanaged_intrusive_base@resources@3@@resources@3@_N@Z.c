void __userpurge vostok::render::scene::remove_speedtree_instance(
        vostok::render::scene *this@<ecx>,
        int a2@<esi>,
        vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> instance,
        bool populate_forest)
{
  vostok::render::speedtree_instance *m_object; // ecx
  vostok::render::speedtree_forest *v5; // ecx
  vostok::render::speedtree_instance *v6; // [esp-4h] [ebp-4h]

  v6 = 0;
  m_object = instance.m_object;
  if ( instance.m_object )
  {
    v6 = instance.m_object;
    m_object = (vostok::render::speedtree_instance *)_InterlockedExchangeAdd(&instance.m_object->m_reference_count, 1u);
  }
  vostok::render::speedtree_forest::remove_instance(
    (vostok::render::speedtree_forest *)m_object,
    *(vostok::render::speedtree_forest **)(a2 + 952),
    (vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base>)v6);
  if ( populate_forest )
    vostok::render::speedtree_forest::populate_forest(v5, *(vostok::render::speedtree_forest **)(a2 + 952));
  if ( instance.m_object )
  {
    if ( !_InterlockedExchangeAdd(&instance.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &instance.m_object->vostok::resources::unmanaged_intrusive_base,
        instance.m_object);
  }
}
