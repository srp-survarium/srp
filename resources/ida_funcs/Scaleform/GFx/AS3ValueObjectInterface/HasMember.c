char __thiscall Scaleform::GFx::AS3ValueObjectInterface::HasMember(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::ASStringNode *pdata,
        char *name,
        bool isdobj)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // edi
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // eax
  Scaleform::GFx::AS3::GASRefCountBase *CheckAvm; // eax
  void *pWeakProxy; // eax
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // esi
  unsigned int Size; // ebp
  const char *v12; // ecx
  const char *v13; // eax
  int v14; // ecx
  int v15; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v16; // esi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v17; // esi
  int v18; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v19; // ecx
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::AS3::WeakProxy *v23; // eax
  Scaleform::GFx::AS3::VM *vm; // [esp+10h] [ebp-48h]
  Scaleform::GFx::AS3::Value::V2U v25; // [esp+14h] [ebp-44h]
  Scaleform::GFx::AS3::Value nameVal; // [esp+18h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+28h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+40h] [ebp-18h] BYREF

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
    nameVal.value.VS._2 = v25;
    nameVal.Flags = 12;
  }
  else
  {
    ++StringNode->RefCount;
  }
  CheckAvm = (Scaleform::GFx::AS3::GASRefCountBase *)pObject[2].__vftable[1].CheckAvm;
  mn.Kind = MN_QName;
  mn.Obj.pObject = CheckAvm;
  if ( CheckAvm )
    CheckAvm->RefCount = (CheckAvm->RefCount + 1) & 0x8FBFFFFF;
  mn.Name.Flags = 0;
  mn.Name.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&mn, &nameVal);
  if ( (nameVal.Flags & 0x1F) > 9 )
  {
    if ( (nameVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = nameVal.Bonus.pWeakProxy;
      v9 = nameVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v9 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&nameVal);
    }
  }
  v9 = StringNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v10 = pdata;
  memset(&prop, 0, 16);
  Scaleform::GFx::AS3::Object::FindProperty(
    (Scaleform::GFx::AS3::Object *)pdata,
    &prop,
    (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&mn,
    FindGet);
  if ( (prop.This.Flags & 0x1F) != 0
    && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
    && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0)
    || (Size = v10->Size, (unsigned int)(*(_DWORD *)(Size + 60) - 23) >= 6)
    || (*(_DWORD *)(Size + 56) & 0x20) != 0 )
  {
    LOBYTE(name) = (prop.This.Flags & 0x1F) != 0
                && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
                && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0);
    if ( (prop.This.Flags & 0x1F) > 9 )
    {
      if ( (prop.This.Flags & 0x200) != 0 )
      {
        v23 = prop.This.Bonus.pWeakProxy;
        --prop.This.Bonus.pWeakProxy->RefCount;
        if ( !v23->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v23);
        memset(&prop.This.Bonus, 0, 12);
        prop.This.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&prop.This);
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    return (char)name;
  }
  else
  {
    v12 = v10[2].pData;
    v13 = (*((_WORD *)v12 + 31) & 0x200) != 0 ? v12 : 0;
    if ( v13
      && (v14 = *((*((_WORD *)v12 + 31) & 0x200) != 0 ? (unsigned __int8 *)(v12 + 65) : (unsigned __int8 *)65),
          (v15 = (*(int (__thiscall **)(const char *))(*(_DWORD *)&v13[4 * v14] + 20))(&v13[4 * v14])) != 0) )
    {
      v16 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v15 - 36);
    }
    else
    {
      v16 = 0;
    }
    pdata = Scaleform::GFx::ASStringManager::CreateStringNode(
              (Scaleform::GFx::ASStringManager *)pObject[21].pASSupport.pObject,
              name);
    ++pdata->RefCount;
    v17 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(
            v16,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)&name,
            (Scaleform::GFx::ASString *)&pdata)->pObject;
    if ( name )
    {
      if ( ((unsigned __int8)name & 1) == 0 )
      {
        v18 = *((_DWORD *)name + 4);
        v19 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)name;
        if ( ((unsigned int)&byte_3FFFFF & v18) != 0 )
        {
          *((_DWORD *)name + 4) = v18 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v19);
        }
      }
    }
    if ( v17 )
    {
      v20 = pdata;
      --pdata->RefCount;
      if ( !v20->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
      return 1;
    }
    else
    {
      if ( vm->HandleException )
        vm->HandleException = 0;
      v22 = pdata;
      --pdata->RefCount;
      if ( !v22->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v22);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
      return 0;
    }
  }
}
