char __thiscall Scaleform::GFx::AS3ValueObjectInterface::CreateEmptyMovieClip(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::ASStringNode *pdata,
        Scaleform::GFx::Value *pmc,
        __m128i *instanceName,
        Scaleform::GFx::DisplayObjectBase *depth)
{
  Scaleform::GFx::AMP::ViewStats *v6; // eax
  Scaleform::GFx::AS3::MovieRoot *pObject; // edi
  unsigned int Size; // eax
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  const char *v13; // ebp
  Scaleform::GFx::AS3::ASVM *v14; // esi
  bool v15; // al
  Scaleform::AmpStats *v16; // edi
  void (__thiscall **v17)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v18; // rax
  Scaleform::GFx::AS3::Value::V1U v19; // esi
  int v20; // eax
  Scaleform::AmpStats *v21; // edi
  void (__thiscall **v22)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v23; // rax
  Scaleform::GFx::ASStringNode *v24; // eax
  int v25; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v26; // ecx
  Scaleform::GFx::DisplayObjectBase *v27; // eax
  Scaleform::AmpStats *v28; // esi
  void (__thiscall **v29)(Scaleform::AmpStats *, unsigned __int64); // edi
  unsigned __int64 v30; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value asObj; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value undefVal; // [esp+2Ch] [ebp-10h] BYREF

  v6 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip,
    v6,
    "ObjectInterface::CreateEmptyMovieClip",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip);
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  Size = pdata->Size;
  if ( (unsigned int)(*(_DWORD *)(Size + 60) - 23) >= 6 || (*(_DWORD *)(Size + 56) & 0x20) != 0 )
  {
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.Stats )
    {
      p_NativePopCallstack = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.Stats->NativePopCallstack;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.StartTicks) >> 32);
    }
    return 0;
  }
  else
  {
    v13 = pdata[2].pData;
    asObj.Flags = 0;
    asObj.Bonus.pWeakProxy = 0;
    v14 = pObject->pAVM.pObject;
    v15 = Scaleform::GFx::AS3::VM::Construct(
            v14,
            "flash.display.Sprite",
            (Scaleform::GFx::ASStringNode *)v14->CurrentDomain,
            &asObj,
            0,
            0,
            0);
    if ( v14->HandleException )
      goto LABEL_10;
    if ( v15 )
      Scaleform::GFx::AS3::VM::ExecuteCode(v14, 1u);
    if ( v14->HandleException )
    {
LABEL_10:
      Scaleform::GFx::AS3::Value::~Value(&asObj);
      v16 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.Stats;
      if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.Stats )
      {
        v17 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.Stats->NativePopCallstack;
        v18 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v17)(
          v16,
          v18 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.StartTicks),
          (v18 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.StartTicks) >> 32);
      }
      return 0;
    }
    else
    {
      v19 = asObj.value.VS._1;
      v20 = *(_DWORD *)(asObj.value.VS._1.VInt + 20);
      if ( (unsigned int)(*(_DWORD *)(v20 + 60) - 17) >= 0xC || (*(_DWORD *)(v20 + 56) & 0x20) != 0 )
      {
        Scaleform::GFx::AS3::Value::~Value(&asObj);
        v21 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.Stats;
        if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.Stats )
        {
          v22 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.Stats->NativePopCallstack;
          v23 = Scaleform::Timer::GetProfileTicks();
          ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v22)(
            v21,
            v23 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.StartTicks),
            (v23 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.StartTicks) >> 32);
        }
        return 0;
      }
      else
      {
        undefVal.Flags = 0;
        undefVal.Bonus.pWeakProxy = 0;
        pdata = Scaleform::GFx::ASStringManager::CreateStringNode(pObject->BuiltinsMgr.pStringManager, instanceName);
        ++pdata->RefCount;
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::nameSet(
          (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v19.VInt,
          &undefVal,
          (const Scaleform::GFx::ASString *)&pdata);
        v24 = pdata;
        --pdata->RefCount;
        if ( !v24->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
        if ( v13
          && (v25 = (*(int (__thiscall **)(const char *))(*(_DWORD *)&v13[4 * *((unsigned __int8 *)v13 + 65)] + 20))(&v13[4 * *((unsigned __int8 *)v13 + 65)])) != 0 )
        {
          v26 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v25 - 36);
        }
        else
        {
          v26 = 0;
        }
        v27 = depth;
        if ( (int)depth < 0 )
          v27 = (Scaleform::GFx::DisplayObjectBase *)v26->pDispObj[1].pRenNode.pObject;
        Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChildAt(
          v26,
          *(Scaleform::GFx::InteractiveObject **)(v19.VInt + 48),
          v27);
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &asObj, (Scaleform::GFx::ASStringNode *)pmc);
        Scaleform::GFx::AS3::Value::~Value(&undefVal);
        Scaleform::GFx::AS3::Value::~Value(&asObj);
        v28 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.Stats;
        if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.Stats )
        {
          v29 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.Stats->NativePopCallstack;
          v30 = Scaleform::Timer::GetProfileTicks();
          ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v29)(
            v28,
            v30 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.StartTicks),
            (v30 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip.StartTicks) >> 32);
        }
        return 1;
      }
    }
  }
}
