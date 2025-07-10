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
