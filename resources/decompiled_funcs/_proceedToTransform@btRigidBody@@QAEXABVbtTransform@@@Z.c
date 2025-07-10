void __usercall btRigidBody::proceedToTransform(btRigidBody *this@<ecx>, int a2@<eax>)
{
  btRigidBody::setCenterOfMassTransform(this, a2);
}
