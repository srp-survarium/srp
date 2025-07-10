void __thiscall Scaleform::GFx::MovieDefImpl::VisitImportedMovies(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::MovieDef::ImportVisitor *visitor)
{
  Scaleform::GFx::ImportData *volatile Value; // ebp
  Scaleform::Lock *p_ImportSourceLock; // esi
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // eax
  unsigned int ImportIndex; // ecx
  Scaleform::GFx::MovieDef *v7; // edi
  unsigned int *p_SourceUrl; // esi
  unsigned int v9; // eax
  signed int v10; // eax
  unsigned int v11; // eax
  signed int v12; // eax
  unsigned int v13; // esi
  unsigned int v14; // eax
  int v15; // [esp+Ah] [ebp-18h] BYREF
  Scaleform::StringHash<bool,Scaleform::AllocatorGH<bool,2> > visited; // [esp+Eh] [ebp-14h] BYREF
  Scaleform::String::NoCaseKey key; // [esp+12h] [ebp-10h] BYREF
  Scaleform::String::NoCaseKey v18; // [esp+16h] [ebp-Ch] BYREF
  Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeRef v19; // [esp+1Ah] [ebp-8h] BYREF

  Value = this->pBindData.pObject->pDataDef.pObject->pData.pObject->BindData.pImports.Value;
  if ( Value )
  {
    visited.mHash.pTable = 0;
    while ( 1 )
    {
      p_ImportSourceLock = &this->pBindData.pObject->ImportSourceLock;
      EnterCriticalSection(&p_ImportSourceLock->cs);
      pObject = this->pBindData.pObject;
      ImportIndex = Value->ImportIndex;
      if ( ImportIndex >= pObject->ImportSourceMovies.Data.Size )
        break;
      v7 = pObject->ImportSourceMovies.Data.Data[ImportIndex].pObject;
      LeaveCriticalSection(&p_ImportSourceLock->cs);
      p_SourceUrl = (unsigned int *)&Value->SourceUrl;
      key.pStr = &Value->SourceUrl;
      if ( !visited.mHash.pTable
        || (v9 = Scaleform::String::BernsteinHashFunctionCIS(
                   (char *)((Value->SourceUrl.HeapTypeBits & 0xFFFFFFFC) + 8),
                   *(_DWORD *)(Value->SourceUrl.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
                   0x1505u),
            v10 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
                    &visited.mHash,
                    &key,
                    v9 & visited.mHash.pTable->SizeMask),
            v10 < 0)
        || !visited.mHash.pTable
        || v10 > (signed int)visited.mHash.pTable->SizeMask )
      {
        if ( v7 )
          visitor->Visit(visitor, this, v7, (const char *)((*p_SourceUrl & 0xFFFFFFFC) + 8));
        HIBYTE(v15) = 1;
        v18.pStr = &Value->SourceUrl;
        if ( visited.mHash.pTable
          && (v11 = Scaleform::String::BernsteinHashFunctionCIS(
                      (char *)((*p_SourceUrl & 0xFFFFFFFC) + 8),
                      *(_DWORD *)(*p_SourceUrl & 0xFFFFFFFC) & 0x7FFFFFFF,
                      0x1505u),
              v12 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
                      &visited.mHash,
                      &v18,
                      v11 & visited.mHash.pTable->SizeMask),
              v12 >= 0)
          && visited.mHash.pTable
          && v12 <= (signed int)visited.mHash.pTable->SizeMask )
        {
          LOBYTE(visited.mHash.pTable[2 * v12 + 2].SizeMask) = HIBYTE(v15);
        }
        else
        {
          v19.pFirst = &Value->SourceUrl;
          v13 = *p_SourceUrl;
          v19.pSecond = (const bool *)&v15 + 3;
          v14 = Scaleform::String::BernsteinHashFunctionCIS(
                  (char *)((v13 & 0xFFFFFFFC) + 8),
                  *(_DWORD *)(v13 & 0xFFFFFFFC) & 0x7FFFFFFF,
                  0x1505u);
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
            &visited.mHash,
            &visited,
            &v19,
            v14);
        }
      }
      Value = Value->pNext.Value;
      if ( !Value )
      {
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>(&visited.mHash);
        return;
      }
    }
    LeaveCriticalSection(&p_ImportSourceLock->cs);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>(&visited.mHash);
  }
}
