void __thiscall btTriangleMeshShape::setLocalScaling(btTriangleMeshShape *this, const btVector3 *scaling)
{
  this->m_meshInterface->m_scaling = (btVector3)scaling->mVec128;
  btTriangleMeshShape::recalcLocalAabb(this, (float *)this);
}
