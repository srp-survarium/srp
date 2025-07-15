void __userpurge btRigidBody::predictIntegratedTransform(
        btRigidBody *this@<ecx>,
        long double a2@<esi:edi>,
        float timeStep,
        btTransform *predictedTransform)
{
  btTransformUtil::integrateTransform(
    &this->m_linearVelocity,
    a2,
    &this->m_worldTransform,
    &this->m_angularVelocity,
    timeStep,
    predictedTransform);
}
