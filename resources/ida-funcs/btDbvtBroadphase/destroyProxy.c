void __thiscall btDbvtBroadphase::destroyProxy(
        btDbvtBroadphase *this,
        btBroadphaseProxy *absproxy,
        btDispatcher *dispatcher)
{
  btDbvtNode *m_clientObject; // ebp
  btDbvt *m_sets; // edi
  btDbvtNode *m_free; // eax
  int v7; // eax
  _DWORD *m_multiSapParentProxy; // eax

  m_clientObject = (btDbvtNode *)absproxy[1].m_clientObject;
  m_sets = &this->m_sets[1];
  if ( absproxy[1].m_uniqueId != 2 )
    m_sets = this->m_sets;
  removeleaf(m_sets, (btDbvtNode *)absproxy[1].m_clientObject);
  m_free = m_sets->m_free;
  if ( m_free )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_free);
  }
  --m_sets->m_leaves;
  m_sets->m_free = m_clientObject;
  v7 = *(_DWORD *)&absproxy[1].m_collisionFilterGroup;
  if ( v7 )
    *(_DWORD *)(v7 + 56) = absproxy[1].m_multiSapParentProxy;
  else
    this->m_stageRoots[absproxy[1].m_uniqueId] = (btDbvtProxy *)absproxy[1].m_multiSapParentProxy;
  m_multiSapParentProxy = absproxy[1].m_multiSapParentProxy;
  if ( m_multiSapParentProxy )
    m_multiSapParentProxy[13] = *(_DWORD *)&absproxy[1].m_collisionFilterGroup;
  this->m_paircache->removeOverlappingPairsContainingProxy(this->m_paircache, absproxy, dispatcher);
  ++gNumAlignedFree;
  sAlignedFreeFunc(absproxy);
  this->m_needcleanup = 1;
}
