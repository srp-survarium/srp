btQuantizedBvh *__thiscall btQuantizedBvh::`scalar deleting destructor'(btQuantizedBvh *this, char a2)
{
  btQuantizedBvh::~btQuantizedBvh(this);
  if ( (a2 & 1) != 0 && this )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc((void *)this);
  }
  return this;
}
