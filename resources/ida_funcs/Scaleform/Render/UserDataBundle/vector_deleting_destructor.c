Scaleform::Render::UserDataBundle *__thiscall Scaleform::Render::UserDataBundle::`vector deleting destructor'(
        Scaleform::Render::UserDataBundle *this,
        char a2)
{
  Scaleform::Render::UserDataBundle::~UserDataBundle(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
