void __thiscall Scaleform::Render::Text::GFxLineCursor::Reset(Scaleform::Render::Text::GFxLineCursor *this)
{
  this->MaxFontLeading = 0.0;
  this->pPrevGrec = 0;
  this->MaxFontDescent = 0.0;
  this->LineHasNewLine = 0;
  this->MaxFontAscent = 0.0;
  this->LastKerning = 0;
  this->LastAdvance = 0.0;
  this->LineWidthWithoutTrailingSpaces = 0;
  this->LineLength = 0;
  this->NumOfTrailingSpaces = 0;
  this->NumOfSpaces = 0;
  this->NumChars = 0;
  this->LastCharCode = 0;
}
