char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetMember(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::String pdata,
        __m128i *name,
        Scaleform::GFx::ASStringNode *value,
        bool isdobj)
{
  Scaleform::GFx::AMP::ViewStats *v6; // eax
  Scaleform::GFx::AS3::MovieRoot *pObject; // edi
  __m128i *v8; // ebp
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v10; // esi
  Scaleform::GFx::ASStringManager *pManager; // edx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v12; // eax
  void *pWeakProxy; // eax
  bool v14; // zf
  Scaleform::String v15; // esi
  int v16; // eax
  unsigned int Size; // ecx
  unsigned int v18; // eax
  int v19; // ecx
  int v20; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v21; // esi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v22; // esi
  int v23; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *Flags; // ecx
  void *v25; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::ASStringNode *v31; // eax
  Scaleform::AmpStats *v32; // edi
  void (__thiscall **v33)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v34; // rax
  Scaleform::AmpStats *v35; // edi
  void (__thiscall **v36)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v37; // rax
  Scaleform::GFx::ASString propName; // [esp+10h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+14h] [ebp-4Ch]
  Scaleform::GFx::AS3::Value nameVal; // [esp+18h] [ebp-48h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember; // [esp+28h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value asval; // [esp+38h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+48h] [ebp-18h] BYREF

  v6 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember,
    v6,
    "ObjectInterface::SetMember",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetMember);
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v8 = name;
  vm = pObject->pAVM.pObject;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(pObject->BuiltinsMgr.pStringManager, name);
  v10 = StringNode;
  pManager = StringNode->pManager;
  ++StringNode->RefCount;
  nameVal.Flags = 10;
  nameVal.Bonus.pWeakProxy = 0;
  nameVal.value.VS._1.VInt = (int)StringNode;
  if ( StringNode == &pManager->NullStringNode )
  {
    nameVal.value.VS._1.VInt = 0;
    nameVal.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)nameVal.Bonus.pWeakProxy;
    nameVal.Flags = 12;
  }
  else
  {
    ++StringNode->RefCount;
  }
  v12 = vm->PublicNamespace.pObject;
  mn.Kind = MN_QName;
  mn.Obj.pObject = &v12->Scaleform::GFx::AS3::GASRefCountBase;
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  mn.Name.Flags = 0;
  mn.Name.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&mn, &nameVal);
  if ( (nameVal.Flags & 0x1F) > 9 )
  {
    if ( (nameVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = nameVal.Bonus.pWeakProxy;
      v14 = nameVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v14 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&nameVal);
    }
  }
  v14 = v10->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v15.pData = pdata.pData;
  v16 = *(_DWORD *)pdata.pData[1].Data;
  if ( (unsigned int)(*(_DWORD *)(v16 + 60) - 23) < 6 && (*(_DWORD *)(v16 + 56) & 0x20) == 0 )
  {
    Size = pdata.pData[4].Size;
    v18 = (*(_WORD *)(Size + 62) & 0x200) != 0 ? Size : 0;
    if ( v18
      && (v19 = *(unsigned __int8 *)((*(_WORD *)(Size + 62) & 0x200) != 0 ? Size + 0x41 : 65),
          (v20 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)(v18 + 4 * v19) + 20))(v18 + 4 * v19)) != 0) )
    {
      v21 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v20 - 36);
    }
    else
    {
      v21 = 0;
    }
    propName.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(pObject->BuiltinsMgr.pStringManager, v8);
    ++propName.pNode->RefCount;
    v22 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(
            v21,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)&nameVal,
            &propName)->pObject;
    if ( nameVal.Flags )
    {
      if ( (nameVal.Flags & 1) == 0 )
      {
        v23 = *(_DWORD *)(nameVal.Flags + 16);
        Flags = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)nameVal.Flags;
        if ( (v23 & 0x3FFFFF) != 0 )
        {
          *(_DWORD *)(nameVal.Flags + 16) = v23 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(Flags);
        }
      }
    }
    if ( v22 )
    {
      Scaleform::String::String(&pdata);
      nameVal.Flags = 0;
      nameVal.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)&pdata;
      Scaleform::Format<char const *>(
        (const Scaleform::MsgFormat::Sink *)&nameVal,
        "Property '{0}' already exists as a DisplayObject. SetMember aborted.",
        (const char **)&name);
      pObject->Output(
        &pObject->Scaleform::GFx::AS3::FlashUI,
        Output_Error,
        (const char *)((pdata.HeapTypeBits & 0xFFFFFFFC) + 8));
      v25 = (void *)(pdata.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((pdata.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v25);
      pNode = propName.pNode;
      --propName.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
      Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.Stats;
      if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.Stats )
      {
        p_NativePopCallstack = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.Stats->NativePopCallstack;
        ProfileTicks = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
          Stats,
          ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.StartTicks),
          (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.StartTicks) >> 32);
      }
      return 0;
    }
    v31 = propName.pNode;
    --propName.pNode->RefCount;
    if ( !v31->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v31);
    v15.pData = pdata.pData;
  }
  asval.Flags = 0;
  asval.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, value, &asval);
  if ( *(_BYTE *)(*(int (__thiscall **)(Scaleform::String, Scaleform::String *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*(_DWORD *)v15.HeapTypeBits + 24))(
                   v15,
                   &pdata,
                   &mn,
                   &asval) )
  {
    Scaleform::GFx::AS3::Value::~Value(&asval);
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    v35 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.Stats )
    {
      v36 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.Stats->NativePopCallstack;
      v37 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v36)(
        v35,
        v37 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.StartTicks),
        (v37 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.StartTicks) >> 32);
    }
    return 1;
  }
  else
  {
    if ( vm->HandleException )
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(vm);
    Scaleform::GFx::AS3::Value::~Value(&asval);
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    v32 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.Stats )
    {
      v33 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.Stats->NativePopCallstack;
      v34 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v33)(
        v32,
        v34 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.StartTicks),
        (v34 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetMember.StartTicks) >> 32);
    }
    return 0;
  }
}
