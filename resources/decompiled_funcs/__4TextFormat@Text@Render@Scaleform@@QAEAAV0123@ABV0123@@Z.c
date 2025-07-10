Scaleform::Render::Text::TextFormat *__thiscall Scaleform::Render::Text::TextFormat::operator=(
        Scaleform::Render::Text::TextFormat *this,
        const Scaleform::Render::Text::TextFormat *__that)
{
  Scaleform::StringDH *p_FontList; // ebp
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // eax
  Scaleform::Render::Text::HTMLImageTagDesc *v5; // ecx
  Scaleform::GFx::Resource *v6; // ecx
  Scaleform::RefCountVImpl *v7; // ecx

  p_FontList = &this->FontList;
  this->RefCount = __that->RefCount;
  Scaleform::String::operator=(&this->FontList, &__that->FontList);
  p_FontList->pHeap = __that->FontList.pHeap;
  Scaleform::String::operator=(&this->Url, &__that->Url);
  this->Url.pHeap = __that->Url.pHeap;
  pObject = __that->pImageDesc.pObject;
  if ( pObject )
    ++pObject->RefCount;
  v5 = this->pImageDesc.pObject;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  this->pImageDesc.pObject = __that->pImageDesc.pObject;
  v6 = (Scaleform::GFx::Resource *)__that->pFontHandle.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::AddRef(v6);
  v7 = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  this->pFontHandle.pObject = __that->pFontHandle.pObject;
  this->ColorV = __that->ColorV;
  this->LetterSpacing = __that->LetterSpacing;
  this->FontSize = __that->FontSize;
  this->FormatFlags = __that->FormatFlags;
  this->PresentMask = __that->PresentMask;
  return this;
}
