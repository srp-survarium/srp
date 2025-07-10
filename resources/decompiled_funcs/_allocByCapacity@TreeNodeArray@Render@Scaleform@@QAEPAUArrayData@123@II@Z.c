Scaleform::Render::TreeNodeArray::ArrayData *__thiscall Scaleform::Render::TreeNodeArray::allocByCapacity(
        Scaleform::Render::TreeNodeArray *this,
        unsigned int capacity,
        unsigned int size)
{
  Scaleform::Render::TreeNodeArray::ArrayData *result; // eax

  result = (Scaleform::Render::TreeNodeArray::ArrayData *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                            Scaleform::Memory::pGlobalHeap,
                                                            this,
                                                            4 * capacity + 8,
                                                            0);
  if ( result )
  {
    result->RefCount = 1;
    result->Size = size;
  }
  return result;
}
