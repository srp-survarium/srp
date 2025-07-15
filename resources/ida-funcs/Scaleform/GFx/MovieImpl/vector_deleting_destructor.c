Scaleform::GFx::MovieImpl *__thiscall Scaleform::GFx::MovieImpl::`vector deleting destructor'(
        Scaleform::GFx::MovieImpl *this,
        char a2)
{
  Scaleform::GFx::MovieImpl::~MovieImpl(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


Scaleform::GFx::MovieImpl *__thiscall Scaleform::GFx::MovieImpl::`vector deleting destructor'(char *this, char a2)
{
  return Scaleform::GFx::MovieImpl::`vector deleting destructor'((Scaleform::GFx::MovieImpl *)(this - 8), a2);
}
