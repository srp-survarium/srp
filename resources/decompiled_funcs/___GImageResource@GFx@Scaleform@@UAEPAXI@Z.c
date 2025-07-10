Scaleform::GFx::ImageResource *__thiscall Scaleform::GFx::ImageResource::`scalar deleting destructor'(
        Scaleform::GFx::ImageResource *this,
        char a2)
{
  Scaleform::GFx::ImageResource::~ImageResource(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
