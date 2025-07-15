char __thiscall Scaleform::GFx::AS3ValueObjectInterface::PushBack(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::ASStringNode *value)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::AS3::MovieRoot *pObject; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS3::Value asval; // [esp+8h] [ebp-20h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_PushBack; // [esp+18h] [ebp-10h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_PushBack,
    v4,
    "ObjectInterface::PushBack",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_PushBack);
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  asval.Flags = 0;
  asval.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, value, &asval);
  Scaleform::GFx::AS3::Impl::SparseArray::PushBack((Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32), &asval);
  if ( (asval.Flags & 0x1F) > 9 )
  {
    if ( (asval.Flags & 0x200) != 0 )
    {
      pWeakProxy = asval.Bonus.pWeakProxy;
      --asval.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      asval.Flags &= 0xFFFFFDE0;
      memset(&asval.Bonus, 0, 12);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&asval);
    }
  }
  Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_PushBack.Stats;
  if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_PushBack.Stats )
  {
    v8 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_PushBack.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_PushBack.StartTicks),
      (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_PushBack.StartTicks) >> 32);
  }
  return 1;
}
