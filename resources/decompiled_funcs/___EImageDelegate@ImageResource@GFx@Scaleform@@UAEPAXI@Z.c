Scaleform::GFx::ImageResource::ImageDelegate *__thiscall Scaleform::GFx::ImageResource::ImageDelegate::`vector deleting destructor'(
        Scaleform::GFx::ImageResource::ImageDelegate *this,
        char a2)
{
  Scaleform::Render::Image *pObject; // ecx

  pObject = this->pImage.pObject;
  if ( pObject )
    pObject->Release(pObject);
  Scaleform::Render::Image::~Image(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
