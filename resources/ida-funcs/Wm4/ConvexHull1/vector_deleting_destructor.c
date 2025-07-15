Wm4::ConvexHull1<float> *__thiscall Wm4::ConvexHull1<float>::`vector deleting destructor'(
        Wm4::ConvexHull1<float> *this,
        char a2)
{
  Wm4::ConvexHull1<float>::~ConvexHull1<float>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
