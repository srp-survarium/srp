char __thiscall Scaleform::GFx::AS3ValueObjectInterface::DeleteMember(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        void *pdata,
        __m128i *name,
        bool isdobj)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::GFx::ASMovieRootBase *pObject; // eax
  Scaleform::GFx::ASMovieRootBase_vtbl *v7; // edi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v9; // esi
  Scaleform::GFx::ASStringManager *pManager; // edx
  Scaleform::GFx::AS3::GASRefCountBase *GenerateTouchEvents; // eax
  void *pWeakProxy; // eax
  bool v13; // zf
  char v14; // bl
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS3::Value nameVal; // [esp+10h] [ebp-38h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_DeleteMember; // [esp+20h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+30h] [ebp-18h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_DeleteMember,
    v5,
    "ObjectInterface::DeleteMember",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_DeleteMember);
  pObject = this->pMovieRoot->pASMovieRoot.pObject;
  v7 = pObject[2].__vftable;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)pObject[21].pASSupport.pObject,
                 name);
  v9 = StringNode;
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
  GenerateTouchEvents = (Scaleform::GFx::AS3::GASRefCountBase *)v7[1].GenerateTouchEvents;
  mn.Kind = MN_QName;
  mn.Obj.pObject = GenerateTouchEvents;
  if ( GenerateTouchEvents )
    GenerateTouchEvents->RefCount = (GenerateTouchEvents->RefCount + 1) & 0x8FBFFFFF;
  mn.Name.Flags = 0;
  mn.Name.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&mn, &nameVal);
  if ( (nameVal.Flags & 0x1F) > 9 )
  {
    if ( (nameVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = nameVal.Bonus.pWeakProxy;
      v13 = nameVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&nameVal);
    }
  }
  v13 = v9->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v14 = *(_BYTE *)(*(int (__thiscall **)(void *, __m128i **, Scaleform::GFx::AS3::Multiname *))(*(_DWORD *)pdata + 36))(
                    pdata,
                    &name,
                    &mn);
  Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_DeleteMember.Stats;
  if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_DeleteMember.Stats )
  {
    p_NativePopCallstack = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_DeleteMember.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_DeleteMember.StartTicks),
      (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_DeleteMember.StartTicks) >> 32);
  }
  return v14;
}
