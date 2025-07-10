void __thiscall Scaleform::Render::GlyphScanlineFilter::GlyphScanlineFilter(
        Scaleform::Render::GlyphScanlineFilter *this,
        float prim,
        float second,
        float tert)
{
  unsigned int v5; // esi
  float v6; // [esp+3Ch] [ebp-Ch]
  float norm; // [esp+40h] [ebp-8h]
  float norma; // [esp+40h] [ebp-8h]
  float v9; // [esp+44h] [ebp-4h]
  float v10; // [esp+44h] [ebp-4h]
  float prima; // [esp+50h] [ebp+8h]
  float seconda; // [esp+54h] [ebp+Ch]
  float terta; // [esp+58h] [ebp+10h]

  v5 = 0;
  norm = 1.0 / (2.0 * tert + second * 2.0 + prim);
  prima = prim * norm;
  seconda = second * norm;
  terta = norm * tert;
  do
  {
    norma = (float)v5;
    v6 = norma * prima;
    this->Primary[v5] = (int)floor(v6);
    v9 = norma * seconda;
    this->Secondary[v5] = (int)floor(v9);
    v10 = norma * terta;
    this->Secondary[++v5 + 255] = (int)floor(v10);
  }
  while ( v5 < 0x100 );
}
