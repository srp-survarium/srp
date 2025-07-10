Scaleform::GFx::AS2::FunctionRef *__usercall Scaleform::GFx::AS2::AsBroadcasterCtorFunction::Register@<eax>(
        int a1@<ebx>,
        Scaleform::GFx::AS2::LocalFrame **a2@<ebp>,
        int result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v4; // edi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::AsBroadcasterCtorFunction *v6; // eax
  Scaleform::GFx::AS2::FunctionObject *v7; // eax
  Scaleform::GFx::AS2::FunctionRef *v8; // esi
  Scaleform::GFx::AS2::AsBroadcasterProto *v9; // ebp
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::GlobalContext *v11; // eax
  Scaleform::GFx::AS2::GlobalContext *v12; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // ecx
  int v15; // ebx
  int Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v18; // eax
  Scaleform::GFx::AS2::ASStringContext sc; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v21; // [esp+20h] [ebp-10h] BYREF

  v4 = pgc;
  pHeap = pgc->pHeap;
  sc.pContext = pgc;
  sc.SWFVersion = 8;
  v6 = (Scaleform::GFx::AS2::AsBroadcasterCtorFunction *)pHeap->Alloc(pHeap, 56u, 0);
  if ( v6 )
    Scaleform::GFx::AS2::AsBroadcasterCtorFunction::AsBroadcasterCtorFunction(v6, a2, &sc);
  else
    v7 = 0;
  v8 = (Scaleform::GFx::AS2::FunctionRef *)result;
  *(_DWORD *)result = v7;
  v8->Flags = 0;
  v8->pLocalFrame = 0;
  v9 = (Scaleform::GFx::AS2::AsBroadcasterProto *)v4->pHeap->Alloc(v4->pHeap, 84u, 0);
  if ( v9 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v4, ASBuiltin_Object);
    Scaleform::GFx::AS2::AsBroadcasterProto::AsBroadcasterProto(v9, a1, &sc, Prototype, v8);
    v12 = v11;
    if ( v11 )
      v11->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)(((int)&v11->RegisteredClasses.mHash.pTable->EntryCount + 1) & 0x8FFFFFFF);
  }
  else
  {
    v12 = 0;
  }
  pgc = v12;
  result = 19;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &v4->Prototypes,
    (const Scaleform::GFx::AS2::ASBuiltinType *)&result,
    (const Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&pgc);
  if ( pgc )
  {
    pTable = pgc->RegisteredClasses.mHash.pTable;
    v14 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pgc;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & (unsigned int)pTable) != 0 )
    {
      pgc->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)pTable - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
    }
  }
  v15 = (int)&v4->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface;
  Function = (int)v8->Function;
  LOBYTE(pgc) = 0;
  v21.T.Type = 8;
  v21.V.FunctionValue.Flags = 0;
  v21.NV.Int32Value = Function;
  if ( Function )
  {
    ++*(_DWORD *)(Function + 12);
    *(_DWORD *)(Function + 12) &= 0x8FFFFFFF;
  }
  pLocalFrame = v8->pLocalFrame;
  v21.V.FunctionValue.pLocalFrame = 0;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v21.V.FunctionValue, pLocalFrame, v8->Flags & 1);
  (*(void (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::GlobalContext **))(*(_DWORD *)v15 + 40))(
    v15,
    &sc,
    v4->pMovieRoot->pASMovieRoot.pObject + 12,
    &v21,
    &pgc);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  if ( v12 )
  {
    v18 = v12->RegisteredClasses.mHash.pTable;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & (unsigned int)v18) != 0 )
    {
      v12->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)v18 - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v12);
    }
  }
  return v8;
}
