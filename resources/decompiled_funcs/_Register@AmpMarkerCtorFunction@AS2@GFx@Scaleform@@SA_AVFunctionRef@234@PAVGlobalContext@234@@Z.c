Scaleform::GFx::AS2::FunctionRef *__cdecl Scaleform::GFx::AS2::AmpMarkerCtorFunction::Register(
        int result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::AmpMarkerCtorFunction *v4; // eax
  Scaleform::GFx::AS2::FunctionObject *v5; // eax
  Scaleform::GFx::AS2::FunctionRef *v6; // edi
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AmpMarker,Scaleform::GFx::AS2::Environment> *v7; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // ecx
  int v11; // ebx
  int Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ASStringContext sc; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v17; // [esp+20h] [ebp-10h] BYREF

  v2 = pgc;
  pHeap = pgc->pHeap;
  sc.pContext = pgc;
  sc.SWFVersion = 8;
  v4 = (Scaleform::GFx::AS2::AmpMarkerCtorFunction *)pHeap->Alloc(pHeap, 56u, 0);
  if ( v4 )
    Scaleform::GFx::AS2::AmpMarkerCtorFunction::AmpMarkerCtorFunction(v4, (Scaleform::GFx::AS2::LocalFrame **)v2, &sc);
  else
    v5 = 0;
  v6 = (Scaleform::GFx::AS2::FunctionRef *)result;
  *(_DWORD *)result = v5;
  v6->Flags = 0;
  v6->pLocalFrame = 0;
  v7 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AmpMarker,Scaleform::GFx::AS2::Environment> *)v2->pHeap->Alloc(v2->pHeap, 84u, 0);
  if ( v7 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AmpMarker,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::AmpMarker,Scaleform::GFx::AS2::Environment>(
      v7,
      &sc,
      Prototype,
      v6);
    v7->Scaleform::GFx::AS2::AmpMarker::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AmpMarker,Scaleform::GFx::AS2::Environment>_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v7->Scaleform::GFx::AS2::AmpMarker::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v7->Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
    v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
  }
  else
  {
    v7 = 0;
  }
  pgc = (Scaleform::GFx::AS2::GlobalContext *)v7;
  result = 154;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &v2->Prototypes,
    (const Scaleform::GFx::AS2::ASBuiltinType *)&result,
    (const Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&pgc);
  if ( pgc )
  {
    pTable = pgc->RegisteredClasses.mHash.pTable;
    v10 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pgc;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & (unsigned int)pTable) != 0 )
    {
      pgc->RegisteredClasses.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)pTable - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
    }
  }
  v11 = (int)&v2->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface;
  Function = (int)v6->Function;
  LOBYTE(pgc) = 0;
  v17.T.Type = 8;
  v17.V.FunctionValue.Flags = 0;
  v17.NV.Int32Value = Function;
  if ( Function )
  {
    ++*(_DWORD *)(Function + 12);
    *(_DWORD *)(Function + 12) &= 0x8FFFFFFF;
  }
  pLocalFrame = v6->pLocalFrame;
  v17.V.FunctionValue.pLocalFrame = 0;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v17.V.FunctionValue, pLocalFrame, v6->Flags & 1);
  (*(void (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::GlobalContext **))(*(_DWORD *)v11 + 40))(
    v11,
    &sc,
    v2->pMovieRoot->pASMovieRoot.pObject + 39,
    &v17,
    &pgc);
  if ( v17.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v17);
  if ( v7 )
  {
    RefCount = v7->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v7->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
    }
  }
  return v6;
}
