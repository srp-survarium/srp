Scaleform::GFx::AS2::RefCountBaseGC<323> *__cdecl Scaleform::GFx::AS2::StyleSheetCtorFunction::Register(
        Scaleform::GFx::AS2::RefCountBaseGC<323> *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::StyleSheetCtorFunction *v4; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *v5; // eax
  Scaleform::GFx::AS2::StyleSheetProto *v7; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::GlobalContext *v9; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // ecx
  Scaleform::GFx::AS2::Object *v12; // eax
  Scaleform::GFx::AS2::FunctionObject *RefCount; // esi
  $9B9E8CCB0B08DB90B6C18BC91DACC9F3 *v14; // eax
  Scaleform::GFx::AS2::LocalFrame *RootIndex; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *v16; // eax
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // eax
  unsigned __int8 Flags; // bl
  unsigned int v19; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v21; // eax
  unsigned int v22; // eax
  Scaleform::GFx::ASStringNode v24; // [esp-4h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS2::ASStringContext psc; // [esp+14h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::FunctionRefBase v26; // [esp+1Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v27; // [esp+28h] [ebp-10h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v28; // [esp+3Ch] [ebp+4h]

  v2 = pgc;
  pHeap = pgc->pHeap;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  v4 = (Scaleform::GFx::AS2::StyleSheetCtorFunction *)pHeap->Alloc(pHeap, 56u, 0);
  if ( v4 )
    Scaleform::GFx::AS2::StyleSheetCtorFunction::StyleSheetCtorFunction(v4, &psc);
  else
    v5 = 0;
  result->__vftable = v5;
  LOBYTE(result->RootIndex) = 0;
  result->pRCC = 0;
  v7 = (Scaleform::GFx::AS2::StyleSheetProto *)v2->pHeap->Alloc(v2->pHeap, 108u, 0);
  if ( v7 )
  {
    v24.pData = (const char *)result;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::StyleSheetProto::StyleSheetProto(v7, 0, &psc, Prototype, v24);
    v28 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9;
    if ( v9 )
      v9->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)(((int)&v9->RegisteredClasses.mHash.pTable->EntryCount + 1) & 0x8FFFFFFF);
  }
  else
  {
    v28 = 0;
    v9 = 0;
  }
  pgc = v9;
  v24.Size = 33;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &v2->Prototypes,
    (const Scaleform::GFx::AS2::ASBuiltinType *)&v24.Size,
    (const Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&pgc);
  if ( pgc )
  {
    pTable = pgc->RegisteredClasses.mHash.pTable;
    if ( ((unsigned int)pTable & 0x3FFFFFF) != 0 )
    {
      v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pgc;
      pgc->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)pTable - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
    }
  }
  v12 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_TextField);
  RefCount = (Scaleform::GFx::AS2::FunctionObject *)v12[1].RefCount;
  v14 = &v12[1].8;
  v26.Flags = 0;
  v26.Function = RefCount;
  if ( RefCount )
    RefCount->RefCount = (RefCount->RefCount + 1) & 0x8FFFFFFF;
  RootIndex = (Scaleform::GFx::AS2::LocalFrame *)v14[2].RootIndex;
  v26.pLocalFrame = 0;
  if ( RootIndex )
  {
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v26, RootIndex, v14[3].RootIndex & 1);
    RefCount = v26.Function;
  }
  v16 = result->__vftable;
  LOBYTE(pgc) = 0;
  v27.T.Type = 8;
  v27.V.FunctionValue.Flags = 0;
  v27.NV.Int32Value = (int)v16;
  if ( v16 )
  {
    ++v16[1].ExecuteForEachChild_GC;
    v16[1].ExecuteForEachChild_GC = (void (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC))((int)v16[1].ExecuteForEachChild_GC & 0x8FFFFFFF);
  }
  pRCC = result->pRCC;
  v27.V.FunctionValue.pLocalFrame = 0;
  if ( pRCC )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      &v27.V.FunctionValue,
      (Scaleform::GFx::AS2::LocalFrame *)pRCC,
      result->RootIndex & 1);
  RefCount->SetMemberRaw(
    &RefCount->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (const Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[14].AVMVersion,
    &v27,
    (const Scaleform::GFx::AS2::PropFlags *)&pgc);
  if ( v27.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v27);
  Flags = v26.Flags;
  if ( (v26.Flags & 2) == 0 )
  {
    if ( RefCount )
    {
      v19 = RefCount->RefCount;
      if ( (v19 & 0x3FFFFFF) != 0 )
      {
        RefCount->RefCount = v19 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(RefCount);
      }
    }
  }
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = v26.pLocalFrame;
    if ( v26.pLocalFrame )
    {
      v21 = v26.pLocalFrame->RefCount;
      if ( (v21 & 0x3FFFFFF) != 0 )
      {
        v26.pLocalFrame->RefCount = v21 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  if ( v28 )
  {
    v22 = v28->RefCount;
    if ( (v22 & 0x3FFFFFF) != 0 )
    {
      v28->RefCount = v22 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v28);
    }
  }
  return result;
}
