char __thiscall Scaleform::GFx::AS2ValueObjectInterface::PushBack(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        const Scaleform::GFx::Value *value)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::AS2::ArrayObject *v5; // edi
  Scaleform::GFx::AS2::MovieRoot *pObject; // ecx
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS2::Value pdestVal; // [esp+8h] [ebp-20h] BYREF
  Scaleform::AmpFunctionTimer v12; // [esp+18h] [ebp-10h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v12,
    v4,
    "ObjectInterface::PushBack",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_PushBack);
  if ( pdata )
    v5 = (Scaleform::GFx::AS2::ArrayObject *)(pdata - 16);
  else
    v5 = 0;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(pObject, value, &pdestVal);
  Scaleform::GFx::AS2::ArrayObject::PushBack(v5, &pdestVal);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  Stats = v12.Stats;
  if ( v12.Stats )
  {
    v8 = v12.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v12.StartTicks),
      (ProfileTicks - v12.StartTicks) >> 32);
  }
  return 1;
}
