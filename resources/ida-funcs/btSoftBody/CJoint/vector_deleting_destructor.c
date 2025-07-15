btSoftBody::CJoint *__thiscall btSoftBody::CJoint::`vector deleting destructor'(btSoftBody::CJoint *this, char a2)
{
  this->__vftable = (btSoftBody::CJoint_vtbl *)&btSoftBody::Joint::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
