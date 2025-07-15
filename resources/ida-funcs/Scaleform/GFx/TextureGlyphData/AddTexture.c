void __thiscall Scaleform::GFx::TextureGlyphData::AddTexture(
        Scaleform::GFx::TextureGlyphData *this,
        Scaleform::GFx::ResourceId textureId,
        const Scaleform::GFx::ResourceHandle *rh)
{
  const Scaleform::GFx::ResourceHandle *v3; // esi
  bool v4; // zf
  Scaleform::GFx::Resource *pResource; // ecx
  Scaleform::GFx::Resource *v7; // ecx
  Scaleform::GFx::ResourceHandle::HandleType HType; // eax
  Scaleform::GFx::ResourceHandle::HandleType v9; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::Resource *v10; // [esp+Ch] [ebp-Ch]
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeRef key; // [esp+10h] [ebp-8h] BYREF

  v3 = rh;
  v4 = rh->HType == RH_Pointer;
  v9 = RH_Pointer;
  v10 = 0;
  if ( v4 )
  {
    pResource = rh->pResource;
    if ( pResource )
      Scaleform::RefCountImpl::AddRef(pResource);
  }
  v7 = v3->pResource;
  HType = v3->HType;
  key.pFirst = &textureId;
  v10 = v7;
  v9 = HType;
  key.pSecond = (const Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource> *)&v9;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeRef>(
    &this->GlyphsTextures.mHash,
    &this->GlyphsTextures,
    &key);
  if ( v9 == RH_Pointer )
  {
    if ( v10 )
      Scaleform::GFx::Resource::Release(v10);
  }
}


void __thiscall Scaleform::GFx::TextureGlyphData::AddTexture(
        Scaleform::GFx::TextureGlyphData *this,
        Scaleform::GFx::ResourceId textureId,
        Scaleform::GFx::ImageResource *pimageRes)
{
  int v4; // [esp+4h] [ebp-10h] BYREF
  Scaleform::GFx::Resource *v5; // [esp+8h] [ebp-Ch]
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeRef key; // [esp+Ch] [ebp-8h] BYREF

  v4 = 0;
  v5 = pimageRes;
  if ( pimageRes )
    Scaleform::RefCountImpl::AddRef(pimageRes);
  key.pFirst = &textureId;
  key.pSecond = (const Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource> *)&v4;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeRef>(
    &this->GlyphsTextures.mHash,
    &this->GlyphsTextures,
    &key);
  if ( !v4 )
  {
    if ( v5 )
      Scaleform::GFx::Resource::Release(v5);
  }
}
