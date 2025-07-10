Scaleform::GFx::LoaderImpl *__thiscall Scaleform::GFx::LoaderImpl::`vector deleting destructor'(
        Scaleform::GFx::LoaderImpl *this,
        char a2)
{
  Scaleform::GFx::LoaderImpl::~LoaderImpl(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
