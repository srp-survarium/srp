void __thiscall btBvhTriangleMeshShape::~btBvhTriangleMeshShape(btBvhTriangleMeshShape *this)
{
  bool v2; // zf
  btOptimizedBvh *m_bvh; // eax

  v2 = !this->m_ownsBvh;
  this->__vftable = (btBvhTriangleMeshShape_vtbl *)&btBvhTriangleMeshShape::`vftable';
  if ( !v2 )
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
}
