Scaleform::GFx::PathAllocator::Page *__thiscall Scaleform::GFx::PathAllocator::AllocRawPath(
        Scaleform::GFx::PathAllocator *this,
        unsigned int sizeInBytes)
{
  return Scaleform::GFx::PathAllocator::AllocMemoryBlock(this, sizeInBytes, sizeInBytes);
}
