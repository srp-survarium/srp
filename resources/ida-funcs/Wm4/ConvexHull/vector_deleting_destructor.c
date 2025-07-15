Wm4::ConvexHull<float> *__thiscall Wm4::ConvexHull<float>::`vector deleting destructor'(
        Wm4::ConvexHull<float> *this,
        char a2)
{
  Wm4::ConvexHull<float>::~ConvexHull<float>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
