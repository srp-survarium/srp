void __thiscall Scaleform::Render::GlyphFitter::ClosePath(Scaleform::Render::GlyphFitter *this)
{
  if ( this->StartX != this->LastXf || this->StartY != this->LastYf )
    Scaleform::Render::GlyphFitter::LineTo(this, this->StartX, this->StartY);
}
