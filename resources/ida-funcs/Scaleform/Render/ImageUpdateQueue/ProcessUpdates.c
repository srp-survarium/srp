void __thiscall Scaleform::Render::ImageUpdateQueue::ProcessUpdates(
        Scaleform::Render::ImageUpdateQueue *this,
        int pmanager)
{
  unsigned int v3; // ebx
  int v4; // ebp
  unsigned int v5; // eax
  unsigned int v6; // edi
  int v7; // eax
  Scaleform::RefCountVImpl *v8; // edi
  unsigned int *v9; // eax

  v3 = 0;
  if ( !this->Queue.Data.Size )
    goto LABEL_20;
  v4 = pmanager;
  do
  {
    v5 = this->Queue.Data.Data[v3];
    if ( (v5 & 1) != 0 )
    {
      v6 = v5 & 0xFFFFFFFE;
      v7 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)(v5 & 0xFFFFFFFE) + 96))(v5 & 0xFFFFFFFE, v4);
      if ( v7 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 72))(v7);
      (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v6 + 8))(v6);
    }
    else
    {
      v8 = (Scaleform::RefCountVImpl *)this->Queue.Data.Data[v3];
      (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)v5 + 4))(v5, v4);
      Scaleform::RefCountImpl::Release(v8);
    }
    ++v3;
  }
  while ( v3 < this->Queue.Data.Size );
  if ( !this->Queue.Data.Size )
  {
LABEL_20:
    if ( !this->Queue.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH<unsigned int,75>,Scaleform::ArrayConstPolicy<4,4,0>>::Reserve(
        &this->Queue.Data,
        this,
        0);
    goto LABEL_17;
  }
  if ( (this->Queue.Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_17:
    this->Queue.Data.Size = 0;
    return;
  }
  if ( this->Queue.Data.Data )
  {
    v9 = (unsigned int *)Scaleform::Memory::pGlobalHeap->Realloc(
                           Scaleform::Memory::pGlobalHeap,
                           this->Queue.Data.Data,
                           16);
  }
  else
  {
    pmanager = 75;
    v9 = (unsigned int *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                           Scaleform::Memory::pGlobalHeap,
                           this,
                           16,
                           &pmanager);
  }
  this->Queue.Data.Size = 0;
  this->Queue.Data.Data = v9;
  this->Queue.Data.Policy.Capacity = 4;
}
