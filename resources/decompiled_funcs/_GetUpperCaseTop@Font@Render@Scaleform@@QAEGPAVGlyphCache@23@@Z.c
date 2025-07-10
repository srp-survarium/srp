int __thiscall Scaleform::Render::Font::GetUpperCaseTop(
        Scaleform::Render::Font *this,
        Scaleform::Render::GlyphCache *log)
{
  int result; // eax

  if ( !this->UpperCaseTop )
    Scaleform::Render::Font::calcLowerUpperTop(this, log);
  LOWORD(result) = this->UpperCaseTop;
  if ( (__int16)result > 0 )
    return (__int16)result;
  else
    return 0;
}
