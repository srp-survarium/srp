void __thiscall Scaleform::GFx::AS2::GlobalContext::PreClean(
        Scaleform::GFx::AS2::GlobalContext *this,
        bool preserveBuiltinProps)
{
  Scaleform::GFx::AS2::GASGlobalObject *v3; // eax
  Scaleform::GFx::AS2::Object *v4; // eax
  Scaleform::GFx::AS2::Object *v5; // ebp
  Scaleform::GFx::AS2::ObjectInterface *v6; // ecx
  bool (__thiscall *SetMemberRaw)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v8; // eax
  bool (__thiscall *v9)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // eax
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int RefCount; // eax
  bool v12; // cf
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  unsigned int v16; // eax
  Scaleform::GFx::AS2::Object *v17; // ecx
  unsigned int v18; // eax
  Scaleform::GFx::ASStringNode *v19; // [esp+5Ch] [ebp-24h] BYREF
  Scaleform::GFx::ASStringNode *v20; // [esp+60h] [ebp-20h] BYREF
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+64h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::GlobalContext *v22; // [esp+68h] [ebp-18h] BYREF
  char v23; // [esp+6Ch] [ebp-14h]
  Scaleform::GFx::AS2::Value v24; // [esp+70h] [ebp-10h] BYREF

  if ( preserveBuiltinProps )
  {
    v3 = (Scaleform::GFx::AS2::GASGlobalObject *)this->pHeap->Alloc(this->pHeap, 56, 0);
    if ( v3 )
    {
      Scaleform::GFx::AS2::GASGlobalObject::GASGlobalObject(v3, this);
      v5 = v4;
    }
    else
    {
      v5 = 0;
    }
    v22 = this;
    v23 = 8;
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        (Scaleform::GFx::ASStringManager *)this->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                        "gfxPlayer",
                        9u,
                        0);
    ++ConstStringNode->RefCount;
    v20 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
            (Scaleform::GFx::ASStringManager *)v22->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            "gfxLanguage",
            0xBu,
            0);
    ++v20->RefCount;
    v19 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
            (Scaleform::GFx::ASStringManager *)v22->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            "gfxArg",
            6u,
            0);
    ++v19->RefCount;
    v6 = &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface;
    v24.T.Type = 0;
    v6->GetMemberRaw(
      v6,
      (Scaleform::GFx::AS2::ASStringContext *)&v22,
      (const Scaleform::GFx::ASString *)&ConstStringNode,
      &v24);
    SetMemberRaw = v5->SetMemberRaw;
    preserveBuiltinProps = 0;
    SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::AS2::ASStringContext *)&v22,
      (const Scaleform::GFx::ASString *)&ConstStringNode,
      &v24,
      (const Scaleform::GFx::AS2::PropFlags *)&preserveBuiltinProps);
    this->pGlobal.pObject->GetMemberRaw(
      &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::AS2::ASStringContext *)&v22,
      (const Scaleform::GFx::ASString *)&v20,
      &v24);
    v8 = v5->Scaleform::GFx::AS2::ObjectInterface::__vftable;
    preserveBuiltinProps = 0;
    v8->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::AS2::ASStringContext *)&v22,
      (const Scaleform::GFx::ASString *)&v20,
      &v24,
      (const Scaleform::GFx::AS2::PropFlags *)&preserveBuiltinProps);
    this->pGlobal.pObject->GetMemberRaw(
      &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::AS2::ASStringContext *)&v22,
      (const Scaleform::GFx::ASString *)&v19,
      &v24);
    v9 = v5->SetMemberRaw;
    preserveBuiltinProps = 0;
    v9(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::AS2::ASStringContext *)&v22,
      (const Scaleform::GFx::ASString *)&v19,
      &v24,
      (const Scaleform::GFx::AS2::PropFlags *)&preserveBuiltinProps);
    v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
    pObject = this->pGlobal.pObject;
    if ( pObject )
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    v12 = v24.T.Type < 5u;
    this->pGlobal.pObject = v5;
    if ( !v12 )
      Scaleform::GFx::AS2::Value::DropRefs(&v24);
    v13 = v19;
    --v19->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v14 = v20;
    --v20->RefCount;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    v15 = ConstStringNode;
    --ConstStringNode->RefCount;
    if ( !v15->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    v16 = v5->RefCount;
    if ( (v16 & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
  else
  {
    v17 = this->pGlobal.pObject;
    if ( v17 )
    {
      v18 = v17->RefCount;
      if ( (v18 & 0x3FFFFFF) != 0 )
      {
        v17->RefCount = v18 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
      }
    }
    this->pGlobal.pObject = 0;
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&this->RegisteredClasses.mHash);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Clear(&this->BuiltinClassesRegistry.mHash);
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>(&this->Prototypes.mHash);
  this->pMovieRoot = 0;
}
