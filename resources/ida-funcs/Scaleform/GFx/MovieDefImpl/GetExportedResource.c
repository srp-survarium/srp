bool __thiscall Scaleform::GFx::MovieDefImpl::GetExportedResource(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::ResourceBindData *pdata,
        const Scaleform::String *symbol,
        Scaleform::GFx::MovieDefImpl *ignoreDef)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // eax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // esi
  bool v7; // cc
  Scaleform::GFx::MovieDataDef::LoadTaskData *v8; // eax
  const Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor> *v9; // eax
  char v10; // bl
  Scaleform::GFx::Resource *pResource; // ebp
  Scaleform::GFx::Resource *Resource; // eax
  Scaleform::GFx::Resource *v13; // edi
  bool v14; // bl
  unsigned int Size; // ebx
  Scaleform::Lock *p_ImportSourceLock; // esi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v18; // ecx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v19; // eax
  const Scaleform::String *v20; // ecx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *Data; // eax
  Scaleform::GFx::MovieDefImpl *v22; // esi
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v23; // ebp
  int v24; // esi
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v25; // ebp
  Scaleform::GFx::MovieDefImpl *v26; // ecx
  Scaleform::GFx::Resource **p_pObject; // esi
  Scaleform::GFx::Resource **i; // esi
  Scaleform::String::NoCaseKey key; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::Lock *v30; // [esp+14h] [ebp-18h]
  Scaleform::GFx::ResourceHandle v31; // [esp+18h] [ebp-14h] BYREF
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+20h] [ebp-Ch] BYREF

  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v6 = 0;
  v7 = pObject->LoadState < LS_LoadFinished;
  v31.HType = RH_Pointer;
  v31.BindIndex = 0;
  if ( v7 )
  {
    v6 = pObject;
    EnterCriticalSection(&pObject->ResourceLock.cs);
  }
  v8 = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  key.pStr = symbol;
  v9 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetAlt<Scaleform::String::NoCaseKey>(
         &v8->Exports.mHash,
         &key);
  if ( v9 )
  {
    Scaleform::GFx::ResourceHandle::operator=(&v31, &v9->Second);
    v10 = 1;
  }
  else
  {
    v10 = 0;
  }
  if ( v6 )
    LeaveCriticalSection(&v6->ResourceLock.cs);
  if ( v10 )
  {
    if ( v31.HType == RH_Index )
    {
      pResource = v31.pResource;
      Scaleform::GFx::ResourceBinding::GetResourceData(&this->pBindData.pObject->ResourceBinding, pdata, v31.BindIndex);
    }
    else
    {
      pdata->pBinding = &this->pBindData.pObject->ResourceBinding;
      Resource = Scaleform::GFx::ResourceHandle::GetResource(&v31, &this->pBindData.pObject->ResourceBinding);
      v13 = Resource;
      if ( Resource )
        Scaleform::RefCountImpl::AddRef(Resource);
      if ( pdata->pResource.pObject )
        Scaleform::GFx::Resource::Release(pdata->pResource.pObject);
      pResource = v31.pResource;
      pdata->pResource.pObject = v13;
    }
    v14 = pdata->pResource.pObject != 0;
    if ( v31.HType == RH_Pointer )
    {
      if ( pResource )
        Scaleform::GFx::Resource::Release(pResource);
    }
    return v14;
  }
  else
  {
    Size = 0;
    p_ImportSourceLock = &this->pBindData.pObject->ImportSourceLock;
    memset(&pheapAddr, 0, sizeof(pheapAddr));
    v30 = p_ImportSourceLock;
    EnterCriticalSection(&p_ImportSourceLock->cs);
    v18 = this->pBindData.pObject;
    if ( v18->ImportSourceMovies.Data.Size )
    {
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        v18->ImportSourceMovies.Data.Size);
      Size = pheapAddr.Size;
    }
    v19 = this->pBindData.pObject;
    v20 = 0;
    key.pStr = 0;
    if ( v19->ImportSourceMovies.Data.Size )
    {
      do
      {
        Data = v19->ImportSourceMovies.Data.Data;
        v22 = Data[(_DWORD)v20].pObject;
        if ( v22 != ignoreDef )
        {
          if ( v22 )
            Scaleform::RefCountImpl::AddRef(Data[(_DWORD)v20].pObject);
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &pheapAddr,
            &pheapAddr,
            Size + 1);
          Size = pheapAddr.Size;
          v23 = &pheapAddr.Data[pheapAddr.Size - 1];
          if ( &pheapAddr.Data[pheapAddr.Size] != (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)4 )
          {
            if ( v22 )
              Scaleform::RefCountImpl::AddRef(v22);
            v23->pObject = v22;
          }
          if ( v22 )
            Scaleform::GFx::Resource::Release(v22);
        }
        v19 = this->pBindData.pObject;
        v20 = (const Scaleform::String *)((char *)&key.pStr->pData + 1);
        key.pStr = v20;
      }
      while ( (unsigned int)v20 < v19->ImportSourceMovies.Data.Size );
      p_ImportSourceLock = v30;
    }
    LeaveCriticalSection(&p_ImportSourceLock->cs);
    v24 = 0;
    if ( Size )
    {
      while ( 1 )
      {
        v25 = pheapAddr.Data;
        v26 = pheapAddr.Data[v24].pObject;
        if ( v26 )
        {
          if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(v26, pdata, symbol, 0) )
            break;
        }
        if ( ++v24 >= Size )
          goto LABEL_50;
      }
      p_pObject = &v25[Size - 1].pObject;
      do
      {
        if ( *p_pObject )
          Scaleform::GFx::Resource::Release(*p_pObject);
        --p_pObject;
        --Size;
      }
      while ( Size );
      if ( v25 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v25);
      if ( v31.HType == RH_Pointer && v31.BindIndex )
        Scaleform::GFx::Resource::Release(v31.pResource);
      return 1;
    }
    else
    {
      v25 = pheapAddr.Data;
LABEL_50:
      for ( i = &v25[Size - 1].pObject; Size; --Size )
      {
        if ( *i )
          Scaleform::GFx::Resource::Release(*i);
        --i;
      }
      if ( v25 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v25);
      if ( v31.HType == RH_Pointer && v31.BindIndex )
        Scaleform::GFx::Resource::Release(v31.pResource);
      return 0;
    }
  }
}
