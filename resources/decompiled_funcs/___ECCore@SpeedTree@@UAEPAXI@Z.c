SpeedTree::CCore *__thiscall SpeedTree::CCore::`vector deleting destructor'(SpeedTree::CCore *this, char a2)
{
  SpeedTree::CCore::~CCore(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
