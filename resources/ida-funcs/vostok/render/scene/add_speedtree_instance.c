void __userpurge vostok::render::scene::add_speedtree_instance(
        vostok::render::scene *this@<esi>,
        const vostok::math::float4x4 *transform@<eax>,
        vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> instance,
        bool populate_forest)
{
  vostok::render::speedtree_instance *m_object; // ecx
  vostok::render::speedtree_forest *v5; // ecx
  vostok::render::speedtree_instance_impl *v6; // [esp-8h] [ebp-8h]

  v6 = 0;
  m_object = instance.m_object;
  if ( instance.m_object )
  {
    v6 = (vostok::render::speedtree_instance_impl *)instance.m_object;
    m_object = (vostok::render::speedtree_instance *)_InterlockedExchangeAdd(&instance.m_object->m_reference_count, 1u);
  }
  vostok::render::speedtree_forest::add_instance(
    (vostok::render::speedtree_forest *)m_object,
    this->m_speedtree_forest,
    v6,
    transform);
  if ( populate_forest )
    vostok::render::speedtree_forest::populate_forest(v5, this->m_speedtree_forest);
  if ( instance.m_object )
  {
    if ( !_InterlockedExchangeAdd(&instance.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &instance.m_object->vostok::resources::unmanaged_intrusive_base,
        instance.m_object);
  }
}
