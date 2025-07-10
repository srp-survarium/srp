void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  if ( newSize >= this->Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
      pheapAddr,
      newSize);
    this->Size = newSize;
    return;
  }
  this->Size = newSize;
}
