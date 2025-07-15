void *__thiscall Scaleform::SysAllocPagedMalloc::Alloc(
        Scaleform::SysAllocPagedMalloc *this,
        unsigned int size,
        unsigned int __formal)
{
  void *result; // eax

  result = malloc(size);
  if ( result )
  {
    this->Footprint += size;
    if ( (unsigned int)result < this->Base )
      this->Base = (unsigned int)result;
  }
  return result;
}
