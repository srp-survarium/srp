void __thiscall Scaleform::GFx::AS2::`anonymous namespace'::CandidateListLoader::NotifyOnLoadInit(
        Scaleform::GFx::AS2::CandidateListLoader *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::String ptarget)
{
  Scaleform::GFx::AS2::IMEManager *pObject; // eax
  Scaleform::GFx::IMEManagerBase *pimeManager; // ebx
  Scaleform::GFx::AS2::IMEManager *v6; // ecx
  unsigned int v7; // edi
  Scaleform::GFx::AS2::IMEManager *v8; // ecx
  Scaleform::GFx::DisplayObject *pData; // edi
  Scaleform::GFx::MovieDefImpl *v10; // eax
  void *v11; // esi
  Scaleform::GFx::Value v; // [esp+Ch] [ebp-18h] BYREF

  pObject = this->pASIMEManager.pObject;
  pimeManager = pObject->pimeManager;
  if ( pObject->pMovie )
  {
    v6 = this->pASIMEManager.pObject;
    v.mValue.NValue = 2.0;
    v.pObjectInterface = 0;
    v.Type = VT_Number;
    Scaleform::GFx::Movie::SetVariable(v6->pMovie, "_global.gfx_ime_candidate_list_state", &v, SV_Sticky);
    v7 = this->pASIMEManager.pObject->CandidateSwfPath.HeapTypeBits & 0xFFFFFFFC;
    if ( (v.Type & 0x40) != 0 )
    {
      v.pObjectInterface->ObjectRelease(v.pObjectInterface, &v, (void *)v.mValue.IValue);
      v.pObjectInterface = 0;
    }
    v8 = this->pASIMEManager.pObject;
    v.Type = VT_String;
    v.mValue.IValue = v7 + 8;
    Scaleform::GFx::Movie::SetVariable(v8->pMovie, "_global.gfx_ime_candidate_list_path", &v, SV_Sticky);
    if ( (v.Type & 0x40) != 0 )
      v.pObjectInterface->ObjectRelease(v.pObjectInterface, &v, (void *)v.mValue.IValue);
  }
  pData = (Scaleform::GFx::DisplayObject *)ptarget.pData;
  if ( ptarget.pData )
  {
    v10 = (Scaleform::GFx::MovieDefImpl *)(*(int (__thiscall **)(Scaleform::String::DataDesc *))(*(_DWORD *)ptarget.HeapTypeBits
                                                                                               + 256))(ptarget.pData);
    if ( v10->pLib )
      v10->pLib->PinResource(v10->pLib, v10);
    Scaleform::String::String(&ptarget);
    Scaleform::GFx::DisplayObject::GetAbsolutePath(pData, &ptarget);
    Scaleform::String::operator=(&this->pASIMEManager.pObject->CandListPath, &ptarget);
    if ( pimeManager )
      pimeManager->OnCandidateListLoaded(pimeManager, (const char *)((ptarget.HeapTypeBits & 0xFFFFFFFC) + 8));
    v11 = (void *)(ptarget.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((ptarget.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
  }
  else if ( pimeManager )
  {
    pimeManager->OnCandidateListLoaded(pimeManager, 0);
  }
}
