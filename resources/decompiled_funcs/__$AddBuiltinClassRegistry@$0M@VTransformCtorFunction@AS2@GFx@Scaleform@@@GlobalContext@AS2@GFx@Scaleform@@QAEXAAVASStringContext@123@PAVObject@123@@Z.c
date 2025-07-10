void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<12,Scaleform::GFx::AS2::TransformCtorFunction>(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::AS2::ASStringContext *sc,
        Scaleform::GFx::AS2::Object *pdest)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // ebp
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::GlobalContext::ClassRegEntry> *p_BuiltinClassesRegistry; // esi
  signed int v7; // eax
  int p_SizeMask; // eax
  Scaleform::GFx::ASMovieRootBase *pObject; // eax
  Scaleform::GFx::ASSupport *v10; // edx
  unsigned int RefCount; // eax
  unsigned int v12; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__cdecl *v17)(int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[10].pASSupport,
               pTable->SizeMask & pMovieRoot->pASMovieRoot.pObject[10].pASSupport.pObject[1].RefCount),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::TransformCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[10].pASSupport.pObject;
    *(_DWORD *)&key.T.Type = (char *)pObject + 212;
    RefCount = v10[1].RefCount;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      RefCount);
    if ( v18 )
    {
      v12 = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v12) != 0 )
      {
        v18->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[10].pASSupport.pObject;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[10].pASSupport,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}
