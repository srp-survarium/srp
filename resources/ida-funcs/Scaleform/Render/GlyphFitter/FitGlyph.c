void __thiscall Scaleform::Render::GlyphFitter::FitGlyph(
        Scaleform::Render::GlyphFitter *this,
        int heightInPixels,
        int widthInPixels,
        int lowerCaseTop,
        int upperCaseTop)
{
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  Scaleform::Render::GlyphFitter *v9; // ecx

  if ( widthInPixels )
    v6 = this->NominalFontHeight / widthInPixels;
  else
    v6 = 1;
  this->UnitsPerPixelX = v6;
  if ( heightInPixels )
    v7 = this->NominalFontHeight / heightInPixels;
  else
    v7 = 1;
  v8 = this->NominalFontHeight / v7;
  this->UnitsPerPixelY = v7;
  this->SnappedHeight = v7 * v8;
  if ( heightInPixels || widthInPixels )
  {
    Scaleform::Render::GlyphFitter::removeDuplicateClosures(this);
    Scaleform::Render::GlyphFitter::computeBounds(this);
    if ( heightInPixels && this->MaxY > this->MinY )
    {
      Scaleform::Render::GlyphFitter::detectEvents(v9, FitY);
      Scaleform::Render::GlyphFitter::computeLerpRamp(
        this,
        (unsigned __int8 *)2,
        this->UnitsPerPixelY,
        this->MinY + (this->MaxY - this->MinY) / 3,
        lowerCaseTop,
        upperCaseTop);
    }
    if ( widthInPixels )
    {
      if ( this->MaxY > this->MinY )
      {
        Scaleform::Render::GlyphFitter::detectEvents(this, FitX);
        Scaleform::Render::GlyphFitter::computeLerpRamp(
          this,
          (unsigned __int8 *)1,
          this->UnitsPerPixelX,
          this->MinX + (this->MaxX - this->MinX) / 3,
          0,
          0);
      }
    }
  }
}
