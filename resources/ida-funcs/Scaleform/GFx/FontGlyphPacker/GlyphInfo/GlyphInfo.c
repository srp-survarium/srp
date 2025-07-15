void __thiscall Scaleform::GFx::FontGlyphPacker::GlyphInfo::GlyphInfo(
        Scaleform::GFx::FontGlyphPacker::GlyphInfo *this,
        const Scaleform::GFx::FontGlyphPacker::GlyphInfo *__that)
{
  float x2; // [esp+0h] [ebp-8h]
  float y2; // [esp+4h] [ebp-4h]
  float __thata; // [esp+Ch] [ebp+4h]
  float __thatb; // [esp+Ch] [ebp+4h]

  this->pFont = __that->pFont;
  this->GlyphIndex = __that->GlyphIndex;
  this->GlyphReuse = __that->GlyphReuse;
  this->TextureIdx = __that->TextureIdx;
  __thata = __that->Bounds.y1;
  x2 = __that->Bounds.x2;
  y2 = __that->Bounds.y2;
  this->Bounds.x1 = __that->Bounds.x1;
  this->Bounds.y1 = __thata;
  this->Bounds.x2 = x2;
  this->Bounds.y2 = y2;
  __thatb = __that->Origin.y;
  this->Origin.x = __that->Origin.x;
  this->Origin.y = __thatb;
}
