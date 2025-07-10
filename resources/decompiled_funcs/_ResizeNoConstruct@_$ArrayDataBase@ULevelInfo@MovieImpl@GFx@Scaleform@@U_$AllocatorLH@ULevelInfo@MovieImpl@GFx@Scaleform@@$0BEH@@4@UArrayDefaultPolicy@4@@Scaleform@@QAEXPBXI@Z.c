void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  unsigned int Size; // eax
  int v5; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v6; // ecx
  Scaleform::RefCountNTSImpl **p_pObject; // edi
  int v8; // ebp

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newSize + (newSize >> 2));
  }
  else
  {
    v5 = Size - newSize;
    v6 = &this->Data[v5 - 1 + newSize];
    if ( v5 )
    {
      p_pObject = &v6->pSprite.pObject;
      v8 = v5;
      do
      {
        if ( *p_pObject )
          Scaleform::RefCountNTSImpl::Release(*p_pObject);
        p_pObject -= 2;
        --v8;
      }
      while ( v8 );
    }
    if ( newSize < this->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newSize);
      this->Size = newSize;
      return;
    }
  }
  this->Size = newSize;
}
