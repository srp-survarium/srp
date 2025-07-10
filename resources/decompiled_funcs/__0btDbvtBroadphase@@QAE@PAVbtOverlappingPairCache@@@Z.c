void __usercall btDbvtBroadphase::btDbvtBroadphase(
        btDbvtBroadphase *this@<esi>,
        btHashedOverlappingPairCache *paircache@<edi>)
{
  btHashedOverlappingPairCache *v2; // eax
  btHashedOverlappingPairCache *v3; // ecx

  this->__vftable = (btDbvtBroadphase_vtbl *)&btDbvtBroadphase::`vftable';
  `vector constructor iterator'((char *)this->m_sets, 0x28u, 2, (void *(__thiscall *)(void *))btDbvt::btDbvt);
  this->m_deferedcollide = 0;
  this->m_needcleanup = 1;
  this->m_releasepaircache = paircache == 0;
  this->m_prediction = 0.0;
  this->m_stageCurrent = 0;
  this->m_fixedleft = 0;
  this->m_fupdates = 1;
  this->m_dupdates = 0;
  this->m_cupdates = 10;
  this->m_newpairs = 1;
  this->m_updates_call = 0;
  this->m_updates_done = 0;
  this->m_updates_ratio = 0.0;
  if ( paircache )
  {
    v2 = paircache;
  }
  else
  {
    ++gNumAlignedAllocs;
    if ( sAlignedAllocFunc(0x4Cu, 16) )
      v2 = btHashedOverlappingPairCache::btHashedOverlappingPairCache(v3);
    else
      v2 = 0;
  }
  this->m_paircache = v2;
  this->m_gid = 0;
  this->m_pid = 0;
  this->m_cid = 0;
  this->m_stageRoots[0] = 0;
  this->m_stageRoots[1] = 0;
  this->m_stageRoots[2] = 0;
}
