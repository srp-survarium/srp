int __thiscall Scaleform::Render::Font::GetLowerCaseTop(
        Scaleform::Render::Font *this,
        Scaleform::Render::GlyphCache *log)
{
  int result; // eax

  if ( !this->LowerCaseTop )
    Scaleform::Render::Font::calcLowerUpperTop(this, log);
  LOWORD(result) = this->LowerCaseTop;
  if ( (__int16)result > 0 )
    return (__int16)result;
  else
    return 0;
}
