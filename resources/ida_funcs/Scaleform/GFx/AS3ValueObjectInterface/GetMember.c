char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetMember(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::AS3::RefCountBaseGC<328> *pdata,
        char *name,
        Scaleform::GFx::Value *pval,
        bool isdobj)
{
  char *v5; // ebp
  Scaleform::GFx::AS3::MovieRoot *pObject; // edi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v8; // esi
  Scaleform::GFx::ASStringManager *pManager; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v10; // eax
  void *pWeakProxy; // eax
  bool v12; // zf
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // esi
  void (__thiscall *v14)(Scaleform::GFx::AS3::RefCountBaseGC<328> *); // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *v15; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pNext; // ecx
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v20; // esi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v21; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v23; // ecx
  unsigned int v24; // eax
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::Value *v26; // esi
  Scaleform::GFx::ASStringNode *v27; // ecx
  const char *v28; // eax
  Scaleform::GFx::Value *v30; // esi
  Scaleform::GFx::AS3::VM *vm; // [esp+10h] [ebp-40h]
  Scaleform::GFx::AS3::Value::V2U v32; // [esp+14h] [ebp-3Ch]
  Scaleform::GFx::AS3::Value nameVal; // [esp+18h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value asval; // [esp+28h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+38h] [ebp-18h] BYREF

  v5 = name;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  vm = pObject->pAVM.pObject;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(pObject->BuiltinsMgr.pStringManager, name);
  v8 = StringNode;
  pManager = StringNode->pManager;
  ++StringNode->RefCount;
  nameVal.Flags = 10;
  nameVal.Bonus.pWeakProxy = 0;
  nameVal.value.VS._1.VInt = (int)StringNode;
  if ( StringNode == &pManager->NullStringNode )
  {
    nameVal.value.VS._1.VInt = 0;
    nameVal.value.VS._2 = v32;
    nameVal.Flags = 12;
  }
  else
  {
    ++StringNode->RefCount;
  }
  v10 = vm->PublicNamespace.pObject;
  mn.Kind = MN_QName;
  mn.Obj.pObject = v10;
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
  mn.Name.Flags = 0;
  mn.Name.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&mn, &nameVal);
  if ( (nameVal.Flags & 0x1F) > 9 )
  {
    if ( (nameVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = nameVal.Bonus.pWeakProxy;
      v12 = nameVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&nameVal);
    }
  }
  v12 = v8->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v13 = pdata;
  v14 = pdata->__vftable[1].~Scaleform::GFx::AS3::RefCountBaseGC<328>;
  asval.Flags = 0;
  asval.Bonus.pWeakProxy = 0;
  if ( !*(_BYTE *)((int (__thiscall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, char **, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v14)(
                    pdata,
                    &name,
                    &mn,
                    &asval) )
  {
    v15 = v13[1].__vftable;
    if ( (unsigned int)v15[5].ForEachChild_GC - 23 >= 6 || ((int)v15[4].Finalize_GC & 0x20) != 0 )
    {
      if ( vm->HandleException )
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(vm);
      v30 = pval;
      if ( (pval->Type & 0x40) != 0 )
      {
        ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(
          pval,
          pval->mValue.IValue);
        v30->pObjectInterface = 0;
      }
      v30->Type = VT_Undefined;
    }
    else
    {
      pNext = v13[2].pNext;
      v17 = (HIWORD(pNext[3].__vftable) & 0x200) != 0 ? (unsigned int)pNext : 0;
      if ( v17
        && (v18 = *((HIWORD(pNext[3].__vftable) & 0x200) != 0
                  ? (unsigned __int8 *)&pNext[3]._pRCC + 1
                  : (unsigned __int8 *)65),
            (v19 = (*(int (__thiscall **)(int))(*(_DWORD *)(v17 + 4 * v18) + 20))(v17 + 4 * v18)) != 0) )
      {
        v20 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v19 - 36);
      }
      else
      {
        v20 = 0;
      }
      name = (char *)Scaleform::GFx::ASStringManager::CreateStringNode(pObject->BuiltinsMgr.pStringManager, v5);
      ++*((_DWORD *)name + 3);
      v21 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(
              v20,
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
          v23 = pdata;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            pdata->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
          }
        }
      }
      if ( v21 )
      {
        v24 = (v21->RefCount + 1) & 0x8FBFFFFF;
        nameVal.Flags = 12;
        nameVal.Bonus.pWeakProxy = 0;
        nameVal.value.VS._1.VInt = (int)v21;
        v21->RefCount = v24;
        Scaleform::GFx::AS3::Value::Assign(&asval, &nameVal);
        Scaleform::GFx::AS3::Value::~Value(&nameVal);
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &asval, (Scaleform::GFx::ASStringNode *)pval);
        v25 = (Scaleform::GFx::ASStringNode *)name;
        --*((_DWORD *)name + 3);
        if ( !v25->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
        goto LABEL_41;
      }
      if ( vm->HandleException )
        vm->HandleException = 0;
      v26 = pval;
      if ( (pval->Type & 0x40) != 0 )
      {
        ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(
          pval,
          pval->mValue.IValue);
        v26->pObjectInterface = 0;
      }
      v27 = (Scaleform::GFx::ASStringNode *)name;
      v28 = name + 12;
      v26->Type = VT_Undefined;
      if ( !--*(_DWORD *)v28 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
    }
    Scaleform::GFx::AS3::Value::~Value(&asval);
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    return 0;
  }
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &asval, (Scaleform::GFx::ASStringNode *)pval);
LABEL_41:
  Scaleform::GFx::AS3::Value::~Value(&asval);
  Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  return 1;
}
