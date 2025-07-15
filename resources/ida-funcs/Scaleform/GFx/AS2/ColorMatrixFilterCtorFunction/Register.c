Scaleform::GFx::AS2::FunctionRef *__cdecl Scaleform::GFx::AS2::ColorMatrixFilterCtorFunction::Register(
        Scaleform::GFx::AS2::ASBuiltinType result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // esi
  char v3; // bl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // ecx
  int v5; // eax
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  int v7; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::ColorMatrixFilterCtorFunction *v9; // eax
  int v10; // eax
  Scaleform::GFx::AS2::ASBuiltinType v11; // edi
  Scaleform::GFx::AS2::ColorMatrixFilterProto *v12; // ebp
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::GlobalContext *v14; // eax
  Scaleform::GFx::AS2::GlobalContext *v15; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v17; // ecx
  int v18; // eax
  Scaleform::GFx::AS2::LocalFrame *v19; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v20; // eax
  Scaleform::GFx::ASStringNode v22; // [esp+4h] [ebp-2Ch] BYREF
  char psc_4; // [esp+1Ch] [ebp-14h]
  Scaleform::GFx::AS2::Value v24; // [esp+20h] [ebp-10h] BYREF

  v2 = pgc;
  v22.pData = (const char *)pgc->pMovieRoot->pASMovieRoot.pObject[15].pASSupport.pObject;
  ++*((_DWORD *)v22.pData + 3);
  if ( !Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(v2, (Scaleform::GFx::ASStringNode *)v22.pData) )
  {
    Scaleform::GFx::AS2::BitmapFilterCtorFunction::Register((Scaleform::GFx::AS2::FunctionRef *)&v24, v2);
    v3 = BYTE4(v24.NV.NumberValue);
    if ( (BYTE4(v24.NV.NumberValue) & 2) == 0 )
    {
      v4 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v24.T.Type;
      if ( *(_DWORD *)&v24.T.Type )
      {
        v5 = *(_DWORD *)(*(_DWORD *)&v24.T.Type + 12);
        if ( (v5 & 0x3FFFFFF) != 0 )
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
        if ( (v7 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(v24.NV.Int32Value + 12) = v7 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
        }
      }
    }
  }
  pHeap = v2->pHeap;
  v22.Size = (unsigned int)v2;
  psc_4 = 8;
  v9 = (Scaleform::GFx::AS2::ColorMatrixFilterCtorFunction *)pHeap->Alloc(pHeap, 56u, 0);
  if ( v9 )
    Scaleform::GFx::AS2::ColorMatrixFilterCtorFunction::ColorMatrixFilterCtorFunction(
      v9,
      (Scaleform::GFx::AS2::ASStringContext *)&v22.Size);
  else
    v10 = 0;
  v11 = result;
  *(_DWORD *)result = v10;
  *(_BYTE *)(v11 + 8) = 0;
  *(_DWORD *)(v11 + 4) = 0;
  v12 = (Scaleform::GFx::AS2::ColorMatrixFilterProto *)v2->pHeap->Alloc(v2->pHeap, 88u, 0);
  if ( v12 )
  {
    v22.pData = (const char *)v11;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_BitmapFilter);
    Scaleform::GFx::AS2::ColorMatrixFilterProto::ColorMatrixFilterProto(
      v12,
      8,
      (Scaleform::GFx::AS2::ASStringContext *)&v22.Size,
      Prototype,
      v22);
    v15 = v14;
    if ( v14 )
      v14->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)(((int)&v14->RegisteredClasses.mHash.pTable->EntryCount + 1) & 0x8FFFFFFF);
  }
  else
  {
    v15 = 0;
  }
  pgc = v15;
  result = ASBuiltin_ColorMatrixFilter;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &v2->Prototypes,
    &result,
    (const Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&pgc);
  if ( pgc )
  {
    pTable = pgc->RegisteredClasses.mHash.pTable;
    v17 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pgc;
    if ( ((unsigned int)pTable & 0x3FFFFFF) != 0 )
    {
      pgc->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)pTable - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
    }
  }
  v18 = *(_DWORD *)v11;
  LOBYTE(pgc) = 0;
  v24.T.Type = 8;
  v24.V.FunctionValue.Flags = 0;
  v24.NV.Int32Value = v18;
  if ( v18 )
  {
    ++*(_DWORD *)(v18 + 12);
    *(_DWORD *)(v18 + 12) &= 0x8FFFFFFF;
  }
  v19 = *(Scaleform::GFx::AS2::LocalFrame **)(v11 + 4);
  v24.V.FunctionValue.pLocalFrame = 0;
  if ( v19 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v24.V.FunctionValue, v19, *(_BYTE *)(v11 + 8) & 1);
  v2->FlashFiltersPackage->SetMemberRaw(
    &v2->FlashFiltersPackage->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::AS2::ASStringContext *)&v22.Size,
    (const Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[16].pASSupport,
    &v24,
    (const Scaleform::GFx::AS2::PropFlags *)&pgc);
  if ( v24.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v24);
  if ( v15 )
  {
    v20 = v15->RegisteredClasses.mHash.pTable;
    if ( ((unsigned int)v20 & 0x3FFFFFF) != 0 )
    {
      v15->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)v20 - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v15);
    }
  }
  return (Scaleform::GFx::AS2::FunctionRef *)v11;
}
