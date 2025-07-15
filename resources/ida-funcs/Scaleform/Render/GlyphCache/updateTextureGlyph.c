char __thiscall Scaleform::Render::GlyphCache::updateTextureGlyph(
        Scaleform::Render::GlyphCache *this,
        const Scaleform::Render::GlyphNode *node)
{
  unsigned int w; // ebp
  unsigned __int16 TextureId; // di
  unsigned int RasterPitch; // ecx
  unsigned int x; // edx
  unsigned int v7; // edi
  unsigned int y; // ecx
  unsigned int v9; // edx
  Scaleform::Render::GlyphTextureMapper *v10; // ecx
  unsigned int TextureHeight; // eax
  Scaleform::Render::TextureManager *pTexMan; // edx
  Scaleform::Render::RawImage *pObject; // ecx
  Scaleform::ArrayPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,6,16,2> *p_GlyphsToUpdate; // ebp
  unsigned int Size; // esi
  unsigned int v16; // esi
  Scaleform::Render::Palette *v17; // esi
  Scaleform::Render::ImagePlane *v19; // eax
  unsigned int updX[2]; // [esp+10h] [ebp-64h] BYREF
  unsigned int updY; // [esp+18h] [ebp-5Ch] BYREF
  unsigned int dstY; // [esp+1Ch] [ebp-58h]
  unsigned int dstX; // [esp+20h] [ebp-54h]
  unsigned int pitch; // [esp+24h] [ebp-50h]
  const unsigned __int8 *data; // [esp+28h] [ebp-4Ch]
  char *v26; // [esp+2Ch] [ebp-48h]
  Scaleform::Render::GlyphCache::UpdateRect r; // [esp+30h] [ebp-44h] BYREF
  Scaleform::Render::ImageData d; // [esp+4Ch] [ebp-28h] BYREF
  unsigned int h; // [esp+78h] [ebp+4h]

  w = node->mRect.w;
  TextureId = node->pSlot->TextureId;
  RasterPitch = this->RasterPitch;
  data = this->RasterData.Data.Data;
  x = node->mRect.x;
  v7 = TextureId & 0x7FFF;
  pitch = RasterPitch;
  y = node->mRect.y;
  dstX = x;
  v9 = node->mRect.h;
  dstY = y;
  v10 = &this->Textures[v7];
  h = v9;
  v26 = (char *)this + 80 * v7;
  updY = (unsigned int)v10;
  if ( !v10->Valid )
  {
    TextureHeight = this->TextureHeight;
    updX[0] = this->TextureWidth;
    pTexMan = this->pTexMan;
    updX[1] = TextureHeight;
    Scaleform::Render::GlyphTextureMapper::Create(
      v10,
      this->Method,
      this->pHeap,
      pTexMan,
      this->pFillMan,
      this,
      v7,
      (const Scaleform::Render::Size<unsigned long> *)updX);
    v10 = (Scaleform::Render::GlyphTextureMapper *)updY;
  }
  this->pRQCaches->LockFlags |= 2u;
  if ( this->Method != TU_MultipleUpdate )
  {
    v19 = Scaleform::Render::GlyphTextureMapper::Map(v10);
    if ( v19 )
    {
      Scaleform::Render::GlyphCache::copyImageData(this, v19, (unsigned __int8 *)data, pitch, dstX, dstY, w, h);
      return 1;
    }
    return 0;
  }
  if ( !Scaleform::Render::TextureUpdatePacker::Allocate(&this->UpdatePacker, w, h, updX, &updY) )
  {
    Scaleform::Render::GlyphCache::partialUpdateTextures(this);
    if ( !Scaleform::Render::TextureUpdatePacker::Allocate(&this->UpdatePacker, w, h, updX, &updY) )
      return 0;
  }
  d.RawPlaneCount = 1;
  pObject = this->UpdateBuffer.pObject;
  memset(&d, 0, 10);
  d.pPlanes = &d.Plane0;
  memset(&d.pPalette, 0, 24);
  Scaleform::Render::RawImage::GetImageData(pObject, &d);
  Scaleform::Render::GlyphCache::copyImageData(this, d.pPlanes, (unsigned __int8 *)data, pitch, updX[0], updY, w, h);
  ++*((_DWORD *)v26 + 49);
  r.w = w;
  p_GlyphsToUpdate = &this->GlyphsToUpdate;
  Size = this->GlyphsToUpdate.Size;
  r.SrcX = updX[0];
  r.SrcY = updY;
  v16 = Size >> 6;
  r.DstX = dstX;
  r.DstY = dstY;
  r.h = h;
  r.TextureId = v7;
  if ( v16 >= p_GlyphsToUpdate->NumPages )
    Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::allocatePage(
      p_GlyphsToUpdate,
      v16);
  qmemcpy(
    &p_GlyphsToUpdate->Pages[v16][p_GlyphsToUpdate->Size++ & 0x3F],
    &r,
    sizeof(p_GlyphsToUpdate->Pages[v16][p_GlyphsToUpdate->Size++ & 0x3F]));
  Scaleform::Render::ImageData::freePlanes(&d);
  if ( d.pPalette.pObject )
  {
    v17 = d.pPalette.pObject;
    if ( InterlockedExchangeAdd(&d.pPalette.pObject->RefCount.Value, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v17);
  }
  return 1;
}
