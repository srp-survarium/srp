unsigned int __thiscall Scaleform::Render::TreeNodeArray::calcRemoveCapacity(
        Scaleform::Render::TreeNodeArray *this,
        unsigned int oldCapacity,
        unsigned int newSize)
{
  unsigned int result; // eax

  result = oldCapacity;
  if ( oldCapacity >> 1 >= newSize && oldCapacity > 0xA )
    return ((newSize + 1) & 0xFFFFFFFC) + 2;
  return result;
}
