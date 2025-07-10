Scaleform::Render::FilterEffect *__thiscall Scaleform::Render::FilterEffect::`scalar deleting destructor'(
        Scaleform::Render::FilterEffect *this,
        char a2)
{
  Scaleform::Render::FilterEffect::~FilterEffect(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
