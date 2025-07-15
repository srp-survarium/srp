void __thiscall Scaleform::Render::Text::Style::Style(
        Scaleform::Render::Text::Style *this,
        Scaleform::MemoryHeap *pheap)
{
  this->mTextFormat.RefCount = 1;
  Scaleform::StringDH::StringDH(&this->mTextFormat.FontList, pheap);
  Scaleform::StringDH::StringDH(&this->mTextFormat.Url, pheap);
  this->mTextFormat.pImageDesc.pObject = 0;
  this->mTextFormat.pFontHandle.pObject = 0;
  this->mTextFormat.FormatFlags = 0;
  this->mTextFormat.ColorV = -16777216;
  this->mTextFormat.LetterSpacing = 0;
  this->mTextFormat.PresentMask = 0;
  this->mTextFormat.FontSize = 0;
  this->mParagraphFormat.pTabStops = 0;
  this->mParagraphFormat.Indent = 0;
  this->mParagraphFormat.RightMargin = 0;
  this->mParagraphFormat.RefCount = 1;
  this->mParagraphFormat.BlockIndent = 0;
  this->mParagraphFormat.Leading = 0;
  this->mParagraphFormat.LeftMargin = 0;
  this->mParagraphFormat.PresentMask = 0;
}
