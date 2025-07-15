SpeedTree::CBlockPool<1> *__thiscall SpeedTree::CBlockPool<1>::`vector deleting destructor'(
        SpeedTree::CBlockPool<1> *this,
        char a2)
{
  this->__vftable = (SpeedTree::CBlockPool<1>_vtbl *)&SpeedTree::CBlockPool<1>::`vftable';
  SpeedTree::CBlockPool<1>::clear(this, 0);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
