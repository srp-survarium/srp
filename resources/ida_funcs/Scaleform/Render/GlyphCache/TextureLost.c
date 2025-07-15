void __thiscall Scaleform::Render::GlyphCache::TextureLost(
        Scaleform::Render::GlyphCache *this,
        unsigned int textureId,
        unsigned int reason)
{
  unsigned int v3; // esi
  Scaleform::Render::GlyphCache *v4; // edi
  unsigned int v5; // edx
  unsigned int v6; // ebx
  Scaleform::Render::GlyphCache::UpdateRect **Pages; // ecx
  Scaleform::Render::GlyphCache::UpdateRect *v8; // esi
  int v9; // edi

  v3 = textureId;
  v4 = this;
  Scaleform::Render::GlyphQueue::CleanUpTexture(&this->Queue, textureId);
  v5 = 0;
  v6 = 0;
  if ( v4->GlyphsToUpdate.Size )
  {
    do
    {
      Pages = v4->GlyphsToUpdate.Pages;
      v8 = &Pages[v6 >> 6][v6 & 0x3F];
      if ( v8->TextureId != textureId )
      {
        qmemcpy(&Pages[v5 >> 6][v5 & 0x3F], v8, sizeof(Scaleform::Render::GlyphCache::UpdateRect));
        v4 = this;
        ++v5;
      }
      ++v6;
    }
    while ( v6 < v4->GlyphsToUpdate.Size );
    v3 = textureId;
    if ( v5 < v4->GlyphsToUpdate.Size )
      v4->GlyphsToUpdate.Size = v5;
  }
  v9 = (int)&v4->Textures[v3];
  *(_BYTE *)v9 = 0;
  *(_DWORD *)(v9 + 76) = 0;
}
