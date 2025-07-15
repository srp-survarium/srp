void __thiscall Scaleform::GFx::DrawTextManager::SetTextParams(
        Scaleform::GFx::DrawTextManager *this,
        Scaleform::Render::Text::DocView *pdoc,
        const Scaleform::GFx::DrawTextManager::TextParams *txtParams,
        const Scaleform::Render::Text::TextFormat *tfmt,
        const Scaleform::Render::Text::ParagraphFormat *pfmt)
{
  Scaleform::MemoryHeap *pHeap; // esi
  unsigned int Raw; // eax
  __int16 v7; // ax
  char v8; // al
  Scaleform::Render::Text::ParagraphFormat defaultParagraphFmt; // [esp+10h] [ebp-40h] BYREF
  Scaleform::Render::Text::TextFormat fmt; // [esp+28h] [ebp-28h] BYREF

  pHeap = this->pHeap;
  fmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&fmt.FontList, pHeap);
  Scaleform::StringDH::StringDH(&fmt.Url, pHeap);
  fmt.LetterSpacing = 0;
  fmt.FormatFlags = 0;
  memset(&defaultParagraphFmt.pTabStops, 0, 16);
  fmt.pImageDesc.pObject = 0;
  fmt.pFontHandle.pObject = 0;
  fmt.ColorV = -16777216;
  fmt.FontSize = 0;
  fmt.PresentMask = 0;
  defaultParagraphFmt.RefCount = 1;
  if ( tfmt )
    Scaleform::Render::Text::TextFormat::operator=(&fmt, tfmt);
  if ( pfmt )
    Scaleform::Render::Text::ParagraphFormat::operator=(&defaultParagraphFmt, pfmt);
  Raw = txtParams->TextColor.Raw;
  fmt.PresentMask |= 1u;
  fmt.ColorV = Raw;
  switch ( txtParams->FontStyle )
  {
    case Normal:
      Scaleform::Render::Text::TextFormat::SetBold(&fmt, 0);
      Scaleform::Render::Text::TextFormat::SetItalic(&fmt, 0);
      break;
    case Bold:
      Scaleform::Render::Text::TextFormat::SetBold(&fmt, 1);
      Scaleform::Render::Text::TextFormat::SetItalic(&fmt, 0);
      break;
    case Italic:
      Scaleform::Render::Text::TextFormat::SetBold(&fmt, 0);
      goto LABEL_10;
    case BoldItalic:
      Scaleform::Render::Text::TextFormat::SetBold(&fmt, 1);
LABEL_10:
      Scaleform::Render::Text::TextFormat::SetItalic(&fmt, 1);
      break;
    default:
      break;
  }
  Scaleform::Render::Text::TextFormat::SetFontName(&fmt, &txtParams->FontName);
  Scaleform::Render::Text::TextFormat::SetFontSize(&fmt, txtParams->FontSize);
  Scaleform::Render::Text::TextFormat::SetUnderline(&fmt, txtParams->Underline);
  switch ( txtParams->HAlignment )
  {
    case Align_TopCenter:
      v7 = 1;
      break;
    case Align_BottomCenter:
      v7 = 3;
      break;
    case Align_CenterLeft:
      v7 = 2;
      break;
    default:
      v7 = 0;
      break;
  }
  defaultParagraphFmt.PresentMask = defaultParagraphFmt.PresentMask
                                  ^ (defaultParagraphFmt.PresentMask
                                   ^ (v7 << 9))
                                  & 0x600
                                  | 1;
  if ( txtParams->VAlignment == VAlign_Center )
  {
    v8 = 3;
  }
  else if ( txtParams->VAlignment == VAlign_Bottom )
  {
    v8 = 2;
  }
  else
  {
    v8 = 1;
  }
  pdoc->RTFlags |= 1u;
  pdoc->AlignProps ^= (pdoc->AlignProps ^ (4 * v8)) & 0xC;
  if ( txtParams->Multiline )
  {
    pdoc->Flags |= 4u;
    if ( txtParams->WordWrap )
      Scaleform::Render::Text::DocView::SetWordWrap(pdoc);
  }
  Scaleform::Render::Text::DocView::SetTextFormat(pdoc, &fmt, 0, 0xFFFFFFFF);
  Scaleform::Render::Text::DocView::SetParagraphFormat(pdoc, &defaultParagraphFmt, 0, 0xFFFFFFFF);
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(pdoc->pDocument.pObject, &fmt);
  Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(pdoc->pDocument.pObject, &defaultParagraphFmt);
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&defaultParagraphFmt);
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
}
