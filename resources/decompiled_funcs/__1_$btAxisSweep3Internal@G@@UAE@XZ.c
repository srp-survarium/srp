void __thiscall btAxisSweep3Internal<unsigned short>::~btAxisSweep3Internal<unsigned short>(
        btAxisSweep3Internal<unsigned short> *this)
{
  bool v2; // zf
  btOverlappingPairCache *m_nullPairCache; // eax
  btDbvtBroadphase *m_raycastAccelerator; // eax
  int v5; // edi
  void **v6; // ebx
  void *v7; // eax
  btAxisSweep3Internal<unsigned short>::Handle *m_pHandles; // eax
  btOverlappingPairCache *m_pairCache; // eax

  v2 = this->m_raycastAccelerator == 0;
  this->__vftable = (btAxisSweep3Internal<unsigned short>_vtbl *)&btAxisSweep3Internal<unsigned short>::`vftable';
  if ( !v2 )
  {
    ((void (__thiscall *)(btOverlappingPairCache *, _DWORD))this->m_nullPairCache->~btOverlappingPairCache)(
      this->m_nullPairCache,
      0);
    m_nullPairCache = this->m_nullPairCache;
    if ( m_nullPairCache )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_nullPairCache);
    }
    ((void (__thiscall *)(btDbvtBroadphase *, _DWORD))this->m_raycastAccelerator->~btDbvtBroadphase)(
      this->m_raycastAccelerator,
      0);
    m_raycastAccelerator = this->m_raycastAccelerator;
    if ( m_raycastAccelerator )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_raycastAccelerator);
    }
  }
  v5 = 2;
  v6 = &this->m_pEdgesRawPtr[2];
  do
  {
    v7 = *v6;
    if ( *v6 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v7);
    }
    --v5;
    --v6;
  }
  while ( v5 >= 0 );
  m_pHandles = this->m_pHandles;
  if ( m_pHandles )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_pHandles);
  }
  if ( this->m_ownsPairCache )
  {
    ((void (__thiscall *)(btOverlappingPairCache *, _DWORD))this->m_pairCache->~btOverlappingPairCache)(
      this->m_pairCache,
      0);
    m_pairCache = this->m_pairCache;
    if ( m_pairCache )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_pairCache);
    }
  }
  this->__vftable = (btAxisSweep3Internal<unsigned short>_vtbl *)&btBroadphaseInterface::`vftable';
}
