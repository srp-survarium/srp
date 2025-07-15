void __thiscall Scaleform::Render::GlyphScanlineFilter::GlyphScanlineFilter(
        Scaleform::Render::GlyphScanlineFilter *this,
        float prim,
        float second,
        float tert)
{
  unsigned int v5; // esi
  float v6; // [esp+3Ch] [ebp-Ch]
  float v7; // [esp+40h] [ebp-8h]
  float v8; // [esp+40h] [ebp-8h]
  float v9; // [esp+44h] [ebp-4h]
  float v10; // [esp+44h] [ebp-4h]
  float v11; // [esp+50h] [ebp+8h]
  float v12; // [esp+54h] [ebp+Ch]
  float v13; // [esp+58h] [ebp+10h]

  v5 = 0;
  v7 = 1.0 / (2.0 * tert + second * 2.0 + prim);
  v11 = prim * v7;
  v12 = second * v7;
  v13 = v7 * tert;
  do
  {
    v8 = (float)v5;
    v6 = v8 * v11;
    this->Primary[v5] = (int)floor(v6);
    v9 = v8 * v12;
    this->Secondary[v5] = (int)floor(v9);
    v10 = v8 * v13;
    this->Secondary[++v5 + 255] = (int)floor(v10);
  }
  while ( v5 < 0x100 );
}
