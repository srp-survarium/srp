void __userpurge Scaleform::GFx::ResourceBinding::SetBindData(
        Scaleform::GFx::ResourceBinding *this@<ecx>,
        int a2@<ebp>,
        unsigned int index,
        const Scaleform::GFx::ResourceBindData *bd)
{
  Scaleform::Lock *p_ResourceLock; // ebx
  unsigned int v6; // esi
  volatile unsigned int v7; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::ResourceBindData *volatile v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  _DWORD *v12; // ecx
  unsigned int v13; // edx
  Scaleform::GFx::ResourceBindData *volatile pResources; // esi
  int v15; // ebx
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::ResourceBindData *v17; // esi
  Scaleform::GFx::Resource *v18; // ecx
  Scaleform::GFx::ResourceBindData *volatile v19; // ebp
  volatile unsigned int ResourceCount; // ebx
  Scaleform::GFx::ResourceBindData *v21; // esi
  Scaleform::GFx::ResourceBindData *v23; // [esp+Ch] [ebp-Ch]
  int v24; // [esp+10h] [ebp-8h]
  Scaleform::Lock *v25; // [esp+14h] [ebp-4h]

  p_ResourceLock = &this->ResourceLock;
  v25 = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  v6 = (index + 16) & 0xFFFFFFF0;
  if ( v6 > this->ResourceCount )
  {
    v7 = 0;
    pHeap = this->pHeap;
    if ( this->pResources )
    {
      v11 = ((int (__thiscall *)(Scaleform::MemoryHeap *, unsigned int, _DWORD, int))pHeap->Alloc)(pHeap, 8 * v6, 0, a2);
      v24 = v11;
      v12 = (_DWORD *)v11;
      if ( v6 )
      {
        v13 = (index + 16) & 0xFFFFFFF0;
        do
        {
          if ( v12 )
          {
            *v12 = 0;
            v12[1] = 0;
          }
          v12 += 2;
          --v13;
        }
        while ( v13 );
      }
      if ( this->ResourceCount )
      {
        do
        {
          pResources = this->pResources;
          v15 = 8 * v7;
          pObject = pResources[v7].pResource.pObject;
          v17 = &pResources[v7];
          if ( pObject )
          {
            Scaleform::RefCountImpl::AddRef(pObject);
            v11 = v24;
          }
          v18 = *(Scaleform::GFx::Resource **)(v15 + v11);
          if ( v18 )
          {
            Scaleform::GFx::Resource::Release(v18);
            v11 = v24;
          }
          *(_DWORD *)(v15 + v11) = v17->pResource.pObject;
          *(_DWORD *)(v15 + v11 + 4) = v17->pBinding;
          ++v7;
        }
        while ( v7 < this->ResourceCount );
        v6 = (unsigned int)v25;
      }
      v19 = this->pResources;
      if ( this->ResourceCount )
      {
        ResourceCount = this->ResourceCount;
        do
        {
          if ( v19->pResource.pObject )
            Scaleform::GFx::Resource::Release(v19->pResource.pObject);
          ++v19;
          --ResourceCount;
        }
        while ( ResourceCount );
      }
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pResources);
      p_ResourceLock = v25;
      this->pResources = v23;
    }
    else
    {
      this->pResources = (Scaleform::GFx::ResourceBindData *volatile)pHeap->Alloc(pHeap, 8 * v6, 0);
      v9 = this->pResources;
      if ( v6 )
      {
        v10 = (index + 16) & 0xFFFFFFF0;
        do
        {
          if ( v9 )
          {
            v9->pResource.pObject = 0;
            v9->pBinding = 0;
          }
          ++v9;
          --v10;
        }
        while ( v10 );
      }
    }
    this->ResourceCount = v6;
  }
  v21 = &this->pResources[index];
  if ( bd->pResource.pObject )
    Scaleform::RefCountImpl::AddRef(bd->pResource.pObject);
  if ( v21->pResource.pObject )
    Scaleform::GFx::Resource::Release(v21->pResource.pObject);
  *v21 = *bd;
  LeaveCriticalSection(&p_ResourceLock->cs);
}
