void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<2,Scaleform::GFx::AS2::ArrayCtorFunction>(
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
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
               pTable->SizeMask & pMovieRoot->pASMovieRoot.pObject[8].pASSupport.pObject[1].RefCount),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::ArrayCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[8].pASSupport.pObject;
    *(_DWORD *)&key.T.Type = (char *)pObject + 172;
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
    key.NV.Int32Value = (int)v15[8].pASSupport.pObject;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<3,Scaleform::GFx::AS2::StringCtorFunction>(
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
  int v10; // edx
  unsigned int v11; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(Scaleform::GFx::AS2::LocalFrame **@<ebp>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[8].AVMVersion,
               pTable->SizeMask & *(_DWORD *)(*(_DWORD *)&pMovieRoot->pASMovieRoot.pObject[8].AVMVersion + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::StringCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = *(_DWORD *)&pObject[8].AVMVersion;
    *(_DWORD *)&key.T.Type = (char *)pObject + 176;
    v11 = *(_DWORD *)(v10 + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = *(_DWORD *)&v15[8].AVMVersion;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[8].AVMVersion,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<4,Scaleform::GFx::AS2::NumberCtorFunction>(
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
  Scaleform::GFx::ASMovieRootBase_vtbl *v10; // edx
  unsigned int CheckAvm; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, char *@<ebp>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[9],
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[9].CheckAvm),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::NumberCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[9].__vftable;
    *(_DWORD *)&key.T.Type = pObject + 9;
    CheckAvm = (unsigned int)v10->CheckAvm;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      CheckAvm);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[9].__vftable;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[9],
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<5,Scaleform::GFx::AS2::BooleanCtorFunction>(
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
  volatile int RefCount; // edx
  unsigned int v11; // eax
  unsigned int v12; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[9].RefCount,
               pTable->SizeMask & *(_DWORD *)(pMovieRoot->pASMovieRoot.pObject[9].RefCount + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::BooleanCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    RefCount = pObject[9].RefCount;
    *(_DWORD *)&key.T.Type = (char *)pObject + 184;
    v11 = *(_DWORD *)(RefCount + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
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
    key.NV.Int32Value = v15[9].RefCount;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[9].RefCount,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<9,Scaleform::GFx::AS2::ButtonCtorFunction>(
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
  Scaleform::GFx::ASMovieRootBase_vtbl *v10; // edx
  unsigned int CheckAvm; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[10],
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[10].CheckAvm),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::ButtonCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[10].__vftable;
    *(_DWORD *)&key.T.Type = pObject + 10;
    CheckAvm = (unsigned int)v10->CheckAvm;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      CheckAvm);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[10].__vftable;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[10],
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<10,Scaleform::GFx::AS2::TextFieldCtorFunction>(
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
  volatile int RefCount; // edx
  unsigned int v11; // eax
  unsigned int v12; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(Scaleform::GFx::AS2::LocalFrame **@<ebp>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[10].RefCount,
               pTable->SizeMask & *(_DWORD *)(pMovieRoot->pASMovieRoot.pObject[10].RefCount + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::TextFieldCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    RefCount = pObject[10].RefCount;
    *(_DWORD *)&key.T.Type = (char *)pObject + 204;
    v11 = *(_DWORD *)(RefCount + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
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
    key.NV.Int32Value = v15[10].RefCount;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[10].RefCount,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<16,Scaleform::GFx::AS2::ColorTransformCtorFunction>(
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
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int pLoadQueueHead; // eax
  unsigned int RefCount; // edx
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[11].pMovieImpl,
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[11].pMovieImpl->pLoadQueueHead),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::ColorTransformCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    pMovieImpl = pObject[11].pMovieImpl;
    *(_DWORD *)&key.T.Type = (char *)pObject + 228;
    pLoadQueueHead = (unsigned int)pMovieImpl->pLoadQueueHead;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      pLoadQueueHead);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[11].pMovieImpl;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[11].pMovieImpl,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<17,Scaleform::GFx::AS2::CapabilitiesCtorFunction>(
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[11].pASSupport,
               pTable->SizeMask & pMovieRoot->pASMovieRoot.pObject[11].pASSupport.pObject[1].RefCount),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::CapabilitiesCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[11].pASSupport.pObject;
    *(_DWORD *)&key.T.Type = (char *)pObject + 232;
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
    key.NV.Int32Value = (int)v15[11].pASSupport.pObject;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[11].pASSupport,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<18,Scaleform::GFx::AS2::StageCtorFunction>(
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
  int v10; // edx
  unsigned int v11; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(unsigned __int8 *@<ebx>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[11].AVMVersion,
               pTable->SizeMask & *(_DWORD *)(*(_DWORD *)&pMovieRoot->pASMovieRoot.pObject[11].AVMVersion + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::StageCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = *(_DWORD *)&pObject[11].AVMVersion;
    *(_DWORD *)&key.T.Type = (char *)pObject + 236;
    v11 = *(_DWORD *)(v10 + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = *(_DWORD *)&v15[11].AVMVersion;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[11].AVMVersion,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<19,Scaleform::GFx::AS2::AsBroadcasterCtorFunction>(
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
  Scaleform::GFx::ASMovieRootBase_vtbl *v10; // edx
  unsigned int CheckAvm; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, Scaleform::GFx::AS2::LocalFrame **@<ebp>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[12],
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[12].CheckAvm),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::AsBroadcasterCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[12].__vftable;
    *(_DWORD *)&key.T.Type = pObject + 12;
    CheckAvm = (unsigned int)v10->CheckAvm;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      CheckAvm);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[12].__vftable;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[12],
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<20,Scaleform::GFx::AS2::DateCtorFunction>(
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
  volatile int RefCount; // edx
  unsigned int v11; // eax
  unsigned int v12; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, Scaleform::GFx::AS2::LocalFrame **@<ebp>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[12].RefCount,
               pTable->SizeMask & *(_DWORD *)(pMovieRoot->pASMovieRoot.pObject[12].RefCount + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::DateCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    RefCount = pObject[12].RefCount;
    *(_DWORD *)&key.T.Type = (char *)pObject + 244;
    v11 = *(_DWORD *)(RefCount + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
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
    key.NV.Int32Value = v15[12].RefCount;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[12].RefCount,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<21,Scaleform::GFx::AS2::SelectionCtorFunction>(
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
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int pLoadQueueHead; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, Scaleform::GFx::AS2::LocalFrame **@<ebp>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[12].pMovieImpl,
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[12].pMovieImpl->pLoadQueueHead),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::SelectionCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    pMovieImpl = pObject[12].pMovieImpl;
    *(_DWORD *)&key.T.Type = (char *)pObject + 248;
    pLoadQueueHead = (unsigned int)pMovieImpl->pLoadQueueHead;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      pLoadQueueHead);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[12].pMovieImpl;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[12].pMovieImpl,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<22,Scaleform::GFx::AS2::GASImeCtorFunction>(
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
  Scaleform::GFx::AS2::FunctionRef *(__cdecl *v17)(Scaleform::GFx::AS2::FunctionRef *, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[12].pASSupport,
               pTable->SizeMask & pMovieRoot->pASMovieRoot.pObject[12].pASSupport.pObject[1].RefCount),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::GASImeCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[12].pASSupport.pObject;
    *(_DWORD *)&key.T.Type = (char *)pObject + 252;
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
    key.NV.Int32Value = (int)v15[12].pASSupport.pObject;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[12].pASSupport,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<23,Scaleform::GFx::AS2::XmlCtorFunction>(
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
  int v10; // edx
  unsigned int v11; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__cdecl *v17)(Scaleform::GFx::AS2::FunctionRef *, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[12].AVMVersion,
               pTable->SizeMask & *(_DWORD *)(*(_DWORD *)&pMovieRoot->pASMovieRoot.pObject[12].AVMVersion + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::XmlCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = *(_DWORD *)&pObject[12].AVMVersion;
    *(_DWORD *)&key.T.Type = (char *)pObject + 256;
    v11 = *(_DWORD *)(v10 + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = *(_DWORD *)&v15[12].AVMVersion;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[12].AVMVersion,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<24,Scaleform::GFx::AS2::XmlNodeCtorFunction>(
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
  Scaleform::GFx::ASMovieRootBase_vtbl *v10; // edx
  unsigned int CheckAvm; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__cdecl *v17)(Scaleform::GFx::AS2::FunctionRef *, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[13],
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[13].CheckAvm),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::XmlNodeCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[13].__vftable;
    *(_DWORD *)&key.T.Type = pObject + 13;
    CheckAvm = (unsigned int)v10->CheckAvm;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      CheckAvm);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[13].__vftable;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[13],
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<25,Scaleform::GFx::AS2::MathCtorFunction>(
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
  volatile int RefCount; // edx
  unsigned int v11; // eax
  unsigned int v12; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(unsigned __int8 *@<ebx>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[13].RefCount,
               pTable->SizeMask & *(_DWORD *)(pMovieRoot->pASMovieRoot.pObject[13].RefCount + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::MathCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    RefCount = pObject[13].RefCount;
    *(_DWORD *)&key.T.Type = (char *)pObject + 264;
    v11 = *(_DWORD *)(RefCount + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
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
    key.NV.Int32Value = v15[13].RefCount;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[13].RefCount,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<27,Scaleform::GFx::AS2::MouseCtorFunction>(
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
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[13].pASSupport,
               pTable->SizeMask & pMovieRoot->pASMovieRoot.pObject[13].pASSupport.pObject[1].RefCount),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::MouseCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[13].pASSupport.pObject;
    *(_DWORD *)&key.T.Type = (char *)pObject + 272;
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
    key.NV.Int32Value = (int)v15[13].pASSupport.pObject;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[13].pASSupport,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<28,Scaleform::GFx::AS2::ExternalInterfaceCtorFunction>(
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
  int v10; // edx
  unsigned int v11; // eax
  unsigned int RefCount; // edx
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[13].AVMVersion,
               pTable->SizeMask & *(_DWORD *)(*(_DWORD *)&pMovieRoot->pASMovieRoot.pObject[13].AVMVersion + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = *(_DWORD *)&pObject[13].AVMVersion;
    *(_DWORD *)&key.T.Type = (char *)pObject + 276;
    v11 = *(_DWORD *)(v10 + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = *(_DWORD *)&v15[13].AVMVersion;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[13].AVMVersion,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<29,Scaleform::GFx::AS2::MovieClipLoaderCtorFunction>(
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
  Scaleform::GFx::ASMovieRootBase_vtbl *v10; // edx
  unsigned int CheckAvm; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[14],
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[14].CheckAvm),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[14].__vftable;
    *(_DWORD *)&key.T.Type = pObject + 14;
    CheckAvm = (unsigned int)v10->CheckAvm;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      CheckAvm);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[14].__vftable;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[14],
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<30,Scaleform::GFx::AS2::BitmapDataCtorFunction>(
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
  volatile int RefCount; // edx
  unsigned int v11; // eax
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[14].RefCount,
               pTable->SizeMask & *(_DWORD *)(pMovieRoot->pASMovieRoot.pObject[14].RefCount + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::BitmapDataCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    RefCount = pObject[14].RefCount;
    *(_DWORD *)&key.T.Type = (char *)pObject + 284;
    v11 = *(_DWORD *)(RefCount + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
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
    key.NV.Int32Value = v15[14].RefCount;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[14].RefCount,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<31,Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction>(
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
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int pLoadQueueHead; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[14].pMovieImpl,
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[14].pMovieImpl->pLoadQueueHead),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    pMovieImpl = pObject[14].pMovieImpl;
    *(_DWORD *)&key.T.Type = (char *)pObject + 288;
    pLoadQueueHead = (unsigned int)pMovieImpl->pLoadQueueHead;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      pLoadQueueHead);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[14].pMovieImpl;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[14].pMovieImpl,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<32,Scaleform::GFx::AS2::TextFormatCtorFunction>(
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
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[14].pASSupport,
               pTable->SizeMask & pMovieRoot->pASMovieRoot.pObject[14].pASSupport.pObject[1].RefCount),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::TextFormatCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[14].pASSupport.pObject;
    *(_DWORD *)&key.T.Type = (char *)pObject + 292;
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
    key.NV.Int32Value = (int)v15[14].pASSupport.pObject;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[14].pASSupport,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<33,Scaleform::GFx::AS2::StyleSheetCtorFunction>(
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
  int v10; // edx
  unsigned int v11; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__cdecl *v17)(Scaleform::GFx::AS2::FunctionRef *, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[14].AVMVersion,
               pTable->SizeMask & *(_DWORD *)(*(_DWORD *)&pMovieRoot->pASMovieRoot.pObject[14].AVMVersion + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::StyleSheetCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = *(_DWORD *)&pObject[14].AVMVersion;
    *(_DWORD *)&key.T.Type = (char *)pObject + 296;
    v11 = *(_DWORD *)(v10 + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = *(_DWORD *)&v15[14].AVMVersion;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[14].AVMVersion,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<37,Scaleform::GFx::AS2::BitmapFilterCtorFunction>(
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[15].pASSupport,
               pTable->SizeMask & pMovieRoot->pASMovieRoot.pObject[15].pASSupport.pObject[1].RefCount),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::BitmapFilterCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[15].pASSupport.pObject;
    *(_DWORD *)&key.T.Type = (char *)pObject + 312;
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
    key.NV.Int32Value = (int)v15[15].pASSupport.pObject;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[15].pASSupport,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<38,Scaleform::GFx::AS2::DropShadowFilterCtorFunction>(
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
  int v10; // edx
  unsigned int v11; // eax
  unsigned int RefCount; // edx
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[15].AVMVersion,
               pTable->SizeMask & *(_DWORD *)(*(_DWORD *)&pMovieRoot->pASMovieRoot.pObject[15].AVMVersion + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::DropShadowFilterCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = *(_DWORD *)&pObject[15].AVMVersion;
    *(_DWORD *)&key.T.Type = (char *)pObject + 316;
    v11 = *(_DWORD *)(v10 + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = *(_DWORD *)&v15[15].AVMVersion;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[15].AVMVersion,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<39,Scaleform::GFx::AS2::GlowFilterCtorFunction>(
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
  Scaleform::GFx::ASMovieRootBase_vtbl *v10; // edx
  unsigned int CheckAvm; // eax
  unsigned int RefCount; // edx
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[16],
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[16].CheckAvm),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::GlowFilterCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[16].__vftable;
    *(_DWORD *)&key.T.Type = pObject + 16;
    CheckAvm = (unsigned int)v10->CheckAvm;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      CheckAvm);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[16].__vftable;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[16],
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<40,Scaleform::GFx::AS2::BlurFilterCtorFunction>(
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
  volatile int RefCount; // edx
  unsigned int v11; // eax
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[16].RefCount,
               pTable->SizeMask & *(_DWORD *)(pMovieRoot->pASMovieRoot.pObject[16].RefCount + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::BlurFilterCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    RefCount = pObject[16].RefCount;
    *(_DWORD *)&key.T.Type = (char *)pObject + 324;
    v11 = *(_DWORD *)(RefCount + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
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
    key.NV.Int32Value = v15[16].RefCount;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[16].RefCount,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<41,Scaleform::GFx::AS2::BevelFilterCtorFunction>(
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
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int pLoadQueueHead; // eax
  unsigned int RefCount; // edx
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[16].pMovieImpl,
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[16].pMovieImpl->pLoadQueueHead),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::BevelFilterCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    pMovieImpl = pObject[16].pMovieImpl;
    *(_DWORD *)&key.T.Type = (char *)pObject + 328;
    pLoadQueueHead = (unsigned int)pMovieImpl->pLoadQueueHead;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      pLoadQueueHead);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[16].pMovieImpl;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[16].pMovieImpl,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<42,Scaleform::GFx::AS2::ColorMatrixFilterCtorFunction>(
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[16].pASSupport,
               pTable->SizeMask & pMovieRoot->pASMovieRoot.pObject[16].pASSupport.pObject[1].RefCount),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::ColorMatrixFilterCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[16].pASSupport.pObject;
    *(_DWORD *)&key.T.Type = (char *)pObject + 332;
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
    key.NV.Int32Value = (int)v15[16].pASSupport.pObject;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[16].pASSupport,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<43,Scaleform::GFx::AS2::TextSnapshotCtorFunction>(
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
  int v10; // edx
  unsigned int v11; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[16].AVMVersion,
               pTable->SizeMask & *(_DWORD *)(*(_DWORD *)&pMovieRoot->pASMovieRoot.pObject[16].AVMVersion + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::TextSnapshotCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = *(_DWORD *)&pObject[16].AVMVersion;
    *(_DWORD *)&key.T.Type = (char *)pObject + 336;
    v11 = *(_DWORD *)(v10 + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = *(_DWORD *)&v15[16].AVMVersion;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[16].AVMVersion,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<44,Scaleform::GFx::AS2::SharedObjectCtorFunction>(
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
  Scaleform::GFx::ASMovieRootBase_vtbl *v10; // edx
  unsigned int CheckAvm; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, Scaleform::GFx::AS2::LocalFrame **@<ebp>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[17],
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[17].CheckAvm),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::SharedObjectCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[17].__vftable;
    *(_DWORD *)&key.T.Type = pObject + 17;
    CheckAvm = (unsigned int)v10->CheckAvm;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      CheckAvm);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[17].__vftable;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[17],
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<154,Scaleform::GFx::AS2::AmpMarkerCtorFunction>(
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
  Scaleform::GFx::ASMovieRootBase_vtbl *v10; // edx
  unsigned int CheckAvm; // eax
  unsigned int RefCount; // edx
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[39],
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[39].CheckAvm),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::AmpMarkerCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[39].__vftable;
    *(_DWORD *)&key.T.Type = pObject + 39;
    CheckAvm = (unsigned int)v10->CheckAvm;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      CheckAvm);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[39].__vftable;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[39],
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<11,Scaleform::GFx::AS2::ColorCtorFunction>(
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
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int pLoadQueueHead; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  Scaleform::GFx::ASMovieRootBase *v15; // eax
  char v16; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::FunctionRef *(__usercall *v17)@<eax>(int@<ebx>, int, Scaleform::GFx::AS2::GlobalContext *); // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value key; // [esp+1Ch] [ebp-10h] BYREF

  pMovieRoot = this->pMovieRoot;
  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  if ( !pTable
    || (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[10].pMovieImpl,
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[10].pMovieImpl->pLoadQueueHead),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::ColorCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    pMovieImpl = pObject[10].pMovieImpl;
    *(_DWORD *)&key.T.Type = (char *)pObject + 208;
    pLoadQueueHead = (unsigned int)pMovieImpl->pLoadQueueHead;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      pLoadQueueHead);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[10].pMovieImpl;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[10].pMovieImpl,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


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


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<13,Scaleform::GFx::AS2::GASMatrixCtorFunction>(
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
  int v10; // edx
  unsigned int v11; // eax
  unsigned int RefCount; // edx
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[10].AVMVersion,
               pTable->SizeMask & *(_DWORD *)(*(_DWORD *)&pMovieRoot->pASMovieRoot.pObject[10].AVMVersion + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::GASMatrixCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = *(_DWORD *)&pObject[10].AVMVersion;
    *(_DWORD *)&key.T.Type = (char *)pObject + 216;
    v11 = *(_DWORD *)(v10 + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = *(_DWORD *)&v15[10].AVMVersion;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[10].AVMVersion,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<14,Scaleform::GFx::AS2::PointCtorFunction>(
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
  Scaleform::GFx::ASMovieRootBase_vtbl *v10; // edx
  unsigned int CheckAvm; // eax
  unsigned int RefCount; // edx
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[11],
               pTable->SizeMask & (unsigned int)pMovieRoot->pASMovieRoot.pObject[11].CheckAvm),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::PointCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    v10 = pObject[11].__vftable;
    *(_DWORD *)&key.T.Type = pObject + 11;
    CheckAvm = (unsigned int)v10->CheckAvm;
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      CheckAvm);
    if ( v18 )
    {
      RefCount = v18->RefCount;
      v13 = v18;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v18->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v14 = this->pMovieRoot;
    v16 = 0;
    v15 = v14->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.NV.Int32Value = (int)v15[11].__vftable;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[11],
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}


void __thiscall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<15,Scaleform::GFx::AS2::RectangleCtorFunction>(
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
  volatile int RefCount; // edx
  unsigned int v11; // eax
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
               (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[11].RefCount,
               pTable->SizeMask & *(_DWORD *)(pMovieRoot->pASMovieRoot.pObject[11].RefCount + 16)),
        v7 < 0)
    || (p_SizeMask = (int)&pTable[2 * v7 + 1].SizeMask) == 0
    || p_SizeMask == -4 )
  {
    v17 = Scaleform::GFx::AS2::RectangleCtorFunction::Register;
    v18 = 0;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    RefCount = pObject[11].RefCount;
    *(_DWORD *)&key.T.Type = (char *)pObject + 224;
    v11 = *(_DWORD *)(RefCount + 16);
    key.NV.Int32Value = (int)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &p_BuiltinClassesRegistry->mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_BuiltinClassesRegistry,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      v11);
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
    key.NV.Int32Value = v15[11].RefCount;
    ++*(_DWORD *)(key.NV.Int32Value + 12);
    pdest->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[11].RefCount,
      &key,
      (const Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}
