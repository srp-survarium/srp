void __thiscall Scaleform::GFx::MovieBindProcess::MovieBindProcess(
        Scaleform::GFx::MovieBindProcess *this,
        Scaleform::GFx::Resource *pls,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v8; // edx
  Scaleform::GFx::MovieDataDef *v9; // ecx
  bool v10; // al
  Scaleform::GFx::ImagePackParamsBase *RefCount; // ebp
  Scaleform::GFx::LogState *v12; // eax
  Scaleform::Log *GlobalLog; // eax
  Scaleform::GFx::MovieDefImpl_vtbl *v14; // edx
  Scaleform::MemoryHeap *v15; // eax
  Scaleform::GFx::MovieDefBindStates *pLib; // ecx
  Scaleform::GFx::ImagePacker *(__thiscall *Begin)(Scaleform::GFx::ImagePackParamsBase *, Scaleform::GFx::ResourceId *, Scaleform::GFx::ImageCreator *, Scaleform::GFx::ImageCreateInfo *); // edx
  int v18; // eax
  Scaleform::GFx::ImagePacker *v19; // ecx
  Scaleform::GFx::ImagePacker *v20; // edi
  Scaleform::GFx::TempBindData *v21; // eax
  void *v22; // edi
  volatile LONG *v23; // [esp-8h] [ebp-4Ch]
  Scaleform::GFx::ImageCreateExportInfo icreateInfo; // [esp+10h] [ebp-34h] BYREF
  Scaleform::GFx::FileOpener *plsa; // [esp+48h] [ebp+4h]
  Scaleform::GFx::ImageFileHandlerRegistry *pdefImpla; // [esp+4Ch] [ebp+8h]

  Scaleform::GFx::LoaderTask::LoaderTask(this, pls, (Scaleform::GFx::Task::TaskId)&byte_20003);
  this->__vftable = (Scaleform::GFx::MovieBindProcess_vtbl *)&Scaleform::GFx::MovieBindProcess::`vftable';
  this->pFrameBindData = 0;
  this->GlyphTextureIdGen.Id = 589824;
  this->pImagePacker.pObject = 0;
  pObject = (Scaleform::GFx::Resource *)pdefImpl->pBindData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  this->pBindData.pObject = pdefImpl->pBindData.pObject;
  v8 = this->pBindData.pObject;
  this->pLoadStack = ploadStack;
  v9 = v8->pDataDef.pObject;
  this->pDataDef = v9;
  v10 = (v9->GetSWFFlags(v9) & 0x10) != 0;
  this->Stripped = v10;
  RefCount = (Scaleform::GFx::ImagePackParamsBase *)pls->pLib[4].RefCount;
  if ( !RefCount || v10 )
  {
    this->pTempBindData = 0;
  }
  else
  {
    icreateInfo.pHeap = 0;
    memset(&icreateInfo.pLog, 0, 16);
    icreateInfo.Type = Create_ExportImage;
    icreateInfo.Use = 1;
    icreateInfo.RUse = Use_Bitmap;
    Scaleform::String::String(&icreateInfo.ExportName);
    v12 = (Scaleform::GFx::LogState *)pls[1].__vftable;
    pdefImpla = (Scaleform::GFx::ImageFileHandlerRegistry *)pls[2].RefCount.Value;
    plsa = (Scaleform::GFx::FileOpener *)pls->pLib[1].__vftable;
    if ( v12 )
    {
      GlobalLog = v12->pLog.pObject;
      if ( !GlobalLog )
        GlobalLog = Scaleform::Log::GetGlobalLog();
    }
    else
    {
      GlobalLog = 0;
    }
    icreateInfo.pLog = GlobalLog;
    icreateInfo.pFileOpener = plsa;
    v14 = pdefImpl->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::__vftable;
    icreateInfo.pIFHRegistry = pdefImpla;
    v15 = v14->GetBindDataHeap(pdefImpl);
    pLib = (Scaleform::GFx::MovieDefBindStates *)pls->pLib;
    Begin = RefCount->Begin;
    icreateInfo.pHeap = v15;
    v18 = (int)Begin(RefCount, &this->GlyphTextureIdGen, pLib->pImageCreator.pObject, &icreateInfo);
    v19 = this->pImagePacker.pObject;
    v20 = (Scaleform::GFx::ImagePacker *)v18;
    if ( v19 )
      Scaleform::RefCountNTSImpl::Release(v19);
    this->pImagePacker.pObject = v20;
    v20->SetBindData(v20, this->pBindData.pObject);
    v21 = (Scaleform::GFx::TempBindData *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 4, 0);
    if ( v21 )
      v21->FillStyleImageWrap.pTable = 0;
    else
      v21 = 0;
    v22 = (void *)(icreateInfo.ExportName.HeapTypeBits & 0xFFFFFFFC);
    v23 = (volatile LONG *)((icreateInfo.ExportName.HeapTypeBits & 0xFFFFFFFC) + 4);
    this->pTempBindData = v21;
    if ( InterlockedExchangeAdd(v23, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
  }
}
