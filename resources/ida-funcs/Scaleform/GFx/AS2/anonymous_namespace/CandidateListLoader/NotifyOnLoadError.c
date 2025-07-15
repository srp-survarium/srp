void __thiscall Scaleform::GFx::AS2::`anonymous namespace'::CandidateListLoader::NotifyOnLoadError(
        Scaleform::GFx::AS2::CandidateListLoader *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *ptarget,
        const __m128i *errorCode,
        int status)
{
  Scaleform::GFx::AS2::IMEManager *pObject; // edx
  void *v7; // edi
  Scaleform::String src; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::GFx::Value value; // [esp+Ch] [ebp-18h] BYREF

  Scaleform::String::operator=(
    &this->pASIMEManager.pObject->CandidateSwfErrorMsg,
    (const __m128i *)"Error in loading candidate list from ");
  Scaleform::String::operator+=(
    &this->pASIMEManager.pObject->CandidateSwfErrorMsg,
    &this->pASIMEManager.pObject->CandidateSwfPath);
  if ( this->pASIMEManager.pObject->pMovie )
  {
    Scaleform::String::String(&src);
    Scaleform::GFx::AS2::MovieRoot::GetLevel0Path(
      (Scaleform::GFx::AS2::MovieRoot *)this->pASIMEManager.pObject->pMovie->pASMovieRoot.pObject,
      &src);
    Scaleform::String::AppendString(
      &this->pASIMEManager.pObject->CandidateSwfErrorMsg,
      (const __m128i *)" at ",
      0xFFFFFFFF);
    Scaleform::String::operator+=(&this->pASIMEManager.pObject->CandidateSwfErrorMsg, &src);
    pObject = this->pASIMEManager.pObject;
    value.mValue.NValue = -1.0;
    value.pObjectInterface = 0;
    value.Type = VT_Number;
    Scaleform::GFx::Movie::SetVariable(pObject->pMovie, "_global.gfx_ime_candidate_list_state", &value, SV_Sticky);
    if ( (value.Type & 0x40) != 0 )
    {
      value.pObjectInterface->ObjectRelease(value.pObjectInterface, &value, (void *)value.mValue.IValue);
      value.pObjectInterface = 0;
    }
    value.Type = VT_Undefined;
    v7 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  }
  Scaleform::String::AppendString(&this->pASIMEManager.pObject->CandidateSwfErrorMsg, (const __m128i *)": ", 0xFFFFFFFF);
  Scaleform::String::AppendString(&this->pASIMEManager.pObject->CandidateSwfErrorMsg, errorCode, 0xFFFFFFFF);
}
