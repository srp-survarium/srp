void __thiscall Scaleform::GFx::AS2::`anonymous namespace'::CandidateListLoader::NotifyOnLoadError(
        Scaleform::GFx::AS2::CandidateListLoader *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *ptarget,
        char *errorCode,
        int status)
{
  Scaleform::GFx::AS2::IMEManager *pObject; // edx
  void *v7; // edi
  Scaleform::String level0Path; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::GFx::Value v; // [esp+Ch] [ebp-18h] BYREF

  Scaleform::String::operator=(
    &this->pASIMEManager.pObject->CandidateSwfErrorMsg,
    "Error in loading candidate list from ");
  Scaleform::String::operator+=(
    &this->pASIMEManager.pObject->CandidateSwfErrorMsg,
    &this->pASIMEManager.pObject->CandidateSwfPath);
  if ( this->pASIMEManager.pObject->pMovie )
  {
    Scaleform::String::String(&level0Path);
    Scaleform::GFx::AS2::MovieRoot::GetLevel0Path(
      (Scaleform::GFx::AS2::MovieRoot *)this->pASIMEManager.pObject->pMovie->pASMovieRoot.pObject,
      &level0Path);
    Scaleform::String::AppendString(&this->pASIMEManager.pObject->CandidateSwfErrorMsg, " at ", 0xFFFFFFFF);
    Scaleform::String::operator+=(&this->pASIMEManager.pObject->CandidateSwfErrorMsg, &level0Path);
    pObject = this->pASIMEManager.pObject;
    v.mValue.NValue = -1.0;
    v.pObjectInterface = 0;
    v.Type = VT_Number;
    Scaleform::GFx::Movie::SetVariable(pObject->pMovie, "_global.gfx_ime_candidate_list_state", &v, SV_Sticky);
    if ( (v.Type & 0x40) != 0 )
    {
      v.pObjectInterface->ObjectRelease(v.pObjectInterface, &v, (void *)v.mValue.IValue);
      v.pObjectInterface = 0;
    }
    v.Type = VT_Undefined;
    v7 = (void *)(level0Path.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((level0Path.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  }
  Scaleform::String::AppendString(&this->pASIMEManager.pObject->CandidateSwfErrorMsg, ": ", 0xFFFFFFFF);
  Scaleform::String::AppendString(&this->pASIMEManager.pObject->CandidateSwfErrorMsg, errorCode, 0xFFFFFFFF);
}
