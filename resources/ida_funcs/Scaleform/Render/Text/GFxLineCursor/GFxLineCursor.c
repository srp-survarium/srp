void __thiscall Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(
        Scaleform::Render::Text::GFxLineCursor *this,
        Scaleform::Render::Text::DocView *pview,
        const Scaleform::Render::Text::Paragraph *ppara)
{
  this->pPrevGrec = 0;
  this->pLastFont.pObject = 0;
  this->LastAdvance = 0.0;
  this->LastCharCode = 0;
  this->LastGlyphIndex = 0;
  this->LastGlyphWidth = 0;
  this->LastColor = 0;
  this->pComposStr.pObject = 0;
  this->MaxFontAscent = 0.0;
  this->pDocView = pview;
  this->MaxFontDescent = 0.0;
  this->MaxFontLeading = 0.0;
  this->ComposStrPosition = -1;
  this->ComposStrLength = 0;
  this->ComposStrCurPos = 0;
  this->pParagraph = ppara;
  this->LineWidth = 0;
  this->LineWidthWithoutTrailingSpaces = 0;
  this->LineLength = 0;
  Scaleform::Render::Text::Paragraph::CharactersIterator::CharactersIterator(&this->CharIter, ppara, 0);
  this->CharInfoHolder.pFormat.pObject = 0;
  this->CharInfoHolder.Index = 0;
  this->CharInfoHolder.Character = 0;
  this->Indent = 0;
  this->LeftMargin = 0;
  this->RightMargin = 0;
  this->GlyphIns.pGlyphs = 0;
  this->GlyphIns.pNextFormatData = 0;
  this->GlyphIns.GlyphIndex = 0;
  this->GlyphIns.GlyphsCount = 0;
  this->GlyphIns.FormatDataIndex = 0;
  this->FontScaleFactor = 1.0;
  this->NumOfSpaces = 0;
  this->NumOfTrailingSpaces = 0;
  this->LastKerning = 0;
  this->LineHasNewLine = 0;
  this->NumChars = 0;
}


void __thiscall Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(Scaleform::Render::Text::GFxLineCursor *this)
{
  this->pPrevGrec = 0;
  this->pLastFont.pObject = 0;
  this->LastAdvance = 0.0;
  this->LastCharCode = 0;
  this->LastGlyphIndex = 0;
  this->LastGlyphWidth = 0;
  this->LastColor = 0;
  this->pComposStr.pObject = 0;
  this->MaxFontAscent = 0.0;
  this->MaxFontDescent = 0.0;
  this->ComposStrLength = 0;
  this->MaxFontLeading = 0.0;
  this->ComposStrCurPos = 0;
  this->pDocView = 0;
  this->pParagraph = 0;
  this->LineWidth = 0;
  this->LineWidthWithoutTrailingSpaces = 0;
  this->LineLength = 0;
  this->ComposStrPosition = -1;
  this->CharIter.PlaceHolder.pFormat.pObject = 0;
  this->CharIter.PlaceHolder.Index = 0;
  this->CharIter.pFormatInfo = 0;
  this->CharIter.PlaceHolder.Character = 0;
  this->CharIter.FormatIterator.Index = -1;
  this->CharIter.FormatIterator.pArray = 0;
  this->CharIter.pText = 0;
  this->CharIter.CurTextIndex = 0;
  this->CharInfoHolder.pFormat.pObject = 0;
  this->CharInfoHolder.Index = 0;
  this->CharInfoHolder.Character = 0;
  this->Indent = 0;
  this->LeftMargin = 0;
  this->RightMargin = 0;
  this->GlyphIns.pGlyphs = 0;
  this->GlyphIns.pNextFormatData = 0;
  this->GlyphIns.GlyphIndex = 0;
  this->GlyphIns.GlyphsCount = 0;
  this->GlyphIns.FormatDataIndex = 0;
  this->FontScaleFactor = 1.0;
  this->NumOfSpaces = 0;
  this->NumOfTrailingSpaces = 0;
  this->LastKerning = 0;
  this->LineHasNewLine = 0;
  this->NumChars = 0;
}
