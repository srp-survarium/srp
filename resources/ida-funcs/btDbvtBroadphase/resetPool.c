void __thiscall btDbvtBroadphase::resetPool(btDbvtBroadphase *this, btDispatcher *dispatcher)
{
  btDbvt *v3; // ecx
  btDbvtProxy **m_stageRoots; // edi

  if ( !(this->m_sets[0].m_leaves + this->m_sets[1].m_leaves) )
  {
    btDbvt::clear((btDbvt *)this, this->m_sets);
    btDbvt::clear(v3, &this->m_sets[1]);
    this->m_deferedcollide = 0;
    this->m_needcleanup = 1;
    this->m_stageCurrent = 0;
    this->m_fixedleft = 0;
    this->m_fupdates = 1;
    this->m_dupdates = 0;
    this->m_cupdates = 10;
    this->m_newpairs = 1;
    this->m_updates_call = 0;
    this->m_updates_done = 0;
    this->m_updates_ratio = 0.0;
    this->m_gid = 0;
    this->m_pid = 0;
    this->m_cid = 0;
    m_stageRoots = this->m_stageRoots;
    *m_stageRoots++ = 0;
    *m_stageRoots = 0;
    m_stageRoots[1] = 0;
  }
}
