void __thiscall Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(Scaleform::Render::Text::GFxLineCursor *this)
{
  Scaleform::Render::Text::TextFormat *pObject; // esi
  bool v3; // zf
  Scaleform::Render::Text::TextFormat *v4; // esi
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx

  pObject = this->CharInfoHolder.pFormat.pObject;
  if ( pObject )
  {
    v3 = pObject->RefCount-- == 1;
    if ( v3 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  v4 = this->CharIter.PlaceHolder.pFormat.pObject;
  if ( v4 )
  {
    v3 = v4->RefCount-- == 1;
    if ( v3 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v4);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  v5 = (Scaleform::RefCountVImpl *)this->pComposStr.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (Scaleform::RefCountVImpl *)this->pLastFont.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
}
