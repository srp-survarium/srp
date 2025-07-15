void __thiscall Scaleform::Render::MeshCacheListSet::EvictAll(Scaleform::Render::MeshCacheListSet *this)
{
  unsigned int v2; // ebp
  $91FE2188799D963DDDCE23AE0AD4A8E3 *v3; // esi
  Scaleform::Render::MeshCacheListSet::ListSlot *v4; // ebx
  Scaleform::Render::MeshCacheItem *i; // esi
  Scaleform::Render::Fence *pObject; // eax
  Scaleform::Render::FenceImpl *Data; // eax

  v2 = 0;
  v3 = &this->Slots[0].Root.4;
  do
  {
    if ( v2 != 5 && ($91FE2188799D963DDDCE23AE0AD4A8E3 *)v3->pNext != &v3[-1] )
    {
      do
        this->pCache->Evict(this->pCache, v3->pNext, 0, 0);
      while ( ($91FE2188799D963DDDCE23AE0AD4A8E3 *)v3->pNext != &v3[-1] );
    }
    ++v2;
    v3 += 3;
  }
  while ( v2 < 6 );
  v4 = &this->Slots[5];
  while ( (Scaleform::Render::MeshCacheListSet::ListSlot *)this->Slots[5].Root.pNext != &this->Slots[5] )
  {
    for ( i = this->Slots[5].Root.pNext; i != (Scaleform::Render::MeshCacheItem *)v4; i = this->Slots[5].Root.pNext )
    {
      pObject = i->GPUFence.pObject;
      if ( pObject && pObject->HasData )
      {
        Data = pObject->Data;
        if ( Data )
          Scaleform::Render::FenceImpl::WaitFence(Data, FenceType_Vertex);
      }
      this->pCache->Evict(this->pCache, i, 0, 0);
    }
  }
}
