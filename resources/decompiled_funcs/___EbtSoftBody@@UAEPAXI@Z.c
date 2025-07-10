btSoftBody *__thiscall btSoftBody::`vector deleting destructor'(btSoftBody *this, char a2)
{
  btSoftBody::~btSoftBody(this);
  if ( (a2 & 1) != 0 && this )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(this);
  }
  return this;
}
