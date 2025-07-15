Scaleform::GFx::AMP::MovieProfile *__thiscall Scaleform::GFx::AMP::MovieProfile::`vector deleting destructor'(
        Scaleform::GFx::AMP::MovieProfile *this,
        char a2)
{
  Scaleform::GFx::AMP::MovieProfile::~MovieProfile(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
