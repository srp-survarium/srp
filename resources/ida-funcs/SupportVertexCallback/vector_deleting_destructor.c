btSoftBodyConcaveCollisionAlgorithm::calculateTimeOfImpact::__l5::LocalTriangleSphereCastCallback *__thiscall SupportVertexCallback::`vector deleting destructor'(
        btSoftBodyConcaveCollisionAlgorithm::calculateTimeOfImpact::__l5::LocalTriangleSphereCastCallback *this,
        char a2)
{
  this->__vftable = (btSoftBodyConcaveCollisionAlgorithm::calculateTimeOfImpact::__l5::LocalTriangleSphereCastCallback_vtbl *)&btTriangleCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
