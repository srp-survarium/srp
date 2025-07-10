btGImpactCollisionAlgorithm::CreateFunc *__thiscall btSphereSphereCollisionAlgorithm::CreateFunc::`vector deleting destructor'(
        btGImpactCollisionAlgorithm::CreateFunc *this,
        char a2)
{
  this->__vftable = (btGImpactCollisionAlgorithm::CreateFunc_vtbl *)&stru_957BE0.m_sub_fat;
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
