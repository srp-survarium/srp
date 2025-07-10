void __thiscall Scaleform::Render::Text::GFxLineCursor::TrackFontParams(
        Scaleform::Render::Text::GFxLineCursor *this,
        Scaleform::Render::Font *pfont,
        float scale)
{
  double v4; // st7
  double v5; // st6
  double v6; // st6
  float descent; // [esp+0h] [ebp-8h]
  float MaxFontAscent; // [esp+4h] [ebp-4h]
  float ascent; // [esp+Ch] [ebp+4h]
  float ascentb; // [esp+Ch] [ebp+4h]
  float ascentc; // [esp+Ch] [ebp+4h]
  float ascentd; // [esp+Ch] [ebp+4h]
  float ascente; // [esp+Ch] [ebp+4h]
  float ascenta; // [esp+Ch] [ebp+4h]
  float scalea; // [esp+10h] [ebp+8h]
  float scaleb; // [esp+10h] [ebp+8h]

  ascent = pfont->Ascent;
  descent = pfont->Descent;
  if ( 0.0 == ascent )
    ascent = 960.0;
  if ( 0.0 == descent )
    descent = 64.0;
  MaxFontAscent = this->MaxFontAscent;
  v4 = scale;
  ascentb = ascent * scale;
  v5 = ascentb;
  if ( MaxFontAscent > (double)ascentb )
    v5 = MaxFontAscent;
  ascentc = v5;
  this->MaxFontAscent = ascentc;
  scalea = this->MaxFontDescent;
  ascentd = descent * v4;
  v6 = ascentd;
  if ( scalea > (double)ascentd )
    v6 = scalea;
  ascente = v6;
  this->MaxFontDescent = ascente;
  scaleb = this->MaxFontLeading;
  ascenta = v4 * pfont->Leading;
  if ( scaleb > (double)ascenta )
    ascenta = scaleb;
  this->MaxFontLeading = ascenta;
}
