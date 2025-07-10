char __thiscall Scaleform::GFx::AS3ValueObjectInterface::DeleteMember(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        void *pdata,
        char *name,
        bool isdobj)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // eax
  Scaleform::GFx::ASMovieRootBase_vtbl *v5; // edi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v7; // esi
  Scaleform::GFx::ASStringManager *pManager; // edx
  Scaleform::GFx::AS3::GASRefCountBase *CheckAvm; // eax
  void *pWeakProxy; // eax
  bool v11; // zf
  char v12; // bl
  Scaleform::GFx::AS3::Value nameVal; // [esp+Ch] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+1Ch] [ebp-18h] BYREF

  pObject = this->pMovieRoot->pASMovieRoot.pObject;
  v5 = pObject[2].__vftable;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)pObject[21].pASSupport.pObject,
                 name);
  v7 = StringNode;
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
  CheckAvm = (Scaleform::GFx::AS3::GASRefCountBase *)v5[1].CheckAvm;
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
      v11 = nameVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&nameVal);
    }
  }
  v11 = v7->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v12 = *(_BYTE *)(*(int (__thiscall **)(void *, char **, Scaleform::GFx::AS3::Multiname *))(*(_DWORD *)pdata + 24))(
                    pdata,
                    &name,
                    &mn);
  Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  return v12;
}
