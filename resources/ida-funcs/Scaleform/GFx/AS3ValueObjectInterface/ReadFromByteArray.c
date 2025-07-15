char __thiscall Scaleform::GFx::AS3ValueObjectInterface::ReadFromByteArray(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *pdata,
        unsigned __int8 *destBuff,
        unsigned int destBuffSz)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::GFx::ASMovieRootBase_vtbl *v6; // esi
  Scaleform::GFx::ASString *v7; // edi
  _DWORD *v8; // esi
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v10; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpStats *v13; // esi
  Scaleform::AmpStats_vtbl *v14; // edi
  unsigned __int64 v15; // rax
  Scaleform::StringDataPtr qname; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_ReadFromByteArray; // [esp+14h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+24h] [ebp-18h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_ReadFromByteArray,
    v5,
    "ObjectInterface::ReadFromByteArray",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_ReadFromByteArray);
  v6 = this->pMovieRoot->pASMovieRoot.pObject[2].__vftable;
  qname.pStr = "flash.utils.ByteArray";
  qname.Size = 21;
  Scaleform::GFx::AS3::Multiname::Multiname(
    &mn,
    (const Scaleform::GFx::AS3::VM *)v6,
    (Scaleform::GFx::ASStringNode *)&qname);
  v7 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
         (Scaleform::GFx::AS3::VM *)v6,
         &mn,
         (Scaleform::GFx::ASStringNode *)v6[1].GenerateMouseEvents);
  if ( !v7 )
    goto LABEL_8;
  v8 = &pdata->pTraits.pObject->Scaleform::GFx::AS3::Instances::fl::Object::Scaleform::GFx::AS3::Instance::Scaleform::GFx::AS3::Object::__vftable;
  if ( !v8[17] )
    (*(void (__thiscall **)(Scaleform::GFx::AS3::Traits *))(*v8 + 56))(pdata->pTraits.pObject);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
         (Scaleform::GFx::AS3::ClassTraits::Traits *)v7,
         *(const Scaleform::GFx::AS3::ClassTraits::Traits **)(v8[17] + 20)) )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Get(pdata, destBuff, destBuffSz);
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_ReadFromByteArray.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_ReadFromByteArray.Stats )
    {
      v10 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_ReadFromByteArray.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v10->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_ReadFromByteArray.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_ReadFromByteArray.StartTicks) >> 32);
    }
    return 1;
  }
  else
  {
LABEL_8:
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    v13 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_ReadFromByteArray.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_ReadFromByteArray.Stats )
    {
      v14 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_ReadFromByteArray.Stats->__vftable;
      v15 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v14->NativePopCallstack)(
        v13,
        v15 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_ReadFromByteArray.StartTicks),
        (v15 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_ReadFromByteArray.StartTicks) >> 32);
    }
    return 0;
  }
}
