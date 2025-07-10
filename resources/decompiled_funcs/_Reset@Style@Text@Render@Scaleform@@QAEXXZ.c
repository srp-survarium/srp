void __thiscall Scaleform::Render::Text::Style::Reset(Scaleform::Render::Text::Style *this)
{
  Scaleform::MemoryHeap *pHeap; // edi
  Scaleform::Render::Text::TextFormat __that; // [esp+Ch] [ebp-28h] BYREF

  pHeap = this->mTextFormat.FontList.pHeap;
  __that.RefCount = 1;
  Scaleform::StringDH::StringDH(&__that.FontList, pHeap);
  Scaleform::StringDH::StringDH(&__that.Url, pHeap);
  __that.LetterSpacing = 0;
  __that.FontSize = 0;
  __that.pImageDesc.pObject = 0;
  __that.pFontHandle.pObject = 0;
  __that.ColorV = -16777216;
  __that.FormatFlags = 0;
  __that.PresentMask = 0;
  Scaleform::Render::Text::TextFormat::operator=(&this->mTextFormat, &__that);
  Scaleform::Render::Text::TextFormat::~TextFormat(&__that);
  __that.RefCount = 1;
  memset(&__that.FontList, 0, 16);
  Scaleform::Render::Text::ParagraphFormat::operator=(
    &this->mParagraphFormat,
    (const Scaleform::Render::Text::ParagraphFormat *)&__that);
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)&__that);
}
