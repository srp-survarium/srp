void __thiscall Scaleform::Render::TextureGlyph::TextureGlyph(
        Scaleform::Render::TextureGlyph *this,
        const Scaleform::Render::TextureGlyph *__that)
{
  Scaleform::Render::Image *pObject; // ecx
  float x2; // [esp+8h] [ebp-8h]
  float y2; // [esp+Ch] [ebp-4h]
  float __thata; // [esp+14h] [ebp+4h]
  float __thatb; // [esp+14h] [ebp+4h]

  this->__vftable = (Scaleform::Render::TextureGlyph_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = __that->RefCount;
  this->__vftable = (Scaleform::Render::TextureGlyph_vtbl *)&Scaleform::Render::TextureGlyph::`vftable';
  pObject = __that->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  __thata = __that->UvBounds.y1;
  this->pImage.pObject = __that->pImage.pObject;
  x2 = __that->UvBounds.x2;
  y2 = __that->UvBounds.y2;
  this->UvBounds.x1 = __that->UvBounds.x1;
  this->UvBounds.y1 = __thata;
  this->UvBounds.x2 = x2;
  this->UvBounds.y2 = y2;
  __thatb = __that->UvOrigin.y;
  this->UvOrigin.x = __that->UvOrigin.x;
  this->UvOrigin.y = __thatb;
  this->BindIndex = __that->BindIndex;
}
