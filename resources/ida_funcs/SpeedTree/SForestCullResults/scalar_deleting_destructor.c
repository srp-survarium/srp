SpeedTree::SForestCullResults *__thiscall SpeedTree::SForestCullResults::`scalar deleting destructor'(
        SpeedTree::SForestCullResults *this,
        char a2)
{
  SpeedTree::SForestCullResults::~SForestCullResults(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
