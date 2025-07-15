void __userpurge vostok::render::scene::set_speedtree_instance_transform(
        vostok::render::scene *this@<ecx>,
        int a2@<esi>,
        vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> instance,
        const vostok::math::float4x4 *transform,
        bool populate_forest)
{
  vostok::render::speedtree_instance *m_object; // ecx
  vostok::render::speedtree_forest *v6; // ecx
  vostok::render::speedtree_instance *v7; // [esp-4h] [ebp-4h]

  v7 = 0;
  m_object = instance.m_object;
  if ( instance.m_object )
  {
    v7 = instance.m_object;
    m_object = (vostok::render::speedtree_instance *)_InterlockedExchangeAdd(&instance.m_object->m_reference_count, 1u);
  }
  vostok::render::speedtree_forest::set_transform(
    (int)m_object,
    transform,
    *(vostok::render::speedtree_forest **)(a2 + 952),
    (vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base>)v7);
  if ( populate_forest )
    vostok::render::speedtree_forest::populate_forest(v6, *(vostok::render::speedtree_forest **)(a2 + 952));
  if ( instance.m_object )
  {
    if ( !_InterlockedExchangeAdd(&instance.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &instance.m_object->vostok::resources::unmanaged_intrusive_base,
        instance.m_object);
  }
}
