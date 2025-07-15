void __thiscall Scaleform::Render::TextureManager::UpdateImage(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::Image *pimage)
{
  Scaleform::Mutex *v3; // esi

  v3 = (Scaleform::Mutex *)&this->pRTCommandQueue[9];
  Scaleform::Mutex::DoLock(v3);
  Scaleform::Render::ImageUpdateQueue::Add((Scaleform::Render::ImageUpdateQueue *)&this->pTextureCache, pimage);
  Scaleform::Mutex::Unlock(v3);
}


void __thiscall Scaleform::Render::TextureManager::UpdateImage(
        Scaleform::Render::TextureManager *this,
        Scaleform::GFx::Resource *pupdate)
{
  Scaleform::Mutex *v3; // ebx
  Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH<unsigned int,75>,Scaleform::ArrayConstPolicy<4,4,0> > *p_pTextureCache; // edi
  unsigned int v5; // esi
  Scaleform::GFx::Resource **v6; // eax

  v3 = (Scaleform::Mutex *)&this->pRTCommandQueue[9];
  Scaleform::Mutex::DoLock(v3);
  p_pTextureCache = (Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH<unsigned int,75>,Scaleform::ArrayConstPolicy<4,4,0> > *)&this->pTextureCache;
  v5 = (unsigned int)&this->pLocks.pObject->__vftable + 1;
  if ( v5 >= p_pTextureCache->Size )
  {
    if ( v5 >= p_pTextureCache->Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH<unsigned int,75>,Scaleform::ArrayConstPolicy<4,4,0>>::Reserve(
        p_pTextureCache,
        p_pTextureCache,
        v5 + (v5 >> 2));
  }
  else if ( v5 < p_pTextureCache->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH<unsigned int,75>,Scaleform::ArrayConstPolicy<4,4,0>>::Reserve(
      p_pTextureCache,
      p_pTextureCache,
      v5);
  }
  v6 = (Scaleform::GFx::Resource **)&p_pTextureCache->Data[v5 - 1];
  p_pTextureCache->Size = v5;
  if ( v6 )
    *v6 = pupdate;
  Scaleform::RefCountImpl::AddRef(pupdate);
  Scaleform::Mutex::Unlock(v3);
}
