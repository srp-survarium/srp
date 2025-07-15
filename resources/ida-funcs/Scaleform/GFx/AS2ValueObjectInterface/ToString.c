void __thiscall Scaleform::GFx::AS2ValueObjectInterface::ToString(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::String *pstr,
        Scaleform::GFx::Value *thisVal)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::AS2::MovieRoot *pObject; // esi
  int v6; // ecx
  Scaleform::GFx::AS2::Environment *v7; // edi
  Scaleform::GFx::ASStringNode *v8; // edi
  const Scaleform::String *v9; // eax
  void *v10; // esi
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v13; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::String v15; // [esp+8h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::Value pdestVal; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::AmpFunctionTimer v17; // [esp+1Ch] [ebp-10h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v17,
    v4,
    "ObjectInterface::ToString",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_ToString);
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v6 = (int)pObject->pMovieImpl->pMainMovie + 4 * pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v7 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 124))(v6);
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(pObject, thisVal, &pdestVal);
  Scaleform::GFx::AS2::Value::ToStringImpl(&pdestVal, (Scaleform::GFx::ASString *)&thisVal, v7, -1, 0);
  v8 = (Scaleform::GFx::ASStringNode *)thisVal;
  Scaleform::String::String(&v15, (const __m128i *)thisVal->pObjectInterface);
  Scaleform::String::operator=(pstr, v9);
  v10 = (void *)(v15.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v15.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
  if ( v8->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  Stats = v17.Stats;
  if ( v17.Stats )
  {
    v13 = v17.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v13->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v17.StartTicks),
      (ProfileTicks - v17.StartTicks) >> 32);
  }
}
