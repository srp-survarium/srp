void __userpurge btPolyhedralConvexAabbCachingShape::getAabb(
        btPolyhedralConvexAabbCachingShape *this@<ecx>,
        const float *a2@<edi>,
        btPolyhedralConvexAabbCachingShape *trans,
        const btTransform *aabbMin,
        btVector3 *aabbMax)
{
  float v6; // [esp+0h] [ebp-8h]
  float v7; // [esp+4h] [ebp-4h]

  v6 = this->getMargin(this);
  btPolyhedralConvexAabbCachingShape::getNonvirtualAabb(
    trans,
    (float *)this,
    a2,
    aabbMin,
    aabbMax,
    (btVector3 *)LODWORD(v6),
    v7);
}
