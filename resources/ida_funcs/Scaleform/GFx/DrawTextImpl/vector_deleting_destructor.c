Scaleform::GFx::DrawTextImpl *__thiscall Scaleform::GFx::DrawTextImpl::`vector deleting destructor'(
        Scaleform::GFx::DrawTextImpl *this,
        char a2)
{
  Scaleform::GFx::DrawTextImpl::~DrawTextImpl(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
