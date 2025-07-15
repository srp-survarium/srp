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
  Scaleform::Render::Text::ParagraphFormat paraFmt; // [esp+10h] [ebp-40h] BYREF
  Scaleform::Render::Text::TextFormat textFmt; // [esp+28h] [ebp-28h] BYREF

  pHeap = this->pHeap;
  textFmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&textFmt.FontList, pHeap);
  Scaleform::StringDH::StringDH(&textFmt.Url, pHeap);
  textFmt.LetterSpacing = 0;
  textFmt.FormatFlags = 0;
  memset(&paraFmt.pTabStops, 0, 16);
  textFmt.pImageDesc.pObject = 0;
  textFmt.pFontHandle.pObject = 0;
  textFmt.ColorV = -16777216;
  textFmt.FontSize = 0;
  textFmt.PresentMask = 0;
  paraFmt.RefCount = 1;
  if ( tfmt )
    Scaleform::Render::Text::TextFormat::operator=(&textFmt, tfmt);
  if ( pfmt )
    Scaleform::Render::Text::ParagraphFormat::operator=(&paraFmt, pfmt);
  Raw = txtParams->TextColor.Raw;
  textFmt.PresentMask |= 1u;
  textFmt.ColorV = Raw;
  switch ( txtParams->FontStyle )
  {
    case Normal:
      Scaleform::Render::Text::TextFormat::SetBold(&textFmt, 0);
      Scaleform::Render::Text::TextFormat::SetItalic(&textFmt, 0);
      break;
    case Bold:
      Scaleform::Render::Text::TextFormat::SetBold(&textFmt, 1);
      Scaleform::Render::Text::TextFormat::SetItalic(&textFmt, 0);
      break;
    case Italic:
      Scaleform::Render::Text::TextFormat::SetBold(&textFmt, 0);
      goto LABEL_10;
    case BoldItalic:
      Scaleform::Render::Text::TextFormat::SetBold(&textFmt, 1);
LABEL_10:
      Scaleform::Render::Text::TextFormat::SetItalic(&textFmt, 1);
      break;
    default:
      break;
  }
  Scaleform::Render::Text::TextFormat::SetFontName(&textFmt, &txtParams->FontName);
  Scaleform::Render::Text::TextFormat::SetFontSize(&textFmt, txtParams->FontSize);
  Scaleform::Render::Text::TextFormat::SetUnderline(&textFmt, txtParams->Underline);
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
  paraFmt.PresentMask = paraFmt.PresentMask ^ (paraFmt.PresentMask ^ (v7 << 9)) & 0x600 | 1;
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
  Scaleform::Render::Text::DocView::SetTextFormat(pdoc, &textFmt, 0, 0xFFFFFFFF);
  Scaleform::Render::Text::DocView::SetParagraphFormat(pdoc, &paraFmt, 0, 0xFFFFFFFF);
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(pdoc->pDocument.pObject, &textFmt);
  Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(pdoc->pDocument.pObject, &paraFmt);
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&paraFmt);
  Scaleform::Render::Text::TextFormat::~TextFormat(&textFmt);
}
