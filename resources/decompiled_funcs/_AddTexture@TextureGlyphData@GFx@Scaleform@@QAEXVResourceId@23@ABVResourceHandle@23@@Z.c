void __thiscall Scaleform::GFx::TextureGlyphData::AddTexture(
        Scaleform::GFx::TextureGlyphData *this,
        Scaleform::GFx::ResourceId textureId,
        const Scaleform::GFx::ResourceHandle *rh)
{
  const Scaleform::GFx::ResourceHandle *v3; // esi
  bool v4; // zf
  Scaleform::GFx::Resource *pResource; // ecx
  unsigned int BindIndex; // ecx
  Scaleform::GFx::ResourceHandle::HandleType HType; // eax
  Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource> pres; // [esp+8h] [ebp-10h] BYREF
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeRef key; // [esp+10h] [ebp-8h] BYREF

  v3 = rh;
  v4 = rh->HType == RH_Pointer;
  pres.HType = RH_Pointer;
  pres.BindIndex = 0;
  if ( v4 )
  {
    pResource = rh->pResource;
    if ( pResource )
      Scaleform::RefCountImpl::AddRef(pResource);
  }
  BindIndex = v3->BindIndex;
  HType = v3->HType;
  key.pFirst = &textureId;
  pres.BindIndex = BindIndex;
  pres.HType = HType;
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
