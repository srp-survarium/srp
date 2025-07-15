btBvhTriangleMeshShape *__thiscall btBvhTriangleMeshShape::`vector deleting destructor'(
        btBvhTriangleMeshShape *this,
        char a2)
{
  bool v3; // zf
  btOptimizedBvh *m_bvh; // eax

  v3 = !this->m_ownsBvh;
  this->__vftable = (btBvhTriangleMeshShape_vtbl *)&btBvhTriangleMeshShape::`vftable';
  if ( !v3 )
  {
    ((void (__thiscall *)(btOptimizedBvh *, _DWORD))this->m_bvh->~btOptimizedBvh)(this->m_bvh, 0);
    m_bvh = this->m_bvh;
    if ( m_bvh )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_bvh);
    }
  }
  this->__vftable = (btBvhTriangleMeshShape_vtbl *)&btCollisionShape::`vftable';
  if ( (a2 & 1) != 0 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(this);
  }
  return this;
}
