void __usercall btCollisionObject::setWorldTransform(
        btCollisionObject *this@<ecx>,
        const btTransform *worldTrans@<eax>)
{
  this->m_worldTransform = *worldTrans;
}
