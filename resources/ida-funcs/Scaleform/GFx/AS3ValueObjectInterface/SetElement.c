char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetElement(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        Scaleform::GFx::ASStringNode *value)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::GFx::AS3::MovieRoot *pObject; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v9; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS3::Value asval; // [esp+8h] [ebp-20h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetElement; // [esp+18h] [ebp-10h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetElement,
    v5,
    "ObjectInterface::SetElement",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetElement);
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  asval.Flags = 0;
  asval.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, value, &asval);
  Scaleform::GFx::AS3::Impl::SparseArray::Set((Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32), idx, &asval);
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
  Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetElement.Stats;
  if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetElement.Stats )
  {
    v9 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetElement.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v9->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetElement.StartTicks),
      (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetElement.StartTicks) >> 32);
  }
  return 1;
}
