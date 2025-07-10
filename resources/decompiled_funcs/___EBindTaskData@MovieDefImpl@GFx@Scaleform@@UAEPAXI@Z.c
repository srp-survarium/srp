Scaleform::GFx::MovieDefImpl::BindTaskData *__thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::`vector deleting destructor'(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        char a2)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData::~BindTaskData(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
