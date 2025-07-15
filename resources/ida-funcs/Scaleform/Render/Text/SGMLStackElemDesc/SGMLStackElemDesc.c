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


void __thiscall Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>::SGMLStackElemDesc<wchar_t>(
        Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *this,
        Scaleform::MemoryHeap *pheap,
        const wchar_t *pname,
        unsigned int sz,
        const Scaleform::Render::Text::SGMLElementDesc *pelemDesc,
        unsigned int startPos)
{
  this->pElemName = pname;
  this->ElemNameSize = sz;
  this->pElemDesc = pelemDesc;
  this->StartPos = startPos;
  this->TextFmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&this->TextFmt.FontList, pheap);
  Scaleform::StringDH::StringDH(&this->TextFmt.Url, pheap);
  this->TextFmt.pImageDesc.pObject = 0;
  this->TextFmt.pFontHandle.pObject = 0;
  this->TextFmt.FormatFlags = 0;
  this->TextFmt.ColorV = -16777216;
  this->TextFmt.LetterSpacing = 0;
  this->TextFmt.PresentMask = 0;
  this->TextFmt.FontSize = 0;
  this->ParaFmt.pTabStops = 0;
  this->ParaFmt.Indent = 0;
  this->ParaFmt.RightMargin = 0;
  this->ParaFmt.RefCount = 1;
  this->ParaFmt.BlockIndent = 0;
  this->ParaFmt.Leading = 0;
  this->ParaFmt.LeftMargin = 0;
  this->ParaFmt.PresentMask = 0;
}


void __thiscall Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>::SGMLStackElemDesc<wchar_t>(
        Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *this)
{
  Scaleform::MemoryHeap *v2; // edi

  this->pElemName = 0;
  this->ElemNameSize = 0;
  this->pElemDesc = 0;
  v2 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  this->TextFmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&this->TextFmt.FontList, v2);
  Scaleform::StringDH::StringDH(&this->TextFmt.Url, v2);
  this->TextFmt.pImageDesc.pObject = 0;
  this->TextFmt.pFontHandle.pObject = 0;
  this->TextFmt.FormatFlags = 0;
  this->TextFmt.ColorV = -16777216;
  this->TextFmt.LetterSpacing = 0;
  this->TextFmt.FontSize = 0;
  this->TextFmt.PresentMask = 0;
  this->ParaFmt.BlockIndent = 0;
  this->ParaFmt.LeftMargin = 0;
  this->ParaFmt.pTabStops = 0;
  this->ParaFmt.RefCount = 1;
  this->ParaFmt.Indent = 0;
  this->ParaFmt.Leading = 0;
  this->ParaFmt.RightMargin = 0;
  this->ParaFmt.PresentMask = 0;
}
