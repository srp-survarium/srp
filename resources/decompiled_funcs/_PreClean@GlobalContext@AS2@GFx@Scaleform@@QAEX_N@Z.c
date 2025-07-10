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
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  unsigned int v16; // eax
  Scaleform::GFx::AS2::Object *v17; // ecx
  unsigned int v18; // eax
  Scaleform::GFx::ASString gfxArg; // [esp+5Ch] [ebp-24h] BYREF
  Scaleform::GFx::ASString gfxLanguage; // [esp+60h] [ebp-20h] BYREF
  Scaleform::GFx::ASString gfxPlayer; // [esp+64h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::ASStringContext sc; // [esp+68h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+70h] [ebp-10h] BYREF

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
    sc.pContext = this;
    sc.SWFVersion = 8;
    gfxPlayer.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        (Scaleform::GFx::ASStringManager *)this->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                        "gfxPlayer",
                        9u,
                        0);
    ++gfxPlayer.pNode->RefCount;
    gfxLanguage.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          (Scaleform::GFx::ASStringManager *)sc.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                          "gfxLanguage",
                          0xBu,
                          0);
    ++gfxLanguage.pNode->RefCount;
    gfxArg.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                     (Scaleform::GFx::ASStringManager *)sc.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                     "gfxArg",
                     6u,
                     0);
    ++gfxArg.pNode->RefCount;
    v6 = &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface;
    v.T.Type = 0;
    v6->GetMemberRaw(v6, &sc, &gfxPlayer, &v);
    SetMemberRaw = v5->SetMemberRaw;
    preserveBuiltinProps = 0;
    SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &sc,
      &gfxPlayer,
      &v,
      (const Scaleform::GFx::AS2::PropFlags *)&preserveBuiltinProps);
    this->pGlobal.pObject->GetMemberRaw(
      &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
      &sc,
      &gfxLanguage,
      &v);
    v8 = v5->Scaleform::GFx::AS2::ObjectInterface::__vftable;
    preserveBuiltinProps = 0;
    v8->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &sc,
      &gfxLanguage,
      &v,
      (const Scaleform::GFx::AS2::PropFlags *)&preserveBuiltinProps);
    this->pGlobal.pObject->GetMemberRaw(&this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface, &sc, &gfxArg, &v);
    v9 = v5->SetMemberRaw;
    preserveBuiltinProps = 0;
    v9(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &sc,
      &gfxArg,
      &v,
      (const Scaleform::GFx::AS2::PropFlags *)&preserveBuiltinProps);
    v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
    pObject = this->pGlobal.pObject;
    if ( pObject )
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    v12 = v.T.Type < 5u;
    this->pGlobal.pObject = v5;
    if ( !v12 )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    pNode = gfxArg.pNode;
    --gfxArg.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v14 = gfxLanguage.pNode;
    --gfxLanguage.pNode->RefCount;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    v15 = gfxPlayer.pNode;
    --gfxPlayer.pNode->RefCount;
    if ( !v15->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    v16 = v5->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v16) != 0 )
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
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v18) != 0 )
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
