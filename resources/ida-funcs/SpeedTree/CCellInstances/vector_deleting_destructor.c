SpeedTree::CCellInstances *__thiscall SpeedTree::CCellInstances::`vector deleting destructor'(
        SpeedTree::CCellInstances *this,
        char a2)
{
  SpeedTree::CCellInstances::~CCellInstances(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
