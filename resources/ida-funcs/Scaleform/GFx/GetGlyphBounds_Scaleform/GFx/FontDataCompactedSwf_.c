Scaleform::Render::Rect<float> *__usercall Scaleform::GFx::GetGlyphBounds_Scaleform::GFx::FontDataCompactedSwf_@<eax>(
        Scaleform::GFx::FontDataCompactedSwf *font@<edi>,
        unsigned int glyphIndex@<eax>,
        Scaleform::Render::Rect<float> *prect@<esi>)
{
  double v3; // st7
  Scaleform::Render::Rect<float> *result; // eax
  float v5; // [esp+0h] [ebp-8h]
  float v6; // [esp+0h] [ebp-8h]
  float v7; // [esp+4h] [ebp-4h]
  float v8; // [esp+4h] [ebp-4h]
  float NominalSize; // [esp+4h] [ebp-4h]

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
  {
    prect->y1 = 0.0;
    prect->x1 = 0.0;
    v5 = font->GetNominalGlyphWidth(font);
    v7 = font->GetNominalGlyphHeight(font);
    prect->x1 = 0.0;
    prect->y1 = 0.0;
    prect->x2 = v5;
    v3 = v7;
LABEL_6:
    prect->y2 = v3;
    goto LABEL_7;
  }
  if ( glyphIndex >= font->CompactedFontValue.NumGlyphs )
  {
    prect->y1 = 0.0;
    prect->x1 = 0.0;
    v8 = font->GetNominalGlyphWidth(font);
    v6 = font->GetNominalGlyphHeight(font);
    prect->x1 = 0.0;
    prect->y1 = 0.0;
    prect->x2 = v8;
    v3 = v6;
    goto LABEL_6;
  }
  Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphBounds(
    &font->CompactedFontValue,
    glyphIndex,
    prect);
LABEL_7:
  NominalSize = (float)font->CompactedFontValue.NominalSize;
  result = prect;
  prect->x1 = prect->x1 * 1024.0 / NominalSize;
  prect->y1 = prect->y1 * 1024.0 / NominalSize;
  prect->x2 = prect->x2 * 1024.0 / NominalSize;
  prect->y2 = 1024.0 * prect->y2 / NominalSize;
  return result;
}
