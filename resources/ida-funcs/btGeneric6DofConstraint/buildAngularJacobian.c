void __userpurge btGeneric6DofConstraint::buildAngularJacobian(
        btGeneric6DofConstraint *this@<ecx>,
        btJacobianEntry *jacAngular@<eax>,
        const btVector3 *jointAxisW)
{
  if ( jacAngular )
    btJacobianEntry::btJacobianEntry(jacAngular, &this->m_rbA->m_invInertiaLocal);
}
