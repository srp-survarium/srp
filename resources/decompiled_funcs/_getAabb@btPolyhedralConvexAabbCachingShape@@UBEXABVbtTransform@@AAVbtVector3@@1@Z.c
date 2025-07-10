void __thiscall btPolyhedralConvexAabbCachingShape::getAabb(
        btPolyhedralConvexAabbCachingShape *this,
        const btTransform *trans,
        const struct btTransform *aabbMin,
        btVector3 *aabbMax)
{
  btPolyhedralConvexAabbCachingShape *v5; // ecx
  struct btVector3 *v6; // [esp+0h] [ebp-10h]
  struct btVector3 *v7; // [esp+4h] [ebp-Ch]
  float v8; // [esp+8h] [ebp-8h]
  float v9; // [esp+Ch] [ebp-4h]

  v9 = this->getMargin(this);
  btPolyhedralConvexAabbCachingShape::getNonvirtualAabb(
    v5,
    (float *)this,
    (unsigned __int64 *)aabbMax,
    (float *)trans,
    v9,
    aabbMin,
    v6,
    v7,
    v8);
}
