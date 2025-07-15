char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetMember(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::AS3::RefCountBaseGC<328> *pdata,
        Scaleform::GFx::ASStringNode *name,
        Scaleform::GFx::Value *pval,
        bool isdobj)
{
  Scaleform::GFx::AMP::ViewStats *v6; // eax
  Scaleform::GFx::AS3::MovieRoot *pObject; // edi
  __m128i *v8; // ebp
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v10; // esi
  Scaleform::GFx::ASStringManager *pManager; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v12; // eax
  void *pWeakProxy; // eax
  bool v14; // zf
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v15; // esi
  bool (__thiscall *IsAS3Object)(Scaleform::GFx::AS3::RefCountBaseGC<328> *); // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *v17; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pNext; // ecx
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v22; // esi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v23; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v25; // ecx
  unsigned int v26; // eax
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::AmpStats *v28; // edi
  void (__thiscall **v29)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v30; // rax
  Scaleform::GFx::Value *v32; // esi
  Scaleform::GFx::ASStringNode *v33; // ecx
  const char *p_RefCount; // eax
  Scaleform::AmpStats *v35; // edi
  void (__thiscall **v36)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v37; // rax
  Scaleform::GFx::Value *v38; // esi
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpStats *v42; // edi
  void (__thiscall **v43)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v44; // rax
  Scaleform::GFx::AS3::VM *vm; // [esp+10h] [ebp-50h]
  Scaleform::GFx::AS3::Value::V2U v46; // [esp+14h] [ebp-4Ch]
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember; // [esp+18h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value nameVal; // [esp+28h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value asval; // [esp+38h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+48h] [ebp-18h] BYREF

  v6 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember,
    v6,
    "ObjectInterface::GetMember",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetMember);
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v8 = (__m128i *)name;
  vm = pObject->pAVM.pObject;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(pObject->BuiltinsMgr.pStringManager, (__m128i *)name);
  v10 = StringNode;
  pManager = StringNode->pManager;
  ++StringNode->RefCount;
  nameVal.Flags = 10;
  nameVal.Bonus.pWeakProxy = 0;
  nameVal.value.VS._1.VInt = (int)StringNode;
  if ( StringNode == &pManager->NullStringNode )
  {
    nameVal.value.VS._1.VInt = 0;
    nameVal.value.VS._2 = v46;
    nameVal.Flags = 12;
  }
  else
  {
    ++StringNode->RefCount;
  }
  v12 = &vm->PublicNamespace.pObject->Scaleform::GFx::AS3::GASRefCountBase;
  mn.Kind = MN_QName;
  mn.Obj.pObject = v12;
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
  v15 = pdata;
  IsAS3Object = pdata->__vftable[1].IsAS3Object;
  asval.Flags = 0;
  asval.Bonus.pWeakProxy = 0;
  if ( !*(_BYTE *)((int (__thiscall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))IsAS3Object)(
                    pdata,
                    &name,
                    &mn,
                    &asval) )
  {
    v17 = v15[1].__vftable;
    if ( (unsigned int)v17[2].GetAS3ObjectName - 23 >= 6 || ((int)v17[2].GetAS3ObjectType & 0x20) != 0 )
    {
      if ( vm->HandleException )
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(vm);
      v38 = pval;
      if ( (pval->Type & 0x40) != 0 )
      {
        ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(
          pval,
          pval->mValue.IValue);
        v38->pObjectInterface = 0;
      }
      v38->Type = VT_Undefined;
      Scaleform::GFx::AS3::Value::~Value(&asval);
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
      Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.Stats;
      if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.Stats )
      {
        p_NativePopCallstack = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.Stats->NativePopCallstack;
        ProfileTicks = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
          Stats,
          ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.StartTicks),
          (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.StartTicks) >> 32);
        return 0;
      }
    }
    else
    {
      pNext = v15[2].pNext;
      v19 = (HIWORD(pNext[3].__vftable) & 0x200) != 0 ? (unsigned int)pNext : 0;
      if ( v19
        && (v20 = *((HIWORD(pNext[3].__vftable) & 0x200) != 0
                  ? (unsigned __int8 *)&pNext[3]._pRCC + 1
                  : (unsigned __int8 *)65),
            (v21 = (*(int (__thiscall **)(int))(*(_DWORD *)(v19 + 4 * v20) + 20))(v19 + 4 * v20)) != 0) )
      {
        v22 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v21 - 36);
      }
      else
      {
        v22 = 0;
      }
      name = Scaleform::GFx::ASStringManager::CreateStringNode(pObject->BuiltinsMgr.pStringManager, v8);
      ++name->RefCount;
      v23 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(
              v22,
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)&pdata,
              (Scaleform::GFx::ASString *)&name)->pObject;
      if ( pdata )
      {
        if ( ((unsigned __int8)pdata & 1) != 0 )
        {
          pdata = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)pdata - 1);
        }
        else
        {
          RefCount = pdata->RefCount;
          v25 = pdata;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            pdata->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
          }
        }
      }
      if ( v23 )
      {
        v26 = (v23->RefCount + 1) & 0x8FBFFFFF;
        nameVal.Flags = 12;
        nameVal.Bonus.pWeakProxy = 0;
        nameVal.value.VS._1.VInt = (int)v23;
        v23->RefCount = v26;
        Scaleform::GFx::AS3::Value::Assign(&asval, &nameVal);
        Scaleform::GFx::AS3::Value::~Value(&nameVal);
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &asval, (Scaleform::GFx::ASStringNode *)pval);
        v27 = name;
        --name->RefCount;
        if ( !v27->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v27);
        Scaleform::GFx::AS3::Value::~Value(&asval);
        Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
        v28 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.Stats;
        if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.Stats )
        {
          v29 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.Stats->NativePopCallstack;
          v30 = Scaleform::Timer::GetProfileTicks();
          ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v29)(
            v28,
            v30 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.StartTicks),
            (v30 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.StartTicks) >> 32);
          return 1;
        }
        return 1;
      }
      if ( vm->HandleException )
        vm->HandleException = 0;
      v32 = pval;
      if ( (pval->Type & 0x40) != 0 )
      {
        ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(
          pval,
          pval->mValue.IValue);
        v32->pObjectInterface = 0;
      }
      v33 = name;
      p_RefCount = (const char *)&name->RefCount;
      v32->Type = VT_Undefined;
      if ( !--*(_DWORD *)p_RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v33);
      Scaleform::GFx::AS3::Value::~Value(&asval);
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
      v35 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.Stats;
      if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.Stats )
      {
        v36 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.Stats->NativePopCallstack;
        v37 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v36)(
          v35,
          v37 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.StartTicks),
          (v37 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.StartTicks) >> 32);
      }
    }
    return 0;
  }
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &asval, (Scaleform::GFx::ASStringNode *)pval);
  Scaleform::GFx::AS3::Value::~Value(&asval);
  Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  v42 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.Stats;
  if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.Stats )
  {
    v43 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.Stats->NativePopCallstack;
    v44 = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v43)(
      v42,
      v44 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.StartTicks),
      (v44 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetMember.StartTicks) >> 32);
  }
  return 1;
}
