void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  unsigned int Size; // eax
  int v5; // eax
  Scaleform::Render::FillStyleType *v6; // ecx
  Scaleform::RefCountVImpl **p_pFill; // edi
  int v8; // ebp

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::Reserve(
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
      p_pFill = (Scaleform::RefCountVImpl **)&v6->pFill;
      v8 = v5;
      do
      {
        if ( *p_pFill )
          Scaleform::RefCountImpl::Release(*p_pFill);
        p_pFill -= 2;
        --v8;
      }
      while ( v8 );
    }
    if ( newSize < this->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newSize);
      this->Size = newSize;
      return;
    }
  }
  this->Size = newSize;
}
