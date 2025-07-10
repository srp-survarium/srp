void __thiscall vostok::render::speedtree_forest::add_instance(
        vostok::render::speedtree_forest *this,
        vostok::render::speedtree_forest *st_instance_ptr,
        vostok::render::speedtree_instance_impl *transform,
        const vostok::math::float4x4 *transforma)
{
  float v4; // ebp
  struct SpeedTree::CCore *v5; // esi
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> > > *v6; // ecx
  float v7; // eax
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> > > *p_m_speedtree_tree_ptr; // ecx
  vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> *M_start; // ecx
  vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> *M_finish; // eax
  const stlp_std::__false_type *v11; // [esp+0h] [ebp-2Ch]
  unsigned int v12; // [esp+4h] [ebp-28h]
  bool v13; // [esp+8h] [ebp-24h]
  SpeedTree::SLodProfile sLodProfile; // [esp+10h] [ebp-1Ch] BYREF

  v4 = *(float *)&transform->m_speedtree_tree_ptr.m_object;
  if ( v4 == 0.0 )
    v5 = 0;
  else
    v5 = (struct SpeedTree::CCore *)(LODWORD(v4) + 288);
  if ( !SpeedTree::CForest::TreeIsRegistered(st_instance_ptr->m_forest, v5) )
  {
    SpeedTree::CForest::RegisterTree(st_instance_ptr->m_forest, v5);
    v7 = *(float *)&st_instance_ptr->m_trees._M_impl._M_finish;
    p_m_speedtree_tree_ptr = (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> > > *)&transform->m_speedtree_tree_ptr;
    if ( (vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *)LODWORD(v7) == st_instance_ptr->m_trees._M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::_M_insert_overflow_aux(
        p_m_speedtree_tree_ptr,
        (int)&st_instance_ptr->m_trees,
        (vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> *)LODWORD(v7),
        (const vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> *)&transform->m_speedtree_tree_ptr,
        v11,
        v12,
        v13);
    }
    else
    {
      if ( v7 != 0.0 )
      {
        *(_DWORD *)LODWORD(v7) = 0;
        M_start = p_m_speedtree_tree_ptr->_M_start;
        if ( M_start )
        {
          *(_DWORD *)LODWORD(v7) = M_start;
          _InterlockedExchangeAdd((volatile signed __int32 *)&M_start[52], 1u);
        }
      }
      ++st_instance_ptr->m_trees._M_impl._M_finish;
    }
    *(_QWORD *)&sLodProfile.m_fHighDetail3dDistance = *(_QWORD *)(LODWORD(v4) + 732);
    *(_QWORD *)&sLodProfile.m_fBillboardStartDistance = *(_QWORD *)(LODWORD(v4) + 740);
    *(_DWORD *)&sLodProfile.m_bLodIsPresent = *(_DWORD *)(LODWORD(v4) + 748);
    sLodProfile.m_f3dRange = sLodProfile.m_fLowDetail3dDistance - sLodProfile.m_fHighDetail3dDistance;
    sLodProfile.m_fBillboardRange = sLodProfile.m_fBillboardFinalDistance - sLodProfile.m_fBillboardStartDistance;
    SpeedTree::CCore::SetLodProfile((SpeedTree::CCore *)(LODWORD(v4) + 288), &sLodProfile);
  }
  M_finish = st_instance_ptr->m_tree_instances._M_impl._M_finish;
  if ( M_finish == st_instance_ptr->m_tree_instances._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::_M_insert_overflow_aux(
      v6,
      (int)&st_instance_ptr->m_tree_instances,
      M_finish,
      (const vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> *)&transform,
      v11,
      v12,
      v13);
  }
  else
  {
    if ( M_finish )
    {
      M_finish->m_object = 0;
      if ( transform )
      {
        M_finish->m_object = transform;
        if ( transform )
          _InterlockedExchangeAdd(&transform->m_reference_count, 1u);
      }
    }
    ++st_instance_ptr->m_tree_instances._M_impl._M_finish;
  }
  vostok::render::speedtree_instance_impl::set_transform(transform, transform, transforma);
  if ( transform )
  {
    if ( !_InterlockedExchangeAdd(&transform->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &transform->vostok::resources::unmanaged_intrusive_base,
        transform);
  }
}
