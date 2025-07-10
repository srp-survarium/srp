void __thiscall vostok::render::speedtree_forest::populate_forest(
        vostok::render::speedtree_forest *this,
        vostok::render::speedtree_forest *thisa)
{
  vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *i; // edi
  SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *v4; // ecx
  vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *M_start; // esi
  vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> *j; // edi
  unsigned int m_uiSize; // esi
  SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *v8; // ecx
  SpeedTree::CArray<SpeedTree::CCore *,1> *m_uiDataSize; // ecx
  SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *v10; // ecx
  vostok::render::speedtree_tree_component_billboard *v11; // ecx
  vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *v12; // esi
  SpeedTree::CArray<SpeedTree::CInstance,1> *m_pData; // edi
  vostok::render::speedtree_tree_component_billboard *m_next_for_query_finished_callback; // eax
  SpeedTree::CForest *m_forest; // ecx
  char *v16; // eax
  SpeedTree::CForest::SCompletePopulation *v17; // ecx
  unsigned int *v18; // eax
  SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *v19; // ecx
  SpeedTree::CCore **v20; // eax
  unsigned int v21; // [esp-4h] [ebp-C4h]
  unsigned int v22; // [esp-4h] [ebp-C4h]
  SpeedTree::CCore *base_tree; // [esp+10h] [ebp-B0h] BYREF
  SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> base_tree_instances; // [esp+14h] [ebp-ACh] BYREF
  SpeedTree::CForest::SPopulationStats sStats; // [esp+28h] [ebp-98h] BYREF
  SpeedTree::CArray<SpeedTree::CCore *,1> base_trees; // [esp+70h] [ebp-50h] BYREF
  SpeedTree::CForest::SCompletePopulation sWholePop; // [esp+84h] [ebp-3Ch] BYREF
  SpeedTree::CArray<SpeedTree::CInstance,1> tNew; // [esp+ACh] [ebp-14h] BYREF

  SpeedTree::CForest::ClearInstances(thisa->m_forest, 0, 1);
  v21 = thisa->m_trees._M_impl._M_finish - thisa->m_trees._M_impl._M_start;
  base_trees.__vftable = (SpeedTree::CArray<SpeedTree::CCore *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CCore *,1>::`vftable';
  memset(&base_trees.m_pData, 0, 13);
  base_tree_instances.__vftable = (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::`vftable';
  memset(&base_tree_instances.m_pData, 0, 13);
  SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(&base_trees, v21);
  v22 = thisa->m_trees._M_impl._M_finish - thisa->m_trees._M_impl._M_start;
  SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::reserve(
    (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *)v22,
    (int)&base_tree_instances,
    v22);
  for ( i = thisa->m_trees._M_impl._M_start; i != thisa->m_trees._M_impl._M_finish; ++i )
  {
    if ( i->m_object )
      base_tree = (SpeedTree::CCore *)&i->m_object[1];
    else
      base_tree = 0;
    SpeedTree::CArray<SpeedTree::CCore *,1>::push_back(&base_trees, &base_tree);
    tNew.__vftable = (SpeedTree::CArray<SpeedTree::CInstance,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CInstance,1>::`vftable';
    memset(&tNew.m_pData, 0, 13);
    SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::push_back(v4, (int)&base_tree_instances, &tNew);
    base_tree = 0;
    SpeedTree::st_delete_array<SpeedTree::CInstance>((SpeedTree::CInstance **)&base_tree);
  }
  M_start = thisa->m_trees._M_impl._M_start;
  if ( M_start != thisa->m_trees._M_impl._M_finish )
  {
    base_tree = (SpeedTree::CCore *)base_tree_instances.m_pData;
    do
    {
      for ( j = thisa->m_tree_instances._M_impl._M_start; j != thisa->m_tree_instances._M_impl._M_finish; ++j )
      {
        if ( j->m_object->m_speedtree_tree_ptr.m_object == M_start->m_object )
          SpeedTree::CArray<SpeedTree::CInstance,1>::push_back(
            (SpeedTree::CArray<SpeedTree::CInstance,1> *)base_tree,
            (const SpeedTree::CInstance *)j->m_object[1].__vftable);
      }
      base_tree = (SpeedTree::CCore *)((char *)base_tree + 20);
      ++M_start;
    }
    while ( M_start != thisa->m_trees._M_impl._M_finish );
  }
  m_uiSize = base_trees.m_uiSize;
  sWholePop.m_aBaseTrees.__vftable = (SpeedTree::CArray<SpeedTree::CCore *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CCore *,1>::`vftable';
  memset(&sWholePop.m_aBaseTrees.m_pData, 0, 13);
  sWholePop.m_aaInstances.__vftable = (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::`vftable';
  memset(&sWholePop.m_aaInstances.m_pData, 0, 13);
  if ( SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(&sWholePop.m_aBaseTrees, base_trees.m_uiSize) )
    sWholePop.m_aBaseTrees.m_uiSize = m_uiSize;
  else
    sWholePop.m_aBaseTrees.m_uiSize = sWholePop.m_aBaseTrees.m_uiDataSize;
  if ( SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::reserve(
         v8,
         (int)&sWholePop.m_aaInstances,
         m_uiSize) )
  {
    sWholePop.m_aaInstances.m_uiSize = m_uiSize;
  }
  else
  {
    m_uiDataSize = (SpeedTree::CArray<SpeedTree::CCore *,1> *)sWholePop.m_aaInstances.m_uiDataSize;
    sWholePop.m_aaInstances.m_uiSize = sWholePop.m_aaInstances.m_uiDataSize;
  }
  SpeedTree::CArray<SpeedTree::CCore *,1>::operator=(m_uiDataSize, &sWholePop.m_aBaseTrees, &base_trees);
  SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::operator=(
    v10,
    (int)&sWholePop.m_aaInstances,
    &base_tree_instances);
  if ( SpeedTree::CForest::PopulateAtOnce(thisa->m_forest, &sWholePop) )
  {
    SpeedTree::CForest::UpdateTreeCellExtents(thisa->m_forest);
    SpeedTree::CForest::EndInitialPopulation(thisa->m_forest);
  }
  v12 = thisa->m_trees._M_impl._M_start;
  if ( v12 != thisa->m_trees._M_impl._M_finish )
  {
    m_pData = base_tree_instances.m_pData;
    do
    {
      if ( LOBYTE(v12->m_object[2].m_sub_fat.m_object) )
      {
        m_next_for_query_finished_callback = (vostok::render::speedtree_tree_component_billboard *)v12->m_object[13].m_next_for_query_finished_callback;
        if ( m_next_for_query_finished_callback )
        {
          if ( m_pData->m_uiSize )
            vostok::render::speedtree_tree_component_billboard::init(
              v11,
              m_next_for_query_finished_callback,
              thisa,
              m_pData);
        }
      }
      ++v12;
      ++m_pData;
    }
    while ( v12 != thisa->m_trees._M_impl._M_finish );
  }
  memset(&sStats, 255, 12);
  sStats.m_fAverageNumInstancesPerBase = -1.0;
  sStats.m_nMaxNumBillboardsPerCell = -1;
  sStats.m_nMaxNumInstancesPerCell = -1;
  sStats.m_mMaxNumInstancesPerCellPerBase.__vftable = (SpeedTree::CMap<SpeedTree::CCore const *,int,1>_vtbl *)&SpeedTree::CMap<SpeedTree::CCore const *,int,1>::`vftable';
  sStats.m_mMaxNumInstancesPerCellPerBase.m_pRoot = 0;
  sStats.m_mMaxNumInstancesPerCellPerBase.m_uiSize = 0;
  sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.__vftable = (SpeedTree::CBlockPool<1>_vtbl *)&SpeedTree::CBlockPool<1>::`vftable';
  memset(&sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.m_pData, 0, 16);
  sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.m_uiBlockSize = 24;
  SpeedTree::CBlockPool<1>::resize(&sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool, 0xAu);
  m_forest = thisa->m_forest;
  sStats.m_fAverageInstancesPerCell = -1.0;
  sStats.m_nMaxNumBillboardImages = -1;
  SpeedTree::CForest::GetPopulationStats(m_forest, &sStats);
  sStats.m_mMaxNumInstancesPerCellPerBase.__vftable = (SpeedTree::CMap<SpeedTree::CCore const *,int,1>_vtbl *)&SpeedTree::CMap<SpeedTree::CCore const *,int,1>::`vftable';
  if ( sStats.m_mMaxNumInstancesPerCellPerBase.m_pRoot )
  {
    SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CNode::DeleteChildren(
      (SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CNode *)&sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.m_pData[(unsigned int)sStats.m_mMaxNumInstancesPerCellPerBase.m_pRoot],
      &sStats.m_mMaxNumInstancesPerCellPerBase);
    sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.m_pFreeLocations[sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.m_uiCurrent++] = (unsigned int)sStats.m_mMaxNumInstancesPerCellPerBase.m_pRoot;
    sStats.m_mMaxNumInstancesPerCellPerBase.m_pRoot = 0;
  }
  sStats.m_mMaxNumInstancesPerCellPerBase.m_uiSize = 0;
  sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.__vftable = (SpeedTree::CBlockPool<1>_vtbl *)&SpeedTree::CBlockPool<1>::`vftable';
  if ( !sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.m_pData
    || (v16 = sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.m_pData - 4,
        sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.m_pData == (char *)4) )
  {
    v17 = (SpeedTree::CForest::SCompletePopulation *)SpeedTree::g_pAllocator;
  }
  else
  {
    SpeedTree::g_siHeapMemoryUsed += -4 - *(_DWORD *)v16;
    v17 = (SpeedTree::CForest::SCompletePopulation *)SpeedTree::g_pAllocator;
    if ( SpeedTree::g_pAllocator )
    {
      SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v16);
      v17 = (SpeedTree::CForest::SCompletePopulation *)SpeedTree::g_pAllocator;
    }
    sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.m_pData = 0;
  }
  if ( sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.m_pFreeLocations )
  {
    v18 = sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.m_pFreeLocations - 1;
    if ( sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.m_pFreeLocations != (unsigned int *)4 )
    {
      SpeedTree::g_siHeapMemoryUsed += -4 - 4 * *v18;
      if ( v17 )
        ((void (__thiscall *)(SpeedTree::CForest::SCompletePopulation *, unsigned int *))v17->m_aBaseTrees.__vftable[2].~SpeedTree::CArray<SpeedTree::CCore *,1>)(
          v17,
          v18);
    }
  }
  memset(&sStats.m_mMaxNumInstancesPerCellPerBase.m_cPool.m_pData, 0, 16);
  SpeedTree::CForest::SCompletePopulation::~SCompletePopulation(v17, (int)&sWholePop);
  base_tree_instances.__vftable = (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::`vftable';
  if ( !base_tree_instances.m_bExternalMemory
    || (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::SetExternalMemory(
          v19,
          (int)&base_tree_instances),
        !base_tree_instances.m_bExternalMemory) )
  {
    base_tree = (SpeedTree::CCore *)base_tree_instances.m_pData;
    SpeedTree::st_delete_array<SpeedTree::CArray<SpeedTree::CInstance,1>>((SpeedTree::CArray<SpeedTree::CInstance,1> **)&base_tree);
  }
  if ( !base_trees.m_bExternalMemory )
  {
    if ( base_trees.m_pData )
    {
      v20 = base_trees.m_pData - 1;
      if ( base_trees.m_pData != (SpeedTree::CCore **)4 )
      {
        SpeedTree::g_siHeapMemoryUsed += -4 - 4 * (_DWORD)*v20;
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v20);
      }
    }
  }
}
