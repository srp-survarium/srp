void __thiscall Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>::SGMLStackElemDesc<wchar_t>(
        Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *this,
        const Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *__that)
{
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // eax
  Scaleform::GFx::Resource *v4; // ecx

  this->pElemName = __that->pElemName;
  this->ElemNameSize = __that->ElemNameSize;
  this->pElemDesc = __that->pElemDesc;
  this->StartPos = __that->StartPos;
  this->TextFmt.RefCount = 1;
  Scaleform::StringDH::CopyConstructHelper(
    &this->TextFmt.FontList,
    &__that->TextFmt.FontList,
    __that->TextFmt.FontList.pHeap);
  Scaleform::StringDH::CopyConstructHelper(&this->TextFmt.Url, &__that->TextFmt.Url, __that->TextFmt.FontList.pHeap);
  pObject = __that->TextFmt.pImageDesc.pObject;
  if ( pObject )
    ++pObject->RefCount;
  this->TextFmt.pImageDesc.pObject = __that->TextFmt.pImageDesc.pObject;
  v4 = (Scaleform::GFx::Resource *)__that->TextFmt.pFontHandle.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->TextFmt.pFontHandle.pObject = __that->TextFmt.pFontHandle.pObject;
  this->TextFmt.ColorV = __that->TextFmt.ColorV;
  this->TextFmt.LetterSpacing = __that->TextFmt.LetterSpacing;
  this->TextFmt.FontSize = __that->TextFmt.FontSize;
  this->TextFmt.FormatFlags = __that->TextFmt.FormatFlags;
  this->TextFmt.PresentMask = __that->TextFmt.PresentMask;
  Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(&this->ParaFmt, &__that->ParaFmt);
}
