void __userpurge btSoftBodyConcaveCollisionAlgorithm::calculateTimeOfImpact_::_5_::LocalTriangleSphereCastCallback::LocalTriangleSphereCastCallback(
        const btTransform *from@<edx>,
        const btTransform *to@<ecx>,
        btSoftBodyConcaveCollisionAlgorithm::calculateTimeOfImpact::__l5::LocalTriangleSphereCastCallback *this,
        float ccdSphereRadius,
        float hitFraction)
{
  this->__vftable = (btSoftBodyConcaveCollisionAlgorithm::calculateTimeOfImpact::__l5::LocalTriangleSphereCastCallback_vtbl *)&`btSoftBodyConcaveCollisionAlgorithm::calculateTimeOfImpact'::`5'::LocalTriangleSphereCastCallback::`vftable';
  this->m_ccdSphereFromTrans = *from;
  this->m_ccdSphereToTrans = *to;
  this->m_ccdSphereRadius = ccdSphereRadius;
  LODWORD(this->m_hitFraction) = clear_value;
}
