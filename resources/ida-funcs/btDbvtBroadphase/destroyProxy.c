void __thiscall btDbvtBroadphase::destroyProxy(btDbvtBroadphase *this, btDbvtProxy *absproxy, btDispatcher *dispatcher)
{
  btDbvt *m_sets; // esi

  m_sets = &this->m_sets[1];
  if ( absproxy->stage != 2 )
    m_sets = this->m_sets;
  btDbvt::remove(m_sets, absproxy->leaf);
  listremove_btDbvtProxy_(absproxy, &this->m_stageRoots[absproxy->stage]);
  this->m_paircache->removeOverlappingPairsContainingProxy(this->m_paircache, absproxy, dispatcher);
  btAlignedFreeInternal(absproxy);
  this->m_needcleanup = 1;
}
