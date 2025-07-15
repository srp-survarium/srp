char __thiscall Scaleform::GFx::AS3ValueObjectInterface::HasMember(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::ASStringNode *pdata,
        __m128i *name,
        bool isdobj)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::GFx::ASMovieRootBase *pObject; // edi
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // eax
  Scaleform::GFx::AS3::GASRefCountBase *GenerateTouchEvents; // eax
  void *pWeakProxy; // eax
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // esi
  unsigned int Size; // ebp
  const char *v14; // ecx
  const char *v15; // eax
  int v16; // ecx
  int v17; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v18; // esi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v19; // esi
  int v20; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v21; // ecx
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::AmpStats *v23; // edi
  void (__thiscall **v24)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v25; // rax
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::AmpStats *v28; // edi
  void (__thiscall **v29)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v30; // rax
  Scaleform::GFx::AS3::WeakProxy *v31; // eax
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS3::VM *vm; // [esp+10h] [ebp-58h]
  Scaleform::GFx::AS3::Value::V2U v36; // [esp+14h] [ebp-54h]
  Scaleform::GFx::AS3::Value nameVal; // [esp+18h] [ebp-50h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember; // [esp+28h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+38h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+50h] [ebp-18h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember,
    v5,
    "ObjectInterface::HasMember",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_HasMember);
  pObject = this->pMovieRoot->pASMovieRoot.pObject;
  vm = (Scaleform::GFx::AS3::VM *)pObject[2].__vftable;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)pObject[21].pASSupport.pObject,
                 name);
  pManager = StringNode->pManager;
  ++StringNode->RefCount;
  nameVal.Flags = 10;
  nameVal.Bonus.pWeakProxy = 0;
  nameVal.value.VS._1.VInt = (int)StringNode;
  if ( StringNode == &pManager->NullStringNode )
  {
    nameVal.value.VS._1.VInt = 0;
    nameVal.value.VS._2 = v36;
    nameVal.Flags = 12;
  }
  else
  {
    ++StringNode->RefCount;
  }
  GenerateTouchEvents = (Scaleform::GFx::AS3::GASRefCountBase *)pObject[2].__vftable[1].GenerateTouchEvents;
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
      v11 = nameVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&nameVal);
    }
  }
  v11 = StringNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v12 = pdata;
  memset(&prop, 0, 16);
  Scaleform::GFx::AS3::Object::FindProperty(
    (Scaleform::GFx::AS3::Object *)pdata,
    &prop,
    (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&mn,
    FindGet);
  if ( (prop.This.Flags & 0x1F) != 0
    && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
    && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0)
    || (Size = v12->Size, (unsigned int)(*(_DWORD *)(Size + 60) - 23) >= 6)
    || (*(_DWORD *)(Size + 56) & 0x20) != 0 )
  {
    LOBYTE(name) = (prop.This.Flags & 0x1F) != 0
                && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
                && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0);
    if ( (prop.This.Flags & 0x1F) > 9 )
    {
      if ( (prop.This.Flags & 0x200) != 0 )
      {
        v31 = prop.This.Bonus.pWeakProxy;
        --prop.This.Bonus.pWeakProxy->RefCount;
        if ( !v31->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v31);
        memset(&prop.This.Bonus, 0, 12);
        prop.This.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&prop.This);
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.Stats )
    {
      p_NativePopCallstack = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.Stats->NativePopCallstack;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.StartTicks) >> 32);
    }
    return (char)name;
  }
  else
  {
    v14 = v12[2].pData;
    v15 = (*((_WORD *)v14 + 31) & 0x200) != 0 ? v14 : 0;
    if ( v15
      && (v16 = *((*((_WORD *)v14 + 31) & 0x200) != 0 ? (unsigned __int8 *)(v14 + 65) : (unsigned __int8 *)65),
          (v17 = (*(int (__thiscall **)(const char *))(*(_DWORD *)&v15[4 * v16] + 20))(&v15[4 * v16])) != 0) )
    {
      v18 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v17 - 36);
    }
    else
    {
      v18 = 0;
    }
    pdata = Scaleform::GFx::ASStringManager::CreateStringNode(
              (Scaleform::GFx::ASStringManager *)pObject[21].pASSupport.pObject,
              name);
    ++pdata->RefCount;
    v19 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(
            v18,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)&name,
            (Scaleform::GFx::ASString *)&pdata)->pObject;
    if ( name )
    {
      if ( ((unsigned __int8)name & 1) == 0 )
      {
        v20 = name[1].m128i_i32[0];
        v21 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)name;
        if ( (v20 & 0x3FFFFF) != 0 )
        {
          name[1].m128i_i32[0] = v20 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
        }
      }
    }
    if ( v19 )
    {
      v22 = pdata;
      --pdata->RefCount;
      if ( !v22->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v22);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
      v23 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.Stats;
      if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.Stats )
      {
        v24 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.Stats->NativePopCallstack;
        v25 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v24)(
          v23,
          v25 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.StartTicks),
          (v25 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.StartTicks) >> 32);
      }
      return 1;
    }
    else
    {
      if ( vm->HandleException )
        vm->HandleException = 0;
      v27 = pdata;
      --pdata->RefCount;
      if ( !v27->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
      v28 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.Stats;
      if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.Stats )
      {
        v29 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.Stats->NativePopCallstack;
        v30 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v29)(
          v28,
          v30 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.StartTicks),
          (v30 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_HasMember.StartTicks) >> 32);
      }
      return 0;
    }
  }
}
