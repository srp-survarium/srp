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


BOOL __thiscall Scaleform::Render::Text::TextFormat::operator==(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::Render::Text::TextFormat *f)
{
  unsigned __int16 PresentMask; // ax
  unsigned __int16 v4; // cx
  bool v5; // cl
  Scaleform::Render::Text::FontHandle *v6; // ecx
  Scaleform::Render::Text::FontHandle *v7; // eax
  bool IsUrlSet; // bl
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // esi
  BOOL result; // eax

  PresentMask = f->PresentMask;
  v4 = this->PresentMask;
  result = 0;
  if ( v4 == PresentMask
    && this->FormatFlags == f->FormatFlags
    && this->ColorV == f->ColorV
    && this->FontSize == f->FontSize )
  {
    v5 = (v4 & 4) != 0;
    if ( v5 == ((PresentMask & 4) != 0)
      && (!v5 || !Scaleform::String::CompareNoCase(&this->FontList, &f->FontList))
      && this->LetterSpacing == f->LetterSpacing
      && ((this->PresentMask & 0x800) != 0) == ((f->PresentMask & 0x800) != 0) )
    {
      if ( (this->PresentMask & 0x800) == 0
        || (v6 = this->pFontHandle.pObject, v7 = f->pFontHandle.pObject, v6 == v7)
        || v6 && v7 && Scaleform::Render::Text::FontHandle::operator==(v6, f->pFontHandle.pObject) )
      {
        IsUrlSet = Scaleform::Render::Text::TextFormat::IsUrlSet(f);
        if ( Scaleform::Render::Text::TextFormat::IsUrlSet(this) == IsUrlSet
          && (!Scaleform::Render::Text::TextFormat::IsUrlSet(this)
           || !Scaleform::String::CompareNoCase(&this->Url, &f->Url)) )
        {
          pObject = this->pImageDesc.pObject;
          if ( pObject )
          {
            if ( f->pImageDesc.pObject
              && Scaleform::Render::Text::HTMLImageTagDesc::operator==(pObject, f->pImageDesc.pObject) )
            {
              return 1;
            }
          }
          if ( pObject == f->pImageDesc.pObject )
            return 1;
        }
      }
    }
  }
  return result;
}
