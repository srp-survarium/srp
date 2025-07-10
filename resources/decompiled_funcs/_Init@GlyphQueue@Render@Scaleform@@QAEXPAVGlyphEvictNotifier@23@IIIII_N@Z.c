void __thiscall Scaleform::Render::GlyphQueue::Init(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphEvictNotifier *notifier,
        unsigned int firstTexture,
        unsigned int numTextures,
        unsigned int textureWidth,
        unsigned int textureHeight,
        unsigned int maxSlotHeight,
        bool fenceWaitOnFull)
{
  Scaleform::Render::GlyphQueue::Clear(this);
  this->FirstTexture = firstTexture;
  this->TextureWidth = textureWidth;
  this->TextureHeight = textureHeight;
  this->MaxSlotHeight = maxSlotHeight;
  this->NumTextures = numTextures;
  this->FenceWaitOnFullCache = fenceWaitOnFull;
  this->NumBandsInTexture = textureHeight / maxSlotHeight;
  Scaleform::ArrayUnsafeBase<Scaleform::Render::GlyphBand,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphBand,79>>::Reserve(
    &this->Bands,
    numTextures * (textureHeight / maxSlotHeight),
    0);
  this->Bands.Size = numTextures * (textureHeight / maxSlotHeight);
  this->pEvictNotifier = notifier;
}
