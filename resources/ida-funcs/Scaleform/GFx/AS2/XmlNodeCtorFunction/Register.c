Scaleform::GFx::AS2::FunctionRef *__cdecl Scaleform::GFx::AS2::XmlNodeCtorFunction::Register(
        int result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // edi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::CFunctionObject *v4; // esi
  Scaleform::GFx::AS2::FunctionRef *v5; // ebx
  Scaleform::GFx::AS2::XmlNodeProto *v6; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  int v8; // eax
  int v9; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // ecx
  Scaleform::GFx::AS2::ObjectInterface_vtbl **v12; // ebp
  Scaleform::GFx::AS2::FunctionRef *StringManager; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v14; // ebp
  const Scaleform::GFx::AS2::Value *v15; // eax
  int v16; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl **v18; // [esp+14h] [ebp-1Ch]
  Scaleform::GFx::AS2::ASStringContext sc; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v20; // [esp+20h] [ebp-10h] BYREF

  v2 = pgc;
  pHeap = pgc->pHeap;
  sc.pContext = pgc;
  sc.SWFVersion = 8;
  v4 = (Scaleform::GFx::AS2::CFunctionObject *)pHeap->Alloc(pHeap, 56u, 0);
  if ( v4 )
  {
    Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(v4, &sc, Scaleform::GFx::AS2::XmlNodeCtorFunction::GlobalCtor);
    v4->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::CFunctionObject_vtbl *)&Scaleform::GFx::AS2::XmlNodeCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v4->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::XmlNodeCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  }
  else
  {
    v4 = 0;
  }
  v5 = (Scaleform::GFx::AS2::FunctionRef *)result;
  *(_BYTE *)(result + 8) = 0;
  v5->Function = v4;
  v5->pLocalFrame = 0;
  v6 = (Scaleform::GFx::AS2::XmlNodeProto *)v2->pHeap->Alloc(v2->pHeap, 96u, 0);
  if ( v6 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::XmlNodeProto::XmlNodeProto(v6, (int)v2, (int)v6, &sc, Prototype, v5);
    v9 = v8;
    if ( v8 )
      *(_DWORD *)(v8 + 12) = (*(_DWORD *)(v8 + 12) + 1) & 0x8FFFFFFF;
  }
  else
  {
    v9 = 0;
  }
  pgc = (Scaleform::GFx::AS2::GlobalContext *)v9;
  result = 24;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &v2->Prototypes,
    (const Scaleform::GFx::AS2::ASBuiltinType *)&result,
    (const Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&pgc);
  if ( pgc )
  {
    pTable = pgc->RegisteredClasses.mHash.pTable;
    v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pgc;
    if ( ((unsigned int)pTable & 0x3FFFFFF) != 0 )
    {
      pgc->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)pTable - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
    }
  }
  v12 = &v2->pGlobal.pObject->__vftable;
  v18 = v12;
  LOBYTE(pgc) = 0;
  StringManager = (Scaleform::GFx::AS2::FunctionRef *)Scaleform::GFx::AS2::GlobalContext::GetStringManager(v2);
  v14 = *v12;
  result = (int)StringManager;
  Scaleform::GFx::AS2::Value::Value(&v20, v5);
  v14->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)v18,
    &sc,
    (const Scaleform::GFx::ASString *)(result + 96),
    v15,
    (const Scaleform::GFx::AS2::PropFlags *)&pgc);
  Scaleform::GFx::AS2::Value::~Value(&v20);
  Scaleform::GFx::AS2::XmlNodeObject::InitializeStandardMembers(v2, (Scaleform::GFx::ASStringHash<char> *)(v9 + 92));
  if ( v9 )
  {
    v16 = *(_DWORD *)(v9 + 12);
    if ( (v16 & 0x3FFFFFF) != 0 )
    {
      *(_DWORD *)(v9 + 12) = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9);
    }
  }
  return v5;
}
