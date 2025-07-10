Scaleform::GFx::ResourceHandle *__cdecl Scaleform::GFx::GFx_CreateImageFileResourceHandle(
        Scaleform::GFx::ResourceHandle *result,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::ResourceId rid,
        char *pimageFileName,
        char *pimageExportName,
        unsigned __int16 bitmapFormat,
        unsigned __int16 targetWidth,
        unsigned __int16 targetHeight)
{
  Scaleform::MemoryHeap *v8; // ecx
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::GFx::ResourceFileInfo *v10; // eax
  Scaleform::GFx::ResourceFileInfo *v11; // esi
  const Scaleform::GFx::ResourceData *v12; // eax
  Scaleform::GFx::ResourceHandle *v13; // eax
  Scaleform::GFx::ResourceHandle *v14; // edi
  Scaleform::GFx::Resource *pResource; // ecx
  Scaleform::GFx::Resource *v16; // ecx
  bool v17; // zf
  unsigned int BindIndex; // ecx
  Scaleform::GFx::ResourceHandle v20; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::ResourceData v21; // [esp+18h] [ebp-8h] BYREF

  v8 = Scaleform::Memory::pGlobalHeap;
  Alloc = Scaleform::Memory::pGlobalHeap->Alloc;
  result->HType = RH_Pointer;
  result->BindIndex = 0;
  v10 = (Scaleform::GFx::ResourceFileInfo *)Alloc(v8, 32u, 0);
  v11 = v10;
  if ( v10 )
  {
    Scaleform::GFx::ResourceFileInfo::ResourceFileInfo(v10);
    v11->__vftable = (Scaleform::GFx::ResourceFileInfo_vtbl *)&Scaleform::GFx::ImageFileInfo::`vftable';
    Scaleform::String::String((Scaleform::String *)&v11[1].Format);
    LOWORD(v11[1].__vftable) = 0;
    HIWORD(v11[1].__vftable) = 0;
    v11[1].RefCount = 1;
    Scaleform::String::operator=(&v11->FileName, pimageFileName);
    Scaleform::String::operator=((Scaleform::String *)&v11[1].Format, pimageExportName);
    v11->pExporterInfo = p->pLoadData.pObject->Header.mExporterInfo.SI.Format != File_Unopened
                       ? (const Scaleform::GFx::ExporterInfo *)&p->pLoadData.pObject->Header.mExporterInfo
                       : 0;
    v11->Format = bitmapFormat;
    LOWORD(v11[1].__vftable) = targetWidth;
    HIWORD(v11[1].__vftable) = targetHeight;
    if ( (int *)(rid.Id & 0xFFF0000) == &dword_60000 )
      v11[1].RefCount = 3;
    v12 = Scaleform::GFx::ImageFileResourceCreator::CreateImageFileResourceData(
            &v21,
            (Scaleform::GFx::ImageFileInfo *)v11);
    v13 = Scaleform::GFx::LoadProcess::AddDataResource(p, &v20, rid, v12);
    v14 = v13;
    if ( v13->HType == RH_Pointer )
    {
      pResource = v13->pResource;
      if ( pResource )
        Scaleform::RefCountImpl::AddRef(pResource);
    }
    if ( result->HType == RH_Pointer )
    {
      v16 = result->pResource;
      if ( v16 )
        Scaleform::GFx::Resource::Release(v16);
    }
    v17 = v20.HType == RH_Pointer;
    BindIndex = v14->BindIndex;
    result->HType = v14->HType;
    result->BindIndex = BindIndex;
    if ( v17 && v20.BindIndex )
      Scaleform::GFx::Resource::Release(v20.pResource);
    if ( v21.pInterface )
      v21.pInterface->Release(v21.pInterface, v21.hData);
    Scaleform::RefCountNTSImpl::Release(v11);
  }
  return result;
}
