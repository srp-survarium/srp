Scaleform::GFx::ResourceKey *__cdecl Scaleform::GFx::ImageResource::CreateImageFileKey(
        Scaleform::GFx::ResourceKey *result,
        Scaleform::GFx::ImageFileInfo *pfileInfo,
        Scaleform::GFx::Resource *pfileOpener,
        Scaleform::GFx::Resource *pimageCreator,
        Scaleform::MemoryHeap *pimageHeap)
{
  Scaleform::MemoryHeap *v5; // ecx
  Scaleform::GFx::ImageFileInfoKeyData *v6; // eax
  Scaleform::RefCountVImpl *v7; // eax
  Scaleform::RefCountVImpl *v8; // esi

  v5 = pimageHeap;
  if ( !pimageHeap )
    v5 = Scaleform::Memory::pGlobalHeap;
  v6 = (Scaleform::GFx::ImageFileInfoKeyData *)v5->Alloc(v5, 24u, 0);
  if ( v6 )
  {
    Scaleform::GFx::ImageFileInfoKeyData::ImageFileInfoKeyData(v6, pfileInfo, pfileOpener, pimageCreator, pimageHeap);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  Scaleform::GFx::ResourceKey::ResourceKey(result, &ImageFileKeyInterface_Instance, v8);
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  return result;
}
