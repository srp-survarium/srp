char __thiscall Scaleform::GFx::ImageFileResourceCreator::CreateResource(
        Scaleform::GFx::ImageFileResourceCreator *this,
        unsigned __int16 *hdata,
        Scaleform::GFx::ResourceBindData *pbindData,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::MemoryHeap *pbindHeap)
{
  Scaleform::GFx::ResourceFileInfo *v5; // eax
  Scaleform::GFx::ResourceFileInfo *v6; // edi
  Scaleform::String *v7; // ebx
  Scaleform::String::DataDesc *pData; // eax
  Scaleform::GFx::URLBuilder *pObject; // ecx
  Scaleform::MemoryHeap *v10; // ebx
  Scaleform::GFx::ResourceWeakLib *v11; // ecx
  Scaleform::GFx::MovieDefBindStates *v12; // edx
  Scaleform::Log *v13; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v14; // ebx
  Scaleform::GFx::LogState *v15; // eax
  Scaleform::Log *GlobalLog; // eax
  const Scaleform::GFx::ExporterInfo *v17; // edx
  Scaleform::Render::ImageFileFormat v18; // eax
  unsigned int v19; // ecx
  unsigned int v20; // edx
  void *v21; // ebx
  Scaleform::Render::Image_vtbl *v22; // edx
  Scaleform::Render::Size<unsigned long> *(__thiscall *GetSize)(struct Scaleform::Render::Image *, Scaleform::Render::Size<unsigned long> *); // edx
  Scaleform::GFx::ImageResource *v24; // eax
  Scaleform::GFx::Resource *v25; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v26; // ecx
  Scaleform::GFx::LogState *v27; // edx
  Scaleform::Log *v28; // edx
  char *Error; // eax
  Scaleform::GFx::Resource *v30; // esi
  void *v31; // esi
  void *v33; // esi
  Scaleform::GFx::FileTypeConstants::FileFormatType sy; // [esp+6E0h] [ebp-D4h]
  float sya; // [esp+6E0h] [ebp-D4h]
  Scaleform::MemoryHeap *v36; // [esp+6F8h] [ebp-BCh]
  float v37; // [esp+6F8h] [ebp-BCh]
  float sx; // [esp+6F8h] [ebp-BCh]
  float v39; // [esp+6F8h] [ebp-BCh]
  Scaleform::Render::Image *v40; // [esp+6FCh] [ebp-B8h]
  Scaleform::GFx::FileOpener *v41; // [esp+6FCh] [ebp-B8h]
  Scaleform::Render::Image *v42; // [esp+6FCh] [ebp-B8h]
  Scaleform::String v43; // [esp+700h] [ebp-B4h] BYREF
  Scaleform::GFx::ResourceLib::BindHandle phandle; // [esp+704h] [ebp-B0h] BYREF
  Scaleform::GFx::ImageFileInfo *pfileInfo; // [esp+70Ch] [ebp-A8h]
  Scaleform::GFx::Resource *v46; // [esp+710h] [ebp-A4h]
  Scaleform::GFx::ResourceKey result; // [esp+714h] [ebp-A0h] BYREF
  _DWORD v48[2]; // [esp+71Ch] [ebp-98h] BYREF
  Scaleform::GFx::ImageCreator *v49; // [esp+724h] [ebp-90h]
  Scaleform::GFx::URLBuilder::LocationInfo v50; // [esp+728h] [ebp-8Ch] BYREF
  _DWORD v51[4]; // [esp+734h] [ebp-80h] BYREF
  Scaleform::Log *v52; // [esp+744h] [ebp-70h]
  float v53; // [esp+748h] [ebp-6Ch]
  Scaleform::Render::Image *v54; // [esp+74Ch] [ebp-68h]
  float v55; // [esp+750h] [ebp-64h]
  Scaleform::Render::Matrix2x4<float> v56; // [esp+754h] [ebp-60h] BYREF
  Scaleform::GFx::ImageCreateExportInfo v57; // [esp+780h] [ebp-34h] BYREF

  v5 = (Scaleform::GFx::ResourceFileInfo *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::ResourceFileInfo::ResourceFileInfo(v5, (const Scaleform::GFx::ResourceFileInfo *)hdata);
    v6->__vftable = (Scaleform::GFx::ResourceFileInfo_vtbl *)&Scaleform::GFx::ImageFileInfo::`vftable';
    Scaleform::String::String((Scaleform::String *)&v6[1].Format);
    LOWORD(v6[1].__vftable) = hdata[10];
    HIWORD(v6[1].__vftable) = hdata[11];
    v7 = (Scaleform::String *)v6;
    v6[1].RefCount = *((_DWORD *)hdata + 6);
    pfileInfo = (Scaleform::GFx::ImageFileInfo *)v6;
  }
  else
  {
    pfileInfo = 0;
    v7 = 0;
  }
  if ( v7[2].HeapTypeBits == 1 )
  {
    pData = v7[3].pData;
    if ( pData )
      v7[2].pData = (Scaleform::String::DataDesc *)pData->Size;
  }
  v50.Use = File_ImageImport;
  Scaleform::String::String(&v50.FileName, (const Scaleform::String *)hdata + 4);
  Scaleform::String::String(&v50.ParentPath, &pls->RelativePath);
  pObject = pls->pBindStates.pObject->pURLBulider.pObject;
  v48[0] = v7 + 4;
  if ( pObject )
    pObject->BuildURL(pObject, v7 + 4, &v50);
  else
    Scaleform::GFx::URLBuilder::DefaultBuildURL(v7 + 4, &v50);
  v36 = pls->pWeakResourceLib.pObject->pImageHeap.pObject;
  v10 = v36;
  Scaleform::GFx::ImageResource::CreateImageFileKey(
    &result,
    pfileInfo,
    pls->pBindStates.pObject->pFileOpener.pObject,
    pls->pBindStates.pObject->pImageCreator.pObject,
    v36);
  Scaleform::String::String(&v43);
  v11 = pls->pWeakResourceLib.pObject;
  phandle.State = RS_Unbound;
  phandle.pResource = 0;
  v46 = 0;
  if ( Scaleform::GFx::ResourceWeakLib::BindResourceKey(v11, &phandle, &result) == 3 )
  {
    v12 = pls->pBindStates.pObject;
    v13 = 0;
    v40 = 0;
    v49 = v12->pImageCreator.pObject;
    if ( !v49 )
      goto LABEL_31;
    if ( *((_DWORD *)hdata + 3) )
    {
      Scaleform::GFx::ImageCreateExportInfo::ImageCreateExportInfo(
        &v57,
        v36,
        0,
        *((Scaleform::GFx::Resource::ResourceUse *)hdata + 6));
      v14 = pls->pImageFileHandlerRegistry.pObject;
      v41 = pls->pBindStates.pObject->pFileOpener.pObject;
      v15 = pls->pLog.pObject;
      if ( v15 )
      {
        GlobalLog = v15->pLog.pObject;
        if ( !GlobalLog )
          GlobalLog = Scaleform::Log::GetGlobalLog();
      }
      else
      {
        GlobalLog = 0;
      }
      v17 = (const Scaleform::GFx::ExporterInfo *)*((_DWORD *)hdata + 3);
      v57.pLog = GlobalLog;
      sy = *((_DWORD *)hdata + 2);
      v57.pFileOpener = v41;
      v57.pIFHRegistry = v14;
      v57.pExporterInfo = v17;
      v18 = Scaleform::GFx::LoaderImpl::FileFormat2RenderImageFile(sy);
      v19 = hdata[10];
      v20 = hdata[11];
      v57.Format = v18;
      v57.TargetSize.Width = v19;
      v57.TargetSize.Height = v20;
      Scaleform::String::operator=(&v57.ExportName, (const Scaleform::String *)hdata + 7);
      v40 = v49->LoadExportedImage(v49, &v57, (const Scaleform::String *)v48[0]);
      v21 = (void *)(v57.ExportName.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v57.ExportName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
      v10 = v36;
    }
    else
    {
      v51[3] = *((_DWORD *)hdata + 6);
      v26 = pls->pImageFileHandlerRegistry.pObject;
      v51[0] = 1;
      v51[1] = v36;
      v51[2] = 0;
      v52 = 0;
      v53 = 0.0;
      v54 = 0;
      v55 = 0.0;
      v39 = *(float *)&v12->pFileOpener.pObject;
      v27 = pls->pLog.pObject;
      v42 = (Scaleform::Render::Image *)v26;
      if ( v27 )
      {
        v28 = v27->pLog.pObject;
        if ( v28 )
          v13 = v28;
        else
          v13 = Scaleform::Log::GetGlobalLog();
      }
      v54 = v42;
      v53 = v39;
      v52 = v13;
      v40 = v49->LoadImageFile(v49, (const Scaleform::GFx::ImageCreateInfo *)v51, (const Scaleform::String *)v48[0]);
    }
    if ( !v40 )
      goto LABEL_31;
    v22 = v40->__vftable;
    v56.M[0][0] = 1.0;
    GetSize = v22->GetSize;
    v56.M[0][1] = 0.0;
    v56.M[0][2] = 0.0;
    v56.M[0][3] = 0.0;
    v56.M[1][0] = 0.0;
    v56.M[1][2] = 0.0;
    v56.M[1][3] = 0.0;
    v56.M[1][1] = 1.0;
    GetSize(v40, (Scaleform::Render::Size<unsigned long> *)v48);
    v37 = (double)hdata[11] / (double)v48[1];
    sya = v37;
    sx = (double)hdata[10] / (double)v48[0];
    Scaleform::Render::Matrix2x4<float>::AppendScaling(&v56, sx, sya);
    v40->SetMatrix(v40, &v56, 0);
    v24 = (Scaleform::GFx::ImageResource *)v10->Alloc(v10, 52u, 0);
    if ( v24 )
      Scaleform::GFx::ImageResource::ImageResource(
        v24,
        v40,
        &result,
        *((Scaleform::GFx::Resource::ResourceUse *)hdata + 6));
    else
      v25 = 0;
    v46 = v25;
    if ( v25 )
    {
      Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(phandle.pSlot, v25);
    }
    else
    {
LABEL_31:
      Scaleform::String::operator=(&v43, "Failed to load image '");
      Scaleform::String::operator+=(&v43, &pfileInfo->FileName);
      Scaleform::String::AppendString(&v43, "'", 0xFFFFFFFF);
      Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        phandle.pSlot,
        (char *)((v43.HeapTypeBits & 0xFFFFFFFC) + 8));
    }
    if ( v40 )
      v40->Release(v40);
  }
  else
  {
    v46 = Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&phandle);
    if ( v46 )
    {
      v30 = v46;
      goto LABEL_50;
    }
    if ( phandle.State < RS_WaitingResolve )
      Error = (char *)&buf;
    else
      Error = (char *)Scaleform::GFx::ResourceLib::ResourceSlot::GetError(phandle.pSlot);
    Scaleform::String::operator=(&v43, Error);
  }
  v30 = v46;
  if ( !v46 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
      &pls->pLog.pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
      "%s",
      (const char *)((v43.HeapTypeBits & 0xFFFFFFFC) + 8));
    if ( phandle.State == RS_Available )
    {
      Scaleform::GFx::Resource::Release(phandle.pResource);
    }
    else if ( phandle.State >= RS_WaitingResolve )
    {
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)phandle.pResource);
    }
    v31 = (void *)(v43.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v43.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v31);
    if ( result.pKeyInterface )
      result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
    Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&v50);
    Scaleform::RefCountNTSImpl::Release(pfileInfo);
    return 0;
  }
LABEL_50:
  Scaleform::RefCountImpl::AddRef(v30);
  if ( pbindData->pResource.pObject )
    Scaleform::GFx::Resource::Release(pbindData->pResource.pObject);
  pbindData->pResource.pObject = v30;
  if ( v30 )
    Scaleform::GFx::Resource::Release(v30);
  if ( phandle.State == RS_Available )
  {
    Scaleform::GFx::Resource::Release(phandle.pResource);
  }
  else if ( phandle.State >= RS_WaitingResolve )
  {
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)phandle.pResource);
  }
  v33 = (void *)(v43.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v43.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v33);
  if ( result.pKeyInterface )
    result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
  Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&v50);
  Scaleform::RefCountNTSImpl::Release(pfileInfo);
  return 1;
}
