void __userpurge btRigidBody::predictIntegratedTransform(
        btRigidBody *this@<ecx>,
        btTransform *predictedTransform@<eax>,
        float timeStep)
{
  btTransformUtil::integrateTransform(
    &this->m_worldTransform,
    &this->m_linearVelocity,
    &this->m_angularVelocity,
    timeStep,
    predictedTransform);
}
