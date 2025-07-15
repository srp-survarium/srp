void __thiscall Scaleform::GFx::AS3ValueObjectInterface::ToString(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::String *pstr,
        Scaleform::GFx::ASStringNode *thisVal)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::AS3::MovieRoot *pObject; // esi
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v10; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::ASString asStr; // [esp+8h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::Value asVal; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_ToString; // [esp+1Ch] [ebp-10h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_ToString,
    v4,
    "ObjectInterface::ToString",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_ToString);
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  asVal.Flags = 0;
  asVal.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, thisVal, &asVal);
  pStringManager = pObject->BuiltinsMgr.pStringManager;
  asStr.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  Scaleform::GFx::AS3::Value::Convert2String(&asVal, (Scaleform::GFx::AS3::CheckResult *)&thisVal, &asStr);
  Scaleform::String::AssignString(pstr, (const __m128i *)asStr.pNode->pData, asStr.pNode->Size);
  pNode = asStr.pNode;
  --asStr.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (asVal.Flags & 0x1F) > 9 )
  {
    if ( (asVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = asVal.Bonus.pWeakProxy;
      --asVal.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      asVal.Flags &= 0xFFFFFDE0;
      memset(&asVal.Bonus, 0, 12);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&asVal);
    }
  }
  Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_ToString.Stats;
  if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_ToString.Stats )
  {
    v10 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_ToString.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v10->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_ToString.StartTicks),
      (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_ToString.StartTicks) >> 32);
  }
}
