btGhostObject *__thiscall btGhostObject::`vector deleting destructor'(btGhostObject *this, char a2)
{
  btGhostObject::~btGhostObject(this);
  if ( (a2 & 1) != 0 && this )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(this);
  }
  return this;
}
