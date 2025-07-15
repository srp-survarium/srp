btConvexHullShape *__thiscall btConvexHullShape::`scalar deleting destructor'(btConvexHullShape *this, char a2)
{
  btConvexHullShape::~btConvexHullShape(this);
  if ( (a2 & 1) != 0 && this )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(this);
  }
  return this;
}
