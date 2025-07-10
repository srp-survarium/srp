Scaleform::GFx::AS2::FunctionRef *__cdecl Scaleform::GFx::AS2::XmlCtorFunction::Register(
        int result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // esi
  int v3; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // ecx
  int v5; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::CFunctionObject *v8; // eax
  Scaleform::GFx::AS2::FunctionObject *v9; // edi
  Scaleform::GFx::AS2::FunctionRef *v10; // ebp
  Scaleform::GFx::AS2::XmlProto *v11; // edi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::GlobalContext *v13; // eax
  Scaleform::GFx::AS2::GlobalContext *v14; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // ecx
  Scaleform::GFx::AS2::ObjectInterface_vtbl **v17; // ebx
  Scaleform::GFx::AS2::FunctionRef *StringManager; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v19; // esi
  const Scaleform::GFx::AS2::Value *v20; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v21; // eax
  Scaleform::GFx::ASStringNode *pNode; // [esp+4h] [ebp-2Ch]
  Scaleform::GFx::AS2::ASStringContext sc; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v25; // [esp+20h] [ebp-10h] BYREF

  v2 = pgc;
  pNode = Scaleform::GFx::AS2::GlobalContext::GetStringManager(pgc)->Builtins[24].pNode;
  ++pNode->RefCount;
  if ( !Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(v2, (Scaleform::GFx::ASString)pNode) )
  {
    Scaleform::GFx::AS2::XmlNodeCtorFunction::Register((Scaleform::GFx::AS2::FunctionRef *)&v25, v2);
    if ( (BYTE4(v25.NV.NumberValue) & 2) == 0 )
    {
      if ( *(_DWORD *)&v25.T.Type )
      {
        v3 = *(_DWORD *)(*(_DWORD *)&v25.T.Type + 12);
        v4 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v25.T.Type;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v3) != 0 )
        {
          *(_DWORD *)(*(_DWORD *)&v25.T.Type + 12) = v3 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
        }
      }
    }
    *(_DWORD *)&v25.T.Type = 0;
    if ( (BYTE4(v25.NV.NumberValue) & 1) == 0 )
    {
      if ( v25.NV.Int32Value )
      {
        v5 = *(_DWORD *)(v25.NV.Int32Value + 12);
        pStringNode = v25.V.pStringNode;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v5) != 0 )
        {
          *(_DWORD *)(v25.NV.Int32Value + 12) = v5 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
        }
      }
    }
  }
  pHeap = v2->pHeap;
  sc.pContext = v2;
  sc.SWFVersion = 8;
  v8 = (Scaleform::GFx::AS2::CFunctionObject *)pHeap->Alloc(pHeap, 56u, 0);
  v9 = v8;
  if ( v8 )
  {
    Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(v8, &sc, Scaleform::GFx::AS2::XmlCtorFunction::GlobalCtor);
    v9->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::FunctionObject_vtbl *)&Scaleform::GFx::AS2::XmlCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v9->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::XmlNodeCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  }
  else
  {
    v9 = 0;
  }
  v10 = (Scaleform::GFx::AS2::FunctionRef *)result;
  *(_BYTE *)(result + 8) = 0;
  v10->Function = v9;
  v10->pLocalFrame = 0;
  v11 = (Scaleform::GFx::AS2::XmlProto *)v2->pHeap->Alloc(v2->pHeap, 112u, 0);
  if ( v11 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_XMLNode);
    Scaleform::GFx::AS2::XmlProto::XmlProto(v11, &sc, Prototype, v10);
    v14 = v13;
    if ( v13 )
      v13->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)(((int)&v13->RegisteredClasses.mHash.pTable->EntryCount + 1) & 0x8FFFFFFF);
  }
  else
  {
    v14 = 0;
  }
  pgc = v14;
  result = 23;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &v2->Prototypes,
    (const Scaleform::GFx::AS2::ASBuiltinType *)&result,
    (const Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&pgc);
  if ( pgc )
  {
    pTable = pgc->RegisteredClasses.mHash.pTable;
    v16 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pgc;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & (unsigned int)pTable) != 0 )
    {
      pgc->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)pTable - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
    }
  }
  v17 = &v2->pGlobal.pObject->__vftable;
  LOBYTE(pgc) = 0;
  StringManager = (Scaleform::GFx::AS2::FunctionRef *)Scaleform::GFx::AS2::GlobalContext::GetStringManager(v2);
  v19 = *v17;
  result = (int)StringManager;
  Scaleform::GFx::AS2::Value::Value(&v25, v10);
  v19->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)v17,
    &sc,
    (const Scaleform::GFx::ASString *)(result + 92),
    v20,
    (const Scaleform::GFx::AS2::PropFlags *)&pgc);
  Scaleform::GFx::AS2::Value::~Value(&v25);
  if ( v14 )
  {
    v21 = v14->RegisteredClasses.mHash.pTable;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & (unsigned int)v21) != 0 )
    {
      v14->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)v21 - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v14);
    }
  }
  return v10;
}
