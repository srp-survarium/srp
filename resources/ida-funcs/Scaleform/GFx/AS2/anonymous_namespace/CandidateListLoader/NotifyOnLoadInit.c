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
  Scaleform::String::DataDesc *pData; // edi
  int v10; // eax
  void *v11; // esi
  Scaleform::GFx::Value value; // [esp+Ch] [ebp-18h] BYREF

  pObject = this->pASIMEManager.pObject;
  pimeManager = pObject->pimeManager;
  if ( pObject->pMovie )
  {
    v6 = this->pASIMEManager.pObject;
    value.mValue.NValue = 2.0;
    value.pObjectInterface = 0;
    value.Type = VT_Number;
    Scaleform::GFx::Movie::SetVariable(v6->pMovie, "_global.gfx_ime_candidate_list_state", &value, SV_Sticky);
    v7 = this->pASIMEManager.pObject->CandidateSwfPath.HeapTypeBits & 0xFFFFFFFC;
    if ( (value.Type & 0x40) != 0 )
    {
      value.pObjectInterface->ObjectRelease(value.pObjectInterface, &value, (void *)value.mValue.IValue);
      value.pObjectInterface = 0;
    }
    v8 = this->pASIMEManager.pObject;
    value.Type = VT_String;
    value.mValue.IValue = v7 + 8;
    Scaleform::GFx::Movie::SetVariable(v8->pMovie, "_global.gfx_ime_candidate_list_path", &value, SV_Sticky);
    if ( (value.Type & 0x40) != 0 )
      value.pObjectInterface->ObjectRelease(value.pObjectInterface, &value, (void *)value.mValue.IValue);
  }
  pData = ptarget.pData;
  if ( ptarget.pData )
  {
    v10 = (*(int (__thiscall **)(Scaleform::String::DataDesc *))(*(_DWORD *)ptarget.HeapTypeBits + 256))(ptarget.pData);
    if ( *(_DWORD *)(v10 + 8) )
      (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(v10 + 8) + 8))(*(_DWORD *)(v10 + 8), v10);
    Scaleform::String::String(&ptarget);
    Scaleform::GFx::DisplayObject::GetAbsolutePath((Scaleform::GFx::DisplayObject *)pData, &ptarget);
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
