void __thiscall Scaleform::GFx::TextureGlyphData::AddTexture(
        Scaleform::GFx::TextureGlyphData *this,
        Scaleform::GFx::ResourceId textureId,
        Scaleform::GFx::ImageResource *pimageRes)
{
  Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource> pres; // [esp+4h] [ebp-10h] BYREF
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeRef key; // [esp+Ch] [ebp-8h] BYREF

  pres.HType = RH_Pointer;
  pres.BindIndex = (unsigned int)pimageRes;
  if ( pimageRes )
    Scaleform::RefCountImpl::AddRef(pimageRes);
  key.pFirst = &textureId;
  key.pSecond = &pres;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeRef>(
    &this->GlyphsTextures.mHash,
    &this->GlyphsTextures,
    &key);
  if ( pres.HType == RH_Pointer )
  {
    if ( pres.BindIndex )
      Scaleform::GFx::Resource::Release(pres.pResource);
  }
}
