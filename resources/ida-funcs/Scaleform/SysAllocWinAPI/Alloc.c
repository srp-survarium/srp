void *__thiscall Scaleform::SysAllocWinAPI::Alloc(
        Scaleform::SysAllocWinAPI *this,
        unsigned int size,
        unsigned int align)
{
  return this->pAllocator->Alloc(this->pAllocator, size, align);
}
