void __thiscall Scaleform::GFx::MovieDefImpl::VisitResources(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::MovieDef::ResourceVisitor *pvisitor,
        unsigned int visitMask)
{
  Scaleform::GFx::MovieDefImpl *v3; // ebx
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::Iterator *v5; // eax
  int Index; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *pTable; // edx
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *v9; // eax
  Scaleform::GFx::Resource *v10; // edi
  volatile bool Frozen; // dl
  volatile unsigned int SizeMask; // eax
  Scaleform::GFx::ResourceBindData *v13; // esi
  Scaleform::GFx::Resource *v14; // ecx
  Scaleform::GFx::Resource *v15; // esi
  int v16; // esi
  bool v17; // zf
  Scaleform::GFx::MovieDataDef::LoadTaskData *v18; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v19; // ecx
  Scaleform::StringHashLH<Scaleform::GFx::ResourceHandle,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_Exports; // esi
  Scaleform::StringHashLH<Scaleform::GFx::ResourceHandle,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v21; // ebp
  unsigned int v22; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v23; // edx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v24; // ecx
  unsigned int v25; // edi
  int v26; // esi
  int v27; // ebx
  int v28; // esi
  unsigned int *v29; // ecx
  unsigned int v30; // ecx
  unsigned int v31; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *v32; // ecx
  Scaleform::Lock *p_ImportSourceLock; // ebp
  unsigned int Size; // esi
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *Data; // ebx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v36; // eax
  unsigned int v37; // ecx
  unsigned int v38; // edi
  int v39; // esi
  Scaleform::GFx::Resource **v40; // ebp
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v41; // edi
  unsigned int i; // edi
  Scaleform::GFx::MovieDefImpl *v43; // ecx
  Scaleform::GFx::Resource **j; // edi
  int v46; // [esp+14h] [ebp-34h]
  Scaleform::GFx::Resource *v47; // [esp+18h] [ebp-30h]
  Scaleform::Lock *v48; // [esp+18h] [ebp-30h]
  Scaleform::GFx::MovieDataDef::LoadTaskData *v49; // [esp+1Ch] [ebp-2Ch]
  unsigned int v50; // [esp+1Ch] [ebp-2Ch]
  Scaleform::GFx::Resource **p_pObject; // [esp+20h] [ebp-28h]
  const Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> > *pHash; // [esp+24h] [ebp-24h]
  int v53; // [esp+28h] [ebp-20h]
  Scaleform::GFx::ResourceBindData pdata; // [esp+2Ch] [ebp-1Ch] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::Iterator result; // [esp+34h] [ebp-14h] BYREF
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+3Ch] [ebp-Ch] BYREF

  v3 = this;
  if ( (visitMask & 0x803F) != 0 )
  {
    pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
    v49 = 0;
    if ( pObject->LoadState < LS_LoadFinished )
    {
      v49 = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
      EnterCriticalSection(&pObject->ResourceLock.cs);
    }
    v5 = Scaleform::Hash<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>,Scaleform::AllocatorLH<int,2>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>>::Begin(
           (Scaleform::Hash<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int>,Scaleform::AllocatorLH<int,2>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> > > *)&v3->pBindData.pObject->pDataDef.pObject->pData.pObject->Resources,
           &result);
    Index = v5->Index;
    pHash = v5->pHash;
    v53 = Index;
    while ( pHash )
    {
      pTable = pHash->pTable;
      if ( !pHash->pTable || Index > (signed int)pTable->SizeMask )
        break;
      p_ResourceBinding = &v3->pBindData.pObject->ResourceBinding;
      v9 = &pTable[2 * Index + 2];
      v46 = 2 * Index;
      if ( v9->EntryCount )
      {
        Frozen = v3->pBindData.pObject->ResourceBinding.Frozen;
        SizeMask = v9->SizeMask;
        pdata.pResource.pObject = 0;
        pdata.pBinding = 0;
        if ( Frozen && SizeMask < p_ResourceBinding->ResourceCount )
        {
          v13 = &p_ResourceBinding->pResources[SizeMask];
          if ( v13->pResource.pObject )
          {
            Scaleform::RefCountImpl::AddRef(v13->pResource.pObject);
            if ( pdata.pResource.pObject )
              Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
          }
          v14 = v13->pResource.pObject;
          pdata = *v13;
        }
        else
        {
          Scaleform::GFx::ResourceBinding::GetResourceData_Locked(p_ResourceBinding, &pdata, SizeMask);
          v14 = pdata.pResource.pObject;
        }
        v15 = v14;
        if ( v14 )
          Scaleform::GFx::Resource::Release(v14);
        v10 = v15;
        v47 = v15;
      }
      else
      {
        v10 = (Scaleform::GFx::Resource *)pTable[2 * Index + 2].SizeMask;
        v47 = v10;
      }
      if ( v10 )
      {
        v16 = (unsigned __int8)v10->GetResourceTypeCode(v10);
        switch ( (unsigned __int16)v10->GetResourceTypeCode(v10) >> 8 )
        {
          case 1:
            if ( v16 == 1 )
            {
              v17 = (visitMask & 2) == 0;
              goto LABEL_30;
            }
            if ( v16 == 2 )
            {
              v17 = (visitMask & 4) == 0;
              goto LABEL_30;
            }
            goto LABEL_49;
          case 2:
            v17 = (visitMask & 1) == 0;
            goto LABEL_30;
          case 4:
            v17 = (visitMask & 0x10) == 0;
            goto LABEL_30;
          case 131:
            v17 = (visitMask & 8) == 0;
            goto LABEL_30;
          case 132:
            v17 = (visitMask & 0x20) == 0;
LABEL_30:
            if ( v17 )
              goto LABEL_49;
            v18 = v3->pBindData.pObject->pDataDef.pObject->pData.pObject;
            v19 = v18->Exports.mHash.pTable;
            p_Exports = &v18->Exports;
            v21 = 0;
            v22 = 0;
            if ( v19 )
            {
              v23 = v19 + 1;
              do
              {
                if ( v23->EntryCount != -2 )
                  break;
                ++v22;
                v23 = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *)((char *)v23 + 20);
              }
              while ( v22 <= v19->SizeMask );
              v21 = p_Exports;
            }
            break;
          default:
            goto LABEL_49;
        }
        while ( v21 )
        {
          v24 = v21->mHash.pTable;
          if ( !v21->mHash.pTable )
            break;
          v25 = v24->SizeMask;
          if ( (int)v22 > (int)v25 )
            break;
          v26 = 5 * v22 + 5;
          v27 = *(&v24->EntryCount + v26);
          v28 = (int)v24 + 4 * v26;
          if ( v27 == pHash->pTable[v46 + 2].EntryCount && *(_DWORD *)(v28 + 4) == pHash->pTable[v46 + 2].SizeMask )
          {
            v30 = (*(&v24[2].EntryCount + 5 * v22) & 0xFFFFFFFC) + 8;
            goto LABEL_48;
          }
          if ( ++v22 <= v25 )
          {
            v29 = &v24[1].EntryCount + 5 * v22;
            do
            {
              if ( *v29 != -2 )
                break;
              ++v22;
              v29 += 5;
            }
            while ( v22 <= v25 );
          }
        }
        v30 = 0;
LABEL_48:
        v3 = this;
        ((void (__thiscall *)(Scaleform::GFx::MovieDef::ResourceVisitor *, Scaleform::GFx::MovieDefImpl *, Scaleform::GFx::Resource *, unsigned int, unsigned int))pvisitor->Visit)(
          pvisitor,
          this,
          v47,
          pHash->pTable[v46 + 1].SizeMask,
          v30);
        Index = v53;
      }
LABEL_49:
      v31 = pHash->pTable->SizeMask;
      if ( Index <= (int)v31 )
      {
        v53 = ++Index;
        if ( Index <= v31 )
        {
          v32 = &pHash->pTable[2 * Index + 1];
          do
          {
            if ( v32->EntryCount != -2 )
              break;
            ++Index;
            v32 += 2;
            v53 = Index;
          }
          while ( Index <= v31 );
        }
      }
    }
    if ( v49 )
      LeaveCriticalSection(&v49->ResourceLock.cs);
  }
  if ( (visitMask & 0x8000) != 0 )
  {
    p_ImportSourceLock = &this->pBindData.pObject->ImportSourceLock;
    Size = 0;
    Data = 0;
    memset(&pheapAddr, 0, sizeof(pheapAddr));
    v48 = p_ImportSourceLock;
    EnterCriticalSection(&p_ImportSourceLock->cs);
    if ( this->pBindData.pObject->ImportSourceMovies.Data.Size )
    {
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        this->pBindData.pObject->ImportSourceMovies.Data.Size);
      Size = pheapAddr.Size;
      Data = pheapAddr.Data;
    }
    v36 = this->pBindData.pObject;
    v37 = 0;
    v50 = 0;
    if ( v36->ImportSourceMovies.Data.Size )
    {
      while ( 1 )
      {
        v38 = Size + 1;
        p_pObject = &v36->ImportSourceMovies.Data.Data[v37].pObject;
        if ( Size + 1 < Size )
          break;
        if ( v38 >= pheapAddr.Policy.Capacity )
        {
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v38 + (v38 >> 2));
LABEL_70:
          Data = pheapAddr.Data;
        }
LABEL_71:
        Size = v38;
        v41 = &Data[v38 - 1];
        pheapAddr.Size = Size;
        if ( v41 )
        {
          if ( *p_pObject )
            Scaleform::RefCountImpl::AddRef(*p_pObject);
          v41->pObject = (Scaleform::GFx::MovieDefImpl *)*p_pObject;
        }
        v36 = this->pBindData.pObject;
        v37 = v50 + 1;
        v50 = v37;
        if ( v37 >= v36->ImportSourceMovies.Data.Size )
        {
          p_ImportSourceLock = v48;
          goto LABEL_77;
        }
      }
      v39 = -1;
      v40 = &Data[v38 - 2].pObject;
      do
      {
        if ( *v40 )
          Scaleform::GFx::Resource::Release(*v40);
        --v40;
        --v39;
      }
      while ( v39 );
      if ( v38 >= pheapAddr.Policy.Capacity >> 1 )
        goto LABEL_71;
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        v38);
      goto LABEL_70;
    }
LABEL_77:
    LeaveCriticalSection(&p_ImportSourceLock->cs);
    for ( i = 0; i < Size; ++i )
    {
      v43 = Data[i].pObject;
      if ( v43 )
        v43->VisitResources(v43, pvisitor, visitMask);
    }
    for ( j = &Data[Size - 1].pObject; Size; --Size )
    {
      if ( *j )
        Scaleform::GFx::Resource::Release(*j);
      --j;
    }
    if ( Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  }
}
