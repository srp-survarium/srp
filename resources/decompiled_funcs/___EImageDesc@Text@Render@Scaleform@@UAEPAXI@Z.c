Scaleform::Render::Text::ImageDesc *__thiscall Scaleform::Render::Text::ImageDesc::`vector deleting destructor'(
        Scaleform::Render::Text::ImageDesc *this,
        char a2)
{
  Scaleform::Render::Image *pObject; // ecx

  pObject = this->pImage.pObject;
  if ( pObject )
    pObject->Release(pObject);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
