void __thiscall vostok::render::speedtree_forest::~speedtree_forest(
        vostok::render::speedtree_forest *this,
        vostok::render::speedtree_forest *thisa)
{
  SpeedTree::CForest *m_forest; // ecx
  vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  void *v6; // esi
  SpeedTree::SGrassCullResults *v7; // ecx

  m_forest = thisa->m_forest;
  if ( m_forest )
  {
    ((void (__thiscall *)(SpeedTree::CForest *, _DWORD))m_forest->~SpeedTree::CForest)(m_forest, 0);
    if ( SpeedTree::g_pAllocator )
      SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, thisa->m_forest);
    SpeedTree::g_siHeapMemoryUsed -= 3208;
    thisa->m_forest = 0;
  }
  SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&thisa->m_wind_leader);
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)thisa->m_tree_instances._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)thisa->m_tree_instances._M_impl._M_start);
  M_start = thisa->m_tree_instances._M_impl._M_start;
  if ( M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)thisa->m_trees._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)thisa->m_trees._M_impl._M_start);
  v5 = thisa->m_trees._M_impl._M_start;
  if ( v5 )
  {
    v6 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v6, v5);
  }
  SpeedTree::CGrass::~CGrass(&thisa->m_grass);
  SpeedTree::SGrassCullResults::~SGrassCullResults(v7, (int)&thisa->m_visuble_grass);
  SpeedTree::SForestCullResults::~SForestCullResults(&thisa->m_visible_trees);
}
