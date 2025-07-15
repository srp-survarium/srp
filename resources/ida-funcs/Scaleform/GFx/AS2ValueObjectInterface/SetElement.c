char __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetElement(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        int idx,
        const Scaleform::GFx::Value *value)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::GFx::AS2::ArrayObject *v6; // edi
  Scaleform::GFx::AS2::MovieRoot *pObject; // ecx
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v9; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS2::Value pdestVal; // [esp+8h] [ebp-20h] BYREF
  Scaleform::AmpFunctionTimer v13; // [esp+18h] [ebp-10h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v13,
    v5,
    "ObjectInterface::SetElement",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetElement);
  if ( pdata )
    v6 = (Scaleform::GFx::AS2::ArrayObject *)(pdata - 16);
  else
    v6 = 0;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(pObject, value, &pdestVal);
  Scaleform::GFx::AS2::ArrayObject::SetElementSafe(v6, idx, &pdestVal);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  Stats = v13.Stats;
  if ( v13.Stats )
  {
    v9 = v13.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v9->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v13.StartTicks),
      (ProfileTicks - v13.StartTicks) >> 32);
  }
  return 1;
}
