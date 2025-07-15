btOptimizedBvh *__thiscall btOptimizedBvh::`vector deleting destructor'(btOptimizedBvh *this, char a2)
{
  this->__vftable = (btOptimizedBvh_vtbl *)&btOptimizedBvh::`vftable';
  btQuantizedBvh::~btQuantizedBvh(this);
  if ( (a2 & 1) != 0 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(this);
  }
  return this;
}
