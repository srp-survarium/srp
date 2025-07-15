btDbvtBroadphase *__thiscall btDbvtBroadphase::`scalar deleting destructor'(btDbvtBroadphase *this, char a2)
{
  bool v3; // zf

  v3 = !this->m_releasepaircache;
  this->__vftable = (btDbvtBroadphase_vtbl *)&btDbvtBroadphase::`vftable';
  if ( !v3 )
  {
    ((void (__thiscall *)(btOverlappingPairCache *, _DWORD))this->m_paircache->~btOverlappingPairCache)(
      this->m_paircache,
      0);
    btAlignedFreeInternal(this->m_paircache);
  }
  `vector destructor iterator'((char *)this->m_sets, 0x28u, 2, (void (__thiscall *)(void *))btDbvt::~btDbvt);
  this->__vftable = (btDbvtBroadphase_vtbl *)&btBroadphaseInterface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
