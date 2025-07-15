Scaleform::GFx::AS2::FunctionRef *__cdecl Scaleform::GFx::AS2::StyleSheetCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::StyleSheetCtorFunction *v4; // eax
  Scaleform::GFx::AS2::FunctionObject *v5; // eax
  Scaleform::GFx::AS2::StyleSheetProto *v7; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::GlobalContext *v9; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // ecx
  Scaleform::GFx::AS2::Object *v12; // eax
  Scaleform::GFx::AS2::FunctionObject *RefCount; // esi
  $E651B797BB2DC0EF0FB0BDD51050358F *v14; // eax
  Scaleform::GFx::AS2::LocalFrame *RootIndex; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  unsigned __int8 Flags; // bl
  unsigned int v19; // eax
  Scaleform::GFx::AS2::LocalFrame *v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // eax
  Scaleform::GFx::AS2::ASBuiltinType key; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::ASStringContext sc; // [esp+14h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::FunctionRef textFieldCtor; // [esp+1Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v27; // [esp+28h] [ebp-10h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *resulta; // [esp+3Ch] [ebp+4h]

  v2 = pgc;
  pHeap = pgc->pHeap;
  sc.pContext = pgc;
  sc.SWFVersion = 8;
  v4 = (Scaleform::GFx::AS2::StyleSheetCtorFunction *)pHeap->Alloc(pHeap, 56u, 0);
  if ( v4 )
    Scaleform::GFx::AS2::StyleSheetCtorFunction::StyleSheetCtorFunction(v4, &sc);
  else
    v5 = 0;
  result->Function = v5;
  result->Flags = 0;
  result->pLocalFrame = 0;
  v7 = (Scaleform::GFx::AS2::StyleSheetProto *)v2->pHeap->Alloc(v2->pHeap, 108u, 0);
  if ( v7 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::StyleSheetProto::StyleSheetProto(v7, 0, &sc, Prototype, result);
    resulta = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9;
    if ( v9 )
      v9->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)(((int)&v9->RegisteredClasses.mHash.pTable->EntryCount + 1) & 0x8FFFFFFF);
  }
  else
  {
    resulta = 0;
    v9 = 0;
  }
  pgc = v9;
  key = ASBuiltin_StyleSheet;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &v2->Prototypes,
    &key,
    (const Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&pgc);
  if ( pgc )
  {
    pTable = pgc->RegisteredClasses.mHash.pTable;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & (unsigned int)pTable) != 0 )
    {
      v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pgc;
      pgc->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)pTable - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
    }
  }
  v12 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_TextField);
  RefCount = (Scaleform::GFx::AS2::FunctionObject *)v12[1].RefCount;
  v14 = &v12[1].8;
  textFieldCtor.Flags = 0;
  textFieldCtor.Function = RefCount;
  if ( RefCount )
    RefCount->RefCount = (RefCount->RefCount + 1) & 0x8FFFFFFF;
  RootIndex = (Scaleform::GFx::AS2::LocalFrame *)v14[2].RootIndex;
  textFieldCtor.pLocalFrame = 0;
  if ( RootIndex )
  {
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&textFieldCtor, RootIndex, v14[3].RootIndex & 1);
    RefCount = textFieldCtor.Function;
  }
  Function = result->Function;
  LOBYTE(pgc) = 0;
  v27.T.Type = 8;
  v27.V.FunctionValue.Flags = 0;
  v27.NV.Int32Value = (int)Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  pLocalFrame = result->pLocalFrame;
  v27.V.FunctionValue.pLocalFrame = 0;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v27.V.FunctionValue, pLocalFrame, result->Flags & 1);
  RefCount->SetMemberRaw(
    &RefCount->Scaleform::GFx::AS2::ObjectInterface,
    &sc,
    (const Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[14].AVMVersion,
    &v27,
    (const Scaleform::GFx::AS2::PropFlags *)&pgc);
  if ( v27.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v27);
  Flags = textFieldCtor.Flags;
  if ( (textFieldCtor.Flags & 2) == 0 )
  {
    if ( RefCount )
    {
      v19 = RefCount->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v19) != 0 )
      {
        RefCount->RefCount = v19 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(RefCount);
      }
    }
  }
  if ( (Flags & 1) == 0 )
  {
    v20 = textFieldCtor.pLocalFrame;
    if ( textFieldCtor.pLocalFrame )
    {
      v21 = textFieldCtor.pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v21) != 0 )
      {
        textFieldCtor.pLocalFrame->RefCount = v21 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
      }
    }
  }
  if ( resulta )
  {
    v22 = resulta->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v22) != 0 )
    {
      resulta->RefCount = v22 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(resulta);
    }
  }
  return result;
}
