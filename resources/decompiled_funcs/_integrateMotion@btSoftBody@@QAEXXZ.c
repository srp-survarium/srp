void __usercall btSoftBody::integrateMotion(btSoftBody *this@<ecx>, btSoftBody *a2@<eax>)
{
  btSoftBody::updateNormals(this, a2);
}
