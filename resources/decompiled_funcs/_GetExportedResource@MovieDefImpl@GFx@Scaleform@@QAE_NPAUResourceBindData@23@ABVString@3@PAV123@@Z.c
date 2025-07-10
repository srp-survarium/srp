char __thiscall Scaleform::GFx::MovieDefImpl::GetExportedResource(
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
  unsigned int v20; // ecx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *Data; // eax
  Scaleform::GFx::MovieDefImpl *v22; // esi
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v23; // ebp
  int v24; // esi
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v25; // ebp
  Scaleform::GFx::MovieDefImpl *v26; // ecx
  Scaleform::GFx::Resource **p_pObject; // esi
  Scaleform::GFx::Resource **j; // esi
  unsigned int i; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::Lock::Locker loc; // [esp+14h] [ebp-18h]
  Scaleform::GFx::ResourceHandle hres; // [esp+18h] [ebp-14h] BYREF
  Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265,Scaleform::ArrayDefaultPolicy> importsCopy; // [esp+20h] [ebp-Ch] BYREF

  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v6 = 0;
  v7 = pObject->LoadState < LS_LoadFinished;
  hres.HType = RH_Pointer;
  hres.BindIndex = 0;
  if ( v7 )
  {
    v6 = pObject;
    EnterCriticalSection(&pObject->ResourceLock.cs);
  }
  v8 = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  i = (unsigned int)symbol;
  v9 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetAlt<Scaleform::String::NoCaseKey>(
         &v8->Exports.mHash,
         (const Scaleform::String::NoCaseKey *)&i);
  if ( v9 )
  {
    Scaleform::GFx::ResourceHandle::operator=(&hres, &v9->Second);
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
    if ( hres.HType == RH_Index )
    {
      pResource = hres.pResource;
      Scaleform::GFx::ResourceBinding::GetResourceData(&this->pBindData.pObject->ResourceBinding, pdata, hres.BindIndex);
    }
    else
    {
      pdata->pBinding = &this->pBindData.pObject->ResourceBinding;
      Resource = Scaleform::GFx::ResourceHandle::GetResource(&hres, &this->pBindData.pObject->ResourceBinding);
      v13 = Resource;
      if ( Resource )
        Scaleform::RefCountImpl::AddRef(Resource);
      if ( pdata->pResource.pObject )
        Scaleform::GFx::Resource::Release(pdata->pResource.pObject);
      pResource = hres.pResource;
      pdata->pResource.pObject = v13;
    }
    v14 = pdata->pResource.pObject != 0;
    if ( hres.HType == RH_Pointer )
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
    memset(&importsCopy, 0, sizeof(importsCopy));
    loc.pLock = p_ImportSourceLock;
    EnterCriticalSection(&p_ImportSourceLock->cs);
    v18 = this->pBindData.pObject;
    if ( v18->ImportSourceMovies.Data.Size )
    {
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &importsCopy.Data,
        &importsCopy,
        v18->ImportSourceMovies.Data.Size);
      Size = importsCopy.Data.Size;
    }
    v19 = this->pBindData.pObject;
    v20 = 0;
    i = 0;
    if ( v19->ImportSourceMovies.Data.Size )
    {
      do
      {
        Data = v19->ImportSourceMovies.Data.Data;
        v22 = Data[v20].pObject;
        if ( v22 != ignoreDef )
        {
          if ( v22 )
            Scaleform::RefCountImpl::AddRef(Data[v20].pObject);
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &importsCopy.Data,
            &importsCopy,
            Size + 1);
          Size = importsCopy.Data.Size;
          v23 = &importsCopy.Data.Data[importsCopy.Data.Size - 1];
          if ( &importsCopy.Data.Data[importsCopy.Data.Size] != (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)4 )
          {
            if ( v22 )
              Scaleform::RefCountImpl::AddRef(v22);
            v23->pObject = v22;
          }
          if ( v22 )
            Scaleform::GFx::Resource::Release(v22);
        }
        v19 = this->pBindData.pObject;
        v20 = i + 1;
        i = v20;
      }
      while ( v20 < v19->ImportSourceMovies.Data.Size );
      p_ImportSourceLock = loc.pLock;
    }
    LeaveCriticalSection(&p_ImportSourceLock->cs);
    v24 = 0;
    if ( Size )
    {
      while ( 1 )
      {
        v25 = importsCopy.Data.Data;
        v26 = importsCopy.Data.Data[v24].pObject;
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
      if ( hres.HType == RH_Pointer && hres.BindIndex )
        Scaleform::GFx::Resource::Release(hres.pResource);
      return 1;
    }
    else
    {
      v25 = importsCopy.Data.Data;
LABEL_50:
      for ( j = &v25[Size - 1].pObject; Size; --Size )
      {
        if ( *j )
          Scaleform::GFx::Resource::Release(*j);
        --j;
      }
      if ( v25 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v25);
      if ( hres.HType == RH_Pointer && hres.BindIndex )
        Scaleform::GFx::Resource::Release(hres.pResource);
      return 0;
    }
  }
}
