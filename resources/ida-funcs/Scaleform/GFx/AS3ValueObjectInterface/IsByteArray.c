char __thiscall Scaleform::GFx::AS3ValueObjectInterface::IsByteArray(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  Scaleform::GFx::ASMovieRootBase_vtbl *v4; // esi
  Scaleform::GFx::ASString *v5; // esi
  _DWORD *v6; // edi
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpStats *v11; // esi
  Scaleform::AmpStats_vtbl *v12; // edi
  unsigned __int64 v13; // rax
  Scaleform::StringDataPtr qname; // [esp+8h] [ebp-30h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsByteArray; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+20h] [ebp-18h] BYREF

  v3 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_IsByteArray,
    v3,
    "ObjectInterface::IsByteArray",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_IsByteArray);
  v4 = this->pMovieRoot->pASMovieRoot.pObject[2].__vftable;
  qname.pStr = "flash.utils.ByteArray";
  qname.Size = 21;
  Scaleform::GFx::AS3::Multiname::Multiname(
    &mn,
    (const Scaleform::GFx::AS3::VM *)v4,
    (Scaleform::GFx::ASStringNode *)&qname);
  v5 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
         (Scaleform::GFx::AS3::VM *)v4,
         &mn,
         (Scaleform::GFx::ASStringNode *)v4[1].GenerateMouseEvents);
  if ( !v5 )
    goto LABEL_8;
  v6 = (_DWORD *)pdata[5];
  if ( !v6[17] )
    (*(void (__thiscall **)(_DWORD))(*v6 + 56))(pdata[5]);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
         (Scaleform::GFx::AS3::ClassTraits::Traits *)v5,
         *(const Scaleform::GFx::AS3::ClassTraits::Traits **)(v6[17] + 20)) )
  {
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsByteArray.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsByteArray.Stats )
    {
      v8 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsByteArray.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_IsByteArray.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsByteArray.StartTicks) >> 32);
    }
    return 1;
  }
  else
  {
LABEL_8:
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    v11 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsByteArray.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsByteArray.Stats )
    {
      v12 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsByteArray.Stats->__vftable;
      v13 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v12->NativePopCallstack)(
        v11,
        v13 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_IsByteArray.StartTicks),
        (v13 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsByteArray.StartTicks) >> 32);
    }
    return 0;
  }
}
