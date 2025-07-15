btCompoundShape *__thiscall btCompoundShape::`scalar deleting destructor'(btCompoundShape *this, char a2)
{
  btCompoundShape::~btCompoundShape(this);
  if ( (a2 & 1) != 0 && this )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(this);
  }
  return this;
}
