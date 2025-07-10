void __usercall btCollisionObject::setInterpolationWorldTransform(
        btCollisionObject *this@<ecx>,
        const btTransform *trans@<eax>)
{
  this->m_interpolationWorldTransform = *trans;
}
