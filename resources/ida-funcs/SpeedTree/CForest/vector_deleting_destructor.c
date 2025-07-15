SpeedTree::CForest *__thiscall SpeedTree::CForest::`vector deleting destructor'(SpeedTree::CForest *this, char a2)
{
  SpeedTree::CForest::~CForest(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
