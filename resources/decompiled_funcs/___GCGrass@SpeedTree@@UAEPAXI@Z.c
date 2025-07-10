SpeedTree::CGrass *__thiscall SpeedTree::CGrass::`scalar deleting destructor'(SpeedTree::CGrass *this, char a2)
{
  SpeedTree::CGrass::~CGrass(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
