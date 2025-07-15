unsigned __int16 __thiscall Scaleform::Render::Font::calcTopBound(Scaleform::Render::Font *this, int code)
{
  Scaleform::Render::Font_vtbl *v3; // eax
  int (__thiscall *GetGlyphIndex)(Scaleform::Render::Font *, unsigned __int16); // edx
  unsigned int v5; // eax
  float v7; // [esp+12h] [ebp-10h] BYREF
  float v8; // [esp+16h] [ebp-Ch]
  float v9; // [esp+1Ah] [ebp-8h]
  float v10; // [esp+1Eh] [ebp-4h]

  v7 = 0.0;
  v8 = 0.0;
  v3 = this->__vftable;
  v9 = 0.0;
  GetGlyphIndex = v3->GetGlyphIndex;
  v10 = 0.0;
  v5 = GetGlyphIndex(this, code);
  if ( v5 == -1 )
    return 0;
  this->GetGlyphBounds(this, v5, (Scaleform::Render::Rect<float> *)&v7);
  return (int)-v8;
}
