void __thiscall vostok::render::speedtree_forest::speedtree_forest(
        vostok::render::speedtree_forest *this,
        vostok::render::speedtree_forest *thisa)
{
  vostok::render::speedtree_billboard_parameters *v2; // ecx
  vostok::render::speedtree_tree_parameters *v3; // ecx
  vostok::render::speedtree_common_parameters *v4; // ecx
  SpeedTree::SForestCullResults *v5; // ecx
  SpeedTree::CView *v6; // ecx
  SpeedTree::CForest *v7; // eax
  SpeedTree::CForest *v8; // eax
  SpeedTree::CForest *m_forest; // edi
  SpeedTree::CForest *v10; // ecx
  SpeedTree::Vec3 vDir; // [esp+14h] [ebp-Ch] BYREF

  vostok::render::speedtree_wind_parameters::speedtree_wind_parameters(&this->m_speedtree_wind_parameters);
  vostok::render::speedtree_billboard_parameters::speedtree_billboard_parameters(v2);
  vostok::render::speedtree_tree_parameters::speedtree_tree_parameters(v3);
  vostok::render::speedtree_common_parameters::speedtree_common_parameters(v4);
  SpeedTree::SForestCullResults::SForestCullResults(v5, (int)&thisa->m_visible_trees);
  thisa->m_visuble_grass.m_aCellsToUpdate.m_pData = 0;
  thisa->m_visuble_grass.m_aCellsToUpdate.m_uiSize = 0;
  thisa->m_visuble_grass.m_aCellsToUpdate.m_uiDataSize = 0;
  thisa->m_visuble_grass.m_aCellsToUpdate.m_bExternalMemory = 0;
  thisa->m_visuble_grass.m_aCellsToUpdate.__vftable = (SpeedTree::CArray<SpeedTree::CGrassCell *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CGrassCell *,1>::`vftable';
  thisa->m_visuble_grass.m_aFreedVbos.__vftable = (SpeedTree::CArray<void *,1>_vtbl *)&SpeedTree::CArray<void *,1>::`vftable';
  thisa->m_visuble_grass.m_aFreedVbos.m_pData = 0;
  thisa->m_visuble_grass.m_aFreedVbos.m_uiSize = 0;
  thisa->m_visuble_grass.m_aFreedVbos.m_uiDataSize = 0;
  thisa->m_visuble_grass.m_aFreedVbos.m_bExternalMemory = 0;
  thisa->m_visuble_grass.m_aVisibleCells.__vftable = (SpeedTree::CArray<SpeedTree::CGrassCell *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CGrassCell *,1>::`vftable';
  thisa->m_visuble_grass.m_aVisibleCells.m_pData = 0;
  thisa->m_visuble_grass.m_aVisibleCells.m_uiSize = 0;
  thisa->m_visuble_grass.m_aVisibleCells.m_uiDataSize = 0;
  thisa->m_visuble_grass.m_aVisibleCells.m_bExternalMemory = 0;
  SpeedTree::CView::CView(v6, (int)&thisa->m_view);
  SpeedTree::CGrass::CGrass(&thisa->m_grass);
  thisa->m_trees._M_impl._M_start = 0;
  thisa->m_trees._M_impl._M_finish = 0;
  thisa->m_trees._M_impl._M_end_of_storage._M_data = 0;
  thisa->m_tree_instances._M_impl._M_start = 0;
  thisa->m_tree_instances._M_impl._M_finish = 0;
  thisa->m_tree_instances._M_impl._M_end_of_storage._M_data = 0;
  SpeedTree::CWind::CWind(&thisa->m_wind_leader);
  if ( SpeedTree::g_pAllocator
    && (v7 = (SpeedTree::CForest *)SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, 3208)) != 0 )
  {
    SpeedTree::g_siHeapMemoryUsed += 3208;
    ++SpeedTree::g_siNumHeapAllocs;
    v8 = SpeedTree::CForest::CForest(v7);
  }
  else
  {
    v8 = 0;
  }
  thisa->m_forest = v8;
  v8->m_bWindEnabled = 1;
  m_forest = thisa->m_forest;
  vDir.x = FLOAT_0_5;
  vDir.y = 0.0;
  vDir.z = FLOAT_0_5;
  SpeedTree::CForest::SetGlobalWindDirection(m_forest, &vDir);
  SpeedTree::CForest::SetGlobalWindStrength(v10, (int)thisa->m_forest);
  SpeedTree::CForest::InitBillboardSystem(thisa->m_forest);
  thisa->m_forest->m_cTreeCellMap.m_fCellSize = 25.0;
}
