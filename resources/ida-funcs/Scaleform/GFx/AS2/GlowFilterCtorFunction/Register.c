Scaleform::GFx::AS2::FunctionRef *__cdecl Scaleform::GFx::AS2::GlowFilterCtorFunction::Register(
        int result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // esi
  char v3; // bl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // ecx
  int v5; // eax
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  int v7; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::GlowFilterCtorFunction *v9; // eax
  Scaleform::GFx::AS2::FunctionObject *v10; // eax
  Scaleform::GFx::AS2::FunctionRef *v11; // edi
  Scaleform::GFx::AS2::GlowFilterProto *v12; // ebp
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::GlobalContext *v14; // eax
  Scaleform::GFx::AS2::GlobalContext *v15; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v17; // ecx
  int Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v20; // eax
  Scaleform::GFx::ASSupport *pObject; // [esp+4h] [ebp-2Ch]
  Scaleform::GFx::AS2::ASStringContext sc; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v24; // [esp+20h] [ebp-10h] BYREF

  v2 = pgc;
  pObject = pgc->pMovieRoot->pASMovieRoot.pObject[15].pASSupport.pObject;
  ++pObject[1].__vftable;
  if ( !Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(v2, (Scaleform::GFx::ASString)pObject) )
  {
    Scaleform::GFx::AS2::BitmapFilterCtorFunction::Register((int)&v24, v2);
    v3 = BYTE4(v24.NV.NumberValue);
    if ( (BYTE4(v24.NV.NumberValue) & 2) == 0 )
    {
      v4 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v24.T.Type;
      if ( *(_DWORD *)&v24.T.Type )
      {
        v5 = *(_DWORD *)(*(_DWORD *)&v24.T.Type + 12);
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v5) != 0 )
        {
          *(_DWORD *)(*(_DWORD *)&v24.T.Type + 12) = v5 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
        }
      }
    }
    if ( (v3 & 1) == 0 )
    {
      pStringNode = v24.V.pStringNode;
      if ( v24.NV.Int32Value )
      {
        v7 = *(_DWORD *)(v24.NV.Int32Value + 12);
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v7) != 0 )
        {
          *(_DWORD *)(v24.NV.Int32Value + 12) = v7 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
        }
      }
    }
  }
  pHeap = v2->pHeap;
  sc.pContext = v2;
  sc.SWFVersion = 8;
  v9 = (Scaleform::GFx::AS2::GlowFilterCtorFunction *)pHeap->Alloc(pHeap, 56u, 0);
  if ( v9 )
    Scaleform::GFx::AS2::GlowFilterCtorFunction::GlowFilterCtorFunction(v9, &sc);
  else
    v10 = 0;
  v11 = (Scaleform::GFx::AS2::FunctionRef *)result;
  *(_DWORD *)result = v10;
  v11->Flags = 0;
  v11->pLocalFrame = 0;
  v12 = (Scaleform::GFx::AS2::GlowFilterProto *)v2->pHeap->Alloc(v2->pHeap, 88u, 0);
  if ( v12 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_BitmapFilter);
    Scaleform::GFx::AS2::GlowFilterProto::GlowFilterProto(v12, 8, &sc, Prototype, v11);
    v15 = v14;
    if ( v14 )
      v14->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)(((int)&v14->RegisteredClasses.mHash.pTable->EntryCount + 1) & 0x8FFFFFFF);
  }
  else
  {
    v15 = 0;
  }
  pgc = v15;
  result = 39;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &v2->Prototypes,
    (const Scaleform::GFx::AS2::ASBuiltinType *)&result,
    (const Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&pgc);
  if ( pgc )
  {
    pTable = pgc->RegisteredClasses.mHash.pTable;
    v17 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pgc;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & (unsigned int)pTable) != 0 )
    {
      pgc->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)pTable - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
    }
  }
  Function = (int)v11->Function;
  LOBYTE(pgc) = 0;
  v24.T.Type = 8;
  v24.V.FunctionValue.Flags = 0;
  v24.NV.Int32Value = Function;
  if ( Function )
  {
    ++*(_DWORD *)(Function + 12);
    *(_DWORD *)(Function + 12) &= 0x8FFFFFFF;
  }
  pLocalFrame = v11->pLocalFrame;
  v24.V.FunctionValue.pLocalFrame = 0;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v24.V.FunctionValue, pLocalFrame, v11->Flags & 1);
  v2->FlashFiltersPackage->SetMemberRaw(
    &v2->FlashFiltersPackage->Scaleform::GFx::AS2::ObjectInterface,
    &sc,
    (const Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[16],
    &v24,
    (const Scaleform::GFx::AS2::PropFlags *)&pgc);
  if ( v24.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v24);
  if ( v15 )
  {
    v20 = v15->RegisteredClasses.mHash.pTable;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & (unsigned int)v20) != 0 )
    {
      v15->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)v20 - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v15);
    }
  }
  return v11;
}
