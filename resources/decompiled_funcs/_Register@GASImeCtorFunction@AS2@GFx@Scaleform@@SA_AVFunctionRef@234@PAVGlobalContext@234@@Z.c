Scaleform::GFx::AS2::FunctionRef *__usercall Scaleform::GFx::AS2::GASImeCtorFunction::Register@<eax>(
        unsigned __int8 *a1@<ebx>,
        int result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v3; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::GASImeCtorFunction *v5; // eax
  Scaleform::GFx::AS2::FunctionObject *v6; // eax
  Scaleform::GFx::AS2::FunctionRef *v7; // ebp
  Scaleform::GFx::AS2::GASImeProto *v8; // edi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::GlobalContext *v10; // eax
  Scaleform::GFx::AS2::GlobalContext *v11; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::AS2::StringManager *StringManager; // ebx
  int v15; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v16; // eax
  Scaleform::GFx::AS2::ASStringContext sc; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v19; // [esp+20h] [ebp-10h] BYREF

  v3 = pgc;
  pHeap = pgc->pHeap;
  sc.pContext = pgc;
  sc.SWFVersion = 8;
  v5 = (Scaleform::GFx::AS2::GASImeCtorFunction *)pHeap->Alloc(pHeap, 56u, 0);
  if ( v5 )
    Scaleform::GFx::AS2::GASImeCtorFunction::GASImeCtorFunction(v5, a1, (Scaleform::GFx::AS2::LocalFrame **)&sc);
  else
    v6 = 0;
  v7 = (Scaleform::GFx::AS2::FunctionRef *)result;
  *(_DWORD *)result = v6;
  v7->Flags = 0;
  v7->pLocalFrame = 0;
  v8 = (Scaleform::GFx::AS2::GASImeProto *)v3->pHeap->Alloc(v3->pHeap, 84u, 0);
  if ( v8 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v3, ASBuiltin_Object);
    Scaleform::GFx::AS2::GASImeProto::GASImeProto(v8, (int)a1, &sc, Prototype, v7);
    v11 = v10;
    if ( v10 )
      v10->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)(((int)&v10->RegisteredClasses.mHash.pTable->EntryCount + 1) & 0x8FFFFFFF);
  }
  else
  {
    v11 = 0;
  }
  pgc = v11;
  result = 22;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &v3->Prototypes,
    (const Scaleform::GFx::AS2::ASBuiltinType *)&result,
    (const Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&pgc);
  if ( pgc )
  {
    pTable = pgc->RegisteredClasses.mHash.pTable;
    v13 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pgc;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & (unsigned int)pTable) != 0 )
    {
      pgc->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)pTable - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
    }
  }
  LOBYTE(pgc) = 0;
  StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v3);
  result = (int)v3->SystemPackage->__vftable;
  Scaleform::GFx::AS2::Value::Value(&v19, v7);
  (*(void (__thiscall **)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASStringNodeHolder *, int, Scaleform::GFx::AS2::GlobalContext **))(result + 40))(
    &v3->SystemPackage->Scaleform::GFx::AS2::ObjectInterface,
    &sc,
    &StringManager->Builtins[22],
    v15,
    &pgc);
  Scaleform::GFx::AS2::Value::~Value(&v19);
  if ( v11 )
  {
    v16 = v11->RegisteredClasses.mHash.pTable;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & (unsigned int)v16) != 0 )
    {
      v11->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)v16 - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v11);
    }
  }
  return v7;
}
