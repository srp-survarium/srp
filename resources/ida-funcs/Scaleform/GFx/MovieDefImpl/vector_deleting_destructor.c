Scaleform::GFx::MovieDefImpl *__thiscall Scaleform::GFx::MovieDefImpl::`vector deleting destructor'(
        Scaleform::GFx::MovieDefImpl *this,
        char a2)
{
  Scaleform::GFx::MovieDefImpl::~MovieDefImpl(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


void *__thiscall Scaleform::GFx::MovieDefImpl::`vector deleting destructor'(char *this, unsigned int a2)
{
  return Scaleform::GFx::MovieDefImpl::`vector deleting destructor'((Scaleform::GFx::MovieDefImpl *)(this - 12), a2);
}
