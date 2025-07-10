void __fastcall vostok::render::speedtree_forest::set_transform(
        int a1,
        const vostok::math::float4x4 *transform,
        vostok::render::speedtree_forest *this,
        vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> st_instance_ptr)
{
  vostok::render::speedtree_tree_base *m_object; // eax
  const struct SpeedTree::CCore *v5; // edi
  SpeedTree::CInstance *v6; // eax
  SpeedTree::CInstance new_speedtree_instance; // [esp+8h] [ebp-48h] BYREF
  SpeedTree::CInstance old_speedtree_instance; // [esp+2Ch] [ebp-24h] BYREF

  m_object = st_instance_ptr.m_object->m_speedtree_tree_ptr.m_object;
  if ( m_object )
    v5 = (const struct SpeedTree::CCore *)&m_object[1];
  else
    v5 = 0;
  old_speedtree_instance = *(SpeedTree::CInstance *)&st_instance_ptr.m_object[1].~vostok::resources::resource_base;
  vostok::render::speedtree_instance_impl::set_transform(
    (vostok::render::speedtree_instance_impl *)st_instance_ptr.m_object,
    (vostok::render::speedtree_instance_impl *)st_instance_ptr.m_object,
    transform);
  v6 = (SpeedTree::CInstance *)st_instance_ptr.m_object[1].__vftable;
  new_speedtree_instance = *v6;
  SpeedTree::CForest::ChangeInstance(this->m_forest, v5, &old_speedtree_instance, &new_speedtree_instance);
  SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&new_speedtree_instance);
  SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&old_speedtree_instance);
  if ( st_instance_ptr.m_object )
  {
    if ( !_InterlockedExchangeAdd(&st_instance_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &st_instance_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
        st_instance_ptr.m_object);
  }
}
