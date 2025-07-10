void __thiscall btDbvtBroadphase::~btDbvtBroadphase(btDbvtBroadphase *this, btDbvtBroadphase *thisa)
{
  bool v2; // zf
  btOverlappingPairCache *m_paircache; // eax
  btDbvtProxy **m_stageRoots; // esi
  int v5; // ebx
  int *p_m_cupdates; // edi
  void *v7; // eax

  v2 = !thisa->m_releasepaircache;
  thisa->__vftable = (btDbvtBroadphase_vtbl *)&btDbvtBroadphase::`vftable';
  if ( !v2 )
  {
    ((void (__thiscall *)(btOverlappingPairCache *, _DWORD))thisa->m_paircache->~btOverlappingPairCache)(
      thisa->m_paircache,
      0);
    m_paircache = thisa->m_paircache;
    if ( m_paircache )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_paircache);
    }
  }
  m_stageRoots = thisa->m_stageRoots;
  v5 = 1;
  p_m_cupdates = &thisa->m_cupdates;
  do
  {
    m_stageRoots -= 10;
    p_m_cupdates -= 10;
    btDbvt::clear((btDbvt *)this);
    v7 = (void *)*p_m_cupdates;
    if ( *p_m_cupdates )
    {
      if ( *((_BYTE *)p_m_cupdates + 4) )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(v7);
      }
      *p_m_cupdates = 0;
    }
    --v5;
    *((_BYTE *)p_m_cupdates + 4) = 1;
    *p_m_cupdates = 0;
    *(p_m_cupdates - 2) = 0;
    *(p_m_cupdates - 1) = 0;
  }
  while ( v5 >= 0 );
  thisa->__vftable = (btDbvtBroadphase_vtbl *)&btBroadphaseInterface::`vftable';
}
