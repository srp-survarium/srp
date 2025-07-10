void __thiscall btConvexHullShape::setLocalScaling(btConvexHullShape *this, const btVector3 *scaling)
{
  this->m_localScaling = (btVector3)scaling->mVec128;
  btPolyhedralConvexAabbCachingShape::recalcLocalAabb(this);
}
