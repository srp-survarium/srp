int __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetByteArraySize(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  Scaleform::GFx::ASMovieRootBase_vtbl *v4; // esi
  Scaleform::GFx::ASString *v5; // edi
  _DWORD *v6; // esi
  int v7; // ebx
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v9; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpStats *v12; // esi
  Scaleform::AmpStats_vtbl *v13; // edi
  unsigned __int64 v14; // rax
  Scaleform::StringDataPtr qname; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetByteArraySize; // [esp+14h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+24h] [ebp-18h] BYREF

  v3 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetByteArraySize,
    v3,
    "ObjectInterface::GetByteArraySize",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetByteArraySize);
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
    v7 = pdata[10];
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetByteArraySize.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetByteArraySize.Stats )
    {
      v9 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetByteArraySize.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v9->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetByteArraySize.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetByteArraySize.StartTicks) >> 32);
    }
    return v7;
  }
  else
  {
LABEL_8:
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    v12 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetByteArraySize.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetByteArraySize.Stats )
    {
      v13 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetByteArraySize.Stats->__vftable;
      v14 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v13->NativePopCallstack)(
        v12,
        v14 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetByteArraySize.StartTicks),
        (v14 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetByteArraySize.StartTicks) >> 32);
    }
    return 0;
  }
}
