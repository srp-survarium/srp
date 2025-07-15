char __thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::ResolveImportThroughFontLib(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        Scaleform::GFx::ImportData *pimport)
{
  int v2; // ebp
  Scaleform::GFx::MovieDefImpl::BindTaskData *v3; // edi
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // ebx
  Scaleform::GFx::ImportData::Symbol *Data; // esi
  Scaleform::GFx::ResourceId *v6; // esi
  Scaleform::GFx::FontData *v7; // eax
  Scaleform::GFx::Resource *v8; // eax
  Scaleform::GFx::Resource *v9; // edi
  Scaleform::GFx::FontResource *v10; // eax
  Scaleform::GFx::Resource *v11; // eax
  Scaleform::GFx::Resource *v12; // ebx
  _RTL_CRITICAL_SECTION *p_cs; // ebp
  unsigned int Size; // esi
  unsigned int v15; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy> *p_Data; // edi
  unsigned int v17; // esi
  unsigned int v18; // eax
  Scaleform::GFx::Resource **p_pObject; // ebx
  unsigned int v20; // ebp
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v21; // eax
  int v23; // [esp+10h] [ebp-14h]
  Scaleform::GFx::ResourceBinding *i; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::ResourceBindData v26; // [esp+1Ch] [ebp-8h] BYREF
  Scaleform::Lock *p_ImportSourceLock; // [esp+28h] [ebp+4h]

  v2 = 0;
  v3 = this;
  v23 = 0;
  if ( pimport->Imports.Data.Size )
  {
    p_ResourceBinding = &this->ResourceBinding;
    for ( i = &this->ResourceBinding; ; p_ResourceBinding = i )
    {
      Data = pimport->Imports.Data.Data;
      v26.pResource.pObject = 0;
      v26.pBinding = p_ResourceBinding;
      v6 = (Scaleform::GFx::ResourceId *)&Data[v2];
      v7 = (Scaleform::GFx::FontData *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 76, 0);
      if ( v7 )
      {
        Scaleform::GFx::FontData::FontData(v7, (char *)((v6->Id & 0xFFFFFFFC) + 8), 0);
        v9 = v8;
      }
      else
      {
        v9 = 0;
      }
      v9[1].pLib = (Scaleform::GFx::ResourceLibBase *)((int)v9[1].pLib | 0x40);
      v10 = (Scaleform::GFx::FontResource *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
      if ( v10 )
      {
        Scaleform::GFx::FontResource::FontResource(v10, v9, p_ResourceBinding);
        v12 = v11;
      }
      else
      {
        v12 = 0;
      }
      if ( v26.pResource.pObject )
        Scaleform::GFx::Resource::Release(v26.pResource.pObject);
      v26.pResource.pObject = v12;
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetResourceBindData(
        this,
        v2 * 12,
        v6[1],
        &v26,
        (const char *)((v6->Id & 0xFFFFFFFC) + 8));
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v9);
      if ( v26.pResource.pObject )
        Scaleform::GFx::Resource::Release(v26.pResource.pObject);
      ++v2;
      if ( ++v23 >= pimport->Imports.Data.Size )
        break;
    }
    v3 = this;
  }
  p_cs = &v3->ImportSourceLock.cs;
  p_ImportSourceLock = &v3->ImportSourceLock;
  EnterCriticalSection(&v3->ImportSourceLock.cs);
  Size = v3->ImportSourceMovies.Data.Size;
  v15 = Size;
  p_Data = &v3->ImportSourceMovies.Data;
  v17 = Size + 1;
  if ( v17 >= v15 )
  {
    if ( v17 >= p_Data->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Data,
        p_Data,
        v17 + (v17 >> 2));
  }
  else
  {
    v18 = v15 - v17;
    p_pObject = &p_Data->Data[v18 - 1 + v17].pObject;
    if ( v18 )
    {
      v20 = v18;
      do
      {
        if ( *p_pObject )
          Scaleform::GFx::Resource::Release(*p_pObject);
        --p_pObject;
        --v20;
      }
      while ( v20 );
      p_cs = &p_ImportSourceLock->cs;
    }
    if ( v17 < p_Data->Policy.Capacity >> 1 )
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Data,
        p_Data,
        v17);
  }
  v21 = &p_Data->Data[v17 - 1];
  p_Data->Size = v17;
  if ( v21 )
    v21->pObject = 0;
  LeaveCriticalSection(p_cs);
  return 1;
}
