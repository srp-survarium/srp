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
  volatile int RefCount; // ebp
  Scaleform::GFx::Resource_vtbl *v12; // eax
  Scaleform::Log *GlobalLog; // eax
  Scaleform::GFx::MovieDefImpl_vtbl *v14; // edx
  int v15; // eax
  Scaleform::GFx::ResourceLibBase *pLib; // ecx
  int (__thiscall *v17)(volatile int, Scaleform::GFx::ResourceId *, Scaleform::GFx::ResourceLibBase_vtbl *, int *); // edx
  int v18; // eax
  Scaleform::GFx::ImagePacker *v19; // ecx
  Scaleform::GFx::ImagePacker *v20; // edi
  Scaleform::GFx::TempBindData *v21; // eax
  void *v22; // edi
  volatile LONG *v23; // [esp-8h] [ebp-4Ch]
  int v24; // [esp+10h] [ebp-34h] BYREF
  int v25; // [esp+14h] [ebp-30h]
  int v26; // [esp+18h] [ebp-2Ch]
  int v27; // [esp+1Ch] [ebp-28h]
  Scaleform::Log *v28; // [esp+20h] [ebp-24h]
  Scaleform::GFx::ResourceLibBase_vtbl *v29; // [esp+24h] [ebp-20h]
  volatile int v30; // [esp+28h] [ebp-1Ch]
  int v31; // [esp+2Ch] [ebp-18h]
  Scaleform::String v32; // [esp+38h] [ebp-Ch] BYREF
  Scaleform::GFx::ResourceLibBase_vtbl *v33; // [esp+48h] [ebp+4h]
  volatile int Value; // [esp+4Ch] [ebp+8h]

  Scaleform::GFx::LoaderTask::LoaderTask(this, pls, Id_MovieBind);
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
  RefCount = pls->pLib[4].RefCount;
  if ( !RefCount || v10 )
  {
    this->pTempBindData = 0;
  }
  else
  {
    v25 = 0;
    v28 = 0;
    v29 = 0;
    v30 = 0;
    v31 = 0;
    v24 = 2;
    v26 = 1;
    v27 = 1;
    Scaleform::String::String(&v32);
    v12 = pls[1].__vftable;
    Value = pls[2].RefCount.Value;
    v33 = pls->pLib[1].__vftable;
    if ( v12 )
    {
      GlobalLog = (Scaleform::Log *)v12[1].~Scaleform::GFx::Resource;
      if ( !GlobalLog )
        GlobalLog = Scaleform::Log::GetGlobalLog();
    }
    else
    {
      GlobalLog = 0;
    }
    v28 = GlobalLog;
    v29 = v33;
    v14 = pdefImpl->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::__vftable;
    v30 = Value;
    v15 = (int)v14->GetBindDataHeap(pdefImpl);
    pLib = pls->pLib;
    v17 = *(int (__thiscall **)(volatile int, Scaleform::GFx::ResourceId *, Scaleform::GFx::ResourceLibBase_vtbl *, int *))(*(_DWORD *)RefCount + 8);
    v25 = v15;
    v18 = v17(RefCount, &this->GlyphTextureIdGen, pLib[2].__vftable, &v24);
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
    v22 = (void *)(v32.HeapTypeBits & 0xFFFFFFFC);
    v23 = (volatile LONG *)((v32.HeapTypeBits & 0xFFFFFFFC) + 4);
    this->pTempBindData = v21;
    if ( InterlockedExchangeAdd(v23, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
  }
}
