void __thiscall Scaleform::Render::Text::GFxLineCursor::TrackFontParams(
        Scaleform::Render::Text::GFxLineCursor *this,
        Scaleform::Render::Font *pfont,
        float scale)
{
  double v4; // st7
  double v5; // st6
  double v6; // st6
  float Descent; // [esp+0h] [ebp-8h]
  float MaxFontAscent; // [esp+4h] [ebp-4h]
  float Ascent; // [esp+Ch] [ebp+4h]
  float v10; // [esp+Ch] [ebp+4h]
  float v11; // [esp+Ch] [ebp+4h]
  float v12; // [esp+Ch] [ebp+4h]
  float v13; // [esp+Ch] [ebp+4h]
  float v14; // [esp+Ch] [ebp+4h]
  float MaxFontDescent; // [esp+10h] [ebp+8h]
  float MaxFontLeading; // [esp+10h] [ebp+8h]

  Ascent = pfont->Ascent;
  Descent = pfont->Descent;
  if ( 0.0 == Ascent )
    Ascent = 960.0;
  if ( 0.0 == Descent )
    Descent = 64.0;
  MaxFontAscent = this->MaxFontAscent;
  v4 = scale;
  v10 = Ascent * scale;
  v5 = v10;
  if ( MaxFontAscent > (double)v10 )
    v5 = MaxFontAscent;
  v11 = v5;
  this->MaxFontAscent = v11;
  MaxFontDescent = this->MaxFontDescent;
  v12 = Descent * v4;
  v6 = v12;
  if ( MaxFontDescent > (double)v12 )
    v6 = MaxFontDescent;
  v13 = v6;
  this->MaxFontDescent = v13;
  MaxFontLeading = this->MaxFontLeading;
  v14 = v4 * pfont->Leading;
  if ( MaxFontLeading > (double)v14 )
    v14 = MaxFontLeading;
  this->MaxFontLeading = v14;
}
