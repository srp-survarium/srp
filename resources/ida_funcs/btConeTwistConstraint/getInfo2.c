void __thiscall btConeTwistConstraint::getInfo2(
        btConeTwistConstraint *this,
        btTypedConstraint::btConstraintInfo2 *info)
{
  btConeTwistConstraint::getInfo2NonVirtual(
    this,
    info,
    &this->m_rbA->m_invInertiaTensorWorld,
    &this->m_rbB->m_invInertiaTensorWorld,
    &this->m_rbA->m_worldTransform,
    &this->m_rbB->m_worldTransform);
}
