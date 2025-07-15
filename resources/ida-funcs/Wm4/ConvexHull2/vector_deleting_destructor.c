Wm4::ConvexHull2<float> *__thiscall Wm4::ConvexHull2<float>::`vector deleting destructor'(
        Wm4::ConvexHull2<float> *this,
        char a2)
{
  Wm4::ConvexHull2<float>::~ConvexHull2<float>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
