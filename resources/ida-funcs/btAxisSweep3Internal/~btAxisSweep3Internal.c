void __thiscall btAxisSweep3Internal<unsigned short>::~btAxisSweep3Internal<unsigned short>(
        btAxisSweep3Internal<unsigned short> *this)
{
  int v2; // ebp
  void **v3; // edi

  this->__vftable = (btAxisSweep3Internal<unsigned short>_vtbl *)&btAxisSweep3Internal<unsigned short>::`vftable';
  if ( this->m_raycastAccelerator )
  {
    ((void (__thiscall *)(btOverlappingPairCache *, _DWORD))this->m_nullPairCache->~btOverlappingPairCache)(
      this->m_nullPairCache,
      0);
    btAlignedFreeInternal(this->m_nullPairCache);
    ((void (__thiscall *)(btDbvtBroadphase *, _DWORD))this->m_raycastAccelerator->~btDbvtBroadphase)(
      this->m_raycastAccelerator,
      0);
    btAlignedFreeInternal(this->m_raycastAccelerator);
  }
  v2 = 2;
  v3 = &this->m_pEdgesRawPtr[2];
  do
  {
    btAlignedFreeInternal(*v3);
    --v2;
    --v3;
  }
  while ( v2 >= 0 );
  btAlignedFreeInternal(this->m_pHandles);
  if ( this->m_ownsPairCache )
  {
    ((void (__thiscall *)(btOverlappingPairCache *, _DWORD))this->m_pairCache->~btOverlappingPairCache)(
      this->m_pairCache,
      0);
    btAlignedFreeInternal(this->m_pairCache);
  }
  this->__vftable = (btAxisSweep3Internal<unsigned short>_vtbl *)&btBroadphaseInterface::`vftable';
}
