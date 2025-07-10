void __thiscall btConeTwistConstraint::setFrames(
        btConeTwistConstraint *this,
        const btTransform *frameA,
        const btTransform *frameB)
{
  this->m_rbAFrame = *frameA;
  this->m_rbBFrame = *frameB;
  this->buildJacobian(this);
}
