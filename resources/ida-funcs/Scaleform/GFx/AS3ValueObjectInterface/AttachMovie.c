char __thiscall Scaleform::GFx::AS3ValueObjectInterface::AttachMovie(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::GFx::Value *pmc,
        const char *symbolName,
        __m128i *instanceName,
        Scaleform::GFx::DisplayObjectBase *depth,
        const Scaleform::GFx::MemberValueSet *initArgs)
{
  Scaleform::GFx::AMP::ViewStats *v8; // eax
  Scaleform::GFx::AS3::MovieRoot *pObject; // ebp
  int v10; // eax
  Scaleform::GFx::DisplayObjContainer *v11; // edi
  Scaleform::GFx::AS3::VM *v12; // esi
  int v13; // eax
  int v14; // eax
  bool v15; // al
  Scaleform::GFx::LogState *v16; // edi
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  int v21; // esi
  Scaleform::AmpStats *v22; // edi
  void (__thiscall **v23)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v24; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *VInt; // esi
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  char *v28; // esi
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::AS3::GASRefCountBase *v30; // eax
  int v32; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v33; // esi
  Scaleform::GFx::LogState *v34; // ebx
  Scaleform::GFx::DisplayObjectBase *v35; // eax
  Scaleform::AmpStats *v36; // ebx
  void (__thiscall **v37)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v38; // rax
  char v39; // [esp+13h] [ebp-7Dh] BYREF
  Scaleform::GFx::ASString value; // [esp+14h] [ebp-7Ch] BYREF
  unsigned int i; // [esp+18h] [ebp-78h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pmcObj; // [esp+1Ch] [ebp-74h] BYREF
  Scaleform::GFx::ASString v; // [esp+20h] [ebp-70h] BYREF
  Scaleform::GFx::DisplayObjContainer *parentDispObj; // [esp+24h] [ebp-6Ch] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie; // [esp+28h] [ebp-68h] BYREF
  Scaleform::GFx::AS3::Value asObj; // [esp+38h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::Value propval; // [esp+48h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value undefVal; // [esp+58h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value nameVal; // [esp+68h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname propname; // [esp+78h] [ebp-18h] BYREF

  v8 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie,
    v8,
    "ObjectInterface::AttachMovie",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_AttachMovie);
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v10 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v10 + 60) - 23) >= 6 || (*(_DWORD *)(v10 + 56) & 0x20) != 0 )
  {
LABEL_16:
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.Stats )
    {
      p_NativePopCallstack = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.Stats->NativePopCallstack;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.StartTicks) >> 32);
    }
    return 0;
  }
  v11 = (Scaleform::GFx::DisplayObjContainer *)pdata[12];
  asObj.Flags = 0;
  asObj.Bonus.pWeakProxy = 0;
  v12 = pObject->pAVM.pObject;
  parentDispObj = v11;
  if ( v11
    && (v13 = (*(int (__thiscall **)(int))(*((_DWORD *)&v11->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v11->AvmObjOffset)
                                         + 20))((int)v11 + 4 * v11->AvmObjOffset)) != 0 )
  {
    v14 = v13 - 36;
  }
  else
  {
    v14 = 0;
  }
  v15 = Scaleform::GFx::AS3::VM::Construct(
          v12,
          symbolName,
          *(Scaleform::GFx::ASStringNode **)(v14 + 20),
          &asObj,
          0,
          0,
          0);
  if ( v12->HandleException )
    goto LABEL_11;
  if ( v15 )
    Scaleform::GFx::AS3::VM::ExecuteCode(v12, 1u);
  if ( v12->HandleException )
  {
LABEL_11:
    v16 = Scaleform::GFx::StateBag::GetLogState(
            &pObject->pMovieImpl->Scaleform::GFx::StateBag,
            (Scaleform::Ptr<Scaleform::GFx::LogState> *)&pmcObj)->pObject;
    if ( pmcObj )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pmcObj);
    if ( v16 )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        &v16->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "attachMovie() failed - export name \"%s\" is not found.",
        symbolName);
    v12->HandleException = 0;
    Scaleform::GFx::AS3::Value::~Value(&asObj);
    goto LABEL_16;
  }
  v21 = *(_DWORD *)(asObj.value.VS._1.VInt + 20);
  if ( (unsigned int)(*(_DWORD *)(v21 + 60) - 17) >= 0xC || (*(_DWORD *)(v21 + 56) & 0x20) != 0 )
  {
    Scaleform::GFx::AS3::Value::~Value(&asObj);
    v22 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.Stats )
    {
      v23 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.Stats->NativePopCallstack;
      v24 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v23)(
        v22,
        v24 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.StartTicks),
        (v24 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.StartTicks) >> 32);
    }
    return 0;
  }
  else
  {
    VInt = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)asObj.value.VS._1.VInt;
    undefVal.Flags = 0;
    undefVal.Bonus.pWeakProxy = 0;
    pStringManager = pObject->BuiltinsMgr.pStringManager;
    pmcObj = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)asObj.value.VS._1.VInt;
    value.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(pStringManager, instanceName);
    ++value.pNode->RefCount;
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::nameSet(VInt, &undefVal, &value);
    pNode = value.pNode;
    --value.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( initArgs )
    {
      i = 0;
      if ( initArgs->Data.Size )
      {
        value.pNode = 0;
        do
        {
          v28 = (char *)value.pNode + (unsigned int)initArgs->Data.Data;
          StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                         pObject->BuiltinsMgr.pStringManager,
                         (__m128i *)((*(_DWORD *)v28 & 0xFFFFFFFC) + 8),
                         *(_DWORD *)(*(_DWORD *)v28 & 0xFFFFFFFC) & 0x7FFFFFFF);
          ++StringNode->RefCount;
          v.pNode = StringNode;
          Scaleform::GFx::AS3::Value::Value(&nameVal, &v);
          v30 = &pObject->pAVM.pObject->PublicNamespace.pObject->Scaleform::GFx::AS3::GASRefCountBase;
          propname.Kind = MN_QName;
          propname.Obj.pObject = v30;
          if ( v30 )
            v30->RefCount = (v30->RefCount + 1) & 0x8FBFFFFF;
          propname.Name.Flags = 0;
          propname.Name.Bonus.pWeakProxy = 0;
          Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&propname, &nameVal);
          Scaleform::GFx::AS3::Value::~Value(&nameVal);
          if ( StringNode->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
          propval.Flags = 0;
          propval.Bonus.pWeakProxy = 0;
          Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, (Scaleform::GFx::ASStringNode *)(v28 + 8), &propval);
          pmcObj->SetProperty(pmcObj, (Scaleform::GFx::AS3::CheckResult *)&v39, &propname, &propval);
          Scaleform::GFx::AS3::Value::~Value(&propval);
          Scaleform::GFx::AS3::Multiname::~Multiname(&propname);
          value.pNode = (Scaleform::GFx::ASStringNode *)((char *)value.pNode + 32);
          ++i;
        }
        while ( i < initArgs->Data.Size );
        v11 = parentDispObj;
      }
    }
    if ( v11
      && (v32 = (*(int (__thiscall **)(int))(*((_DWORD *)&v11->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + v11->AvmObjOffset)
                                           + 20))((int)v11 + 4 * v11->AvmObjOffset)) != 0 )
    {
      v33 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v32 - 36);
    }
    else
    {
      v33 = 0;
    }
    if ( (int)depth > (int)v33->pDispObj[1].pRenNode.pObject )
    {
      v34 = Scaleform::GFx::StateBag::GetLogState(
              &pObject->pMovieImpl->Scaleform::GFx::StateBag,
              (Scaleform::Ptr<Scaleform::GFx::LogState> *)&parentDispObj)->pObject;
      if ( parentDispObj )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)parentDispObj);
      if ( v34 )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
          &v34->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "DAPI AttachMovie() depth requested (%d) for symbol \"%s\" is too large. Using next highest index (%d) instead.",
          depth,
          symbolName,
          v33->pDispObj[1].pRenNode.pObject);
    }
    if ( (int)depth < 0 || (int)depth > (int)v33->pDispObj[1].pRenNode.pObject )
      v35 = (Scaleform::GFx::DisplayObjectBase *)v33->pDispObj[1].pRenNode.pObject;
    else
      v35 = depth;
    Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChildAt(
      v33,
      (Scaleform::GFx::InteractiveObject *)pmcObj->pDispObj.pObject,
      v35);
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &asObj, (Scaleform::GFx::ASStringNode *)pmc);
    Scaleform::GFx::AS3::Value::~Value(&undefVal);
    Scaleform::GFx::AS3::Value::~Value(&asObj);
    v36 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.Stats )
    {
      v37 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.Stats->NativePopCallstack;
      v38 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v37)(
        v36,
        v38 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.StartTicks),
        (v38 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_AttachMovie.StartTicks) >> 32);
    }
    return 1;
  }
}
