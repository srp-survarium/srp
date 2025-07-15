Scaleform::Render::UserDataEffect *__thiscall Scaleform::Render::ProjectionMatrix3DEffect::`vector deleting destructor'(
        Scaleform::Render::UserDataEffect *this,
        char a2)
{
  Scaleform::Render::UserDataEffect::~UserDataEffect(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
