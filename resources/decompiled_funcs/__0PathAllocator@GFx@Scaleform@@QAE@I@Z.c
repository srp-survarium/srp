void __thiscall Scaleform::GFx::PathAllocator::PathAllocator(
        Scaleform::GFx::PathAllocator *this,
        unsigned __int16 pageSize)
{
  this->pFirstPage = 0;
  this->pLastPage = 0;
  this->FreeBytes = 0;
  this->DefaultPageSize = pageSize;
}
