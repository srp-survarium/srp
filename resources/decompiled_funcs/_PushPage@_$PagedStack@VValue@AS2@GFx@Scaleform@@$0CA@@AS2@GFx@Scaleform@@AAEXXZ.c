void __thiscall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this)
{
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *pReserved; // ebp
  Scaleform::ArrayLH<Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *,2,Scaleform::ArrayDefaultPolicy> *p_Pages; // edi
  unsigned int v4; // esi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page **Data; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page **v6; // eax
  Scaleform::GFx::AS2::Value *pPageEnd; // ecx

  pReserved = this->pReserved;
  if ( pReserved )
    this->pReserved = pReserved->pNext;
  else
    pReserved = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                                          Scaleform::Memory::pGlobalHeap,
                                                                                          this,
                                                                                          516,
                                                                                          0);
  if ( pReserved )
  {
    p_Pages = &this->Pages;
    v4 = this->Pages.Data.Size + 1;
    if ( v4 >= this->Pages.Data.Size )
    {
      if ( v4 >= this->Pages.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)p_Pages,
          p_Pages,
          v4 + (v4 >> 2));
    }
    else if ( v4 < this->Pages.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)p_Pages,
        p_Pages,
        v4);
    }
    Data = p_Pages->Data.Data;
    this->Pages.Data.Size = v4;
    v6 = &Data[v4 - 1];
    if ( v6 )
      *v6 = pReserved;
    pPageEnd = this->pPageEnd;
    this->pPageStart = (Scaleform::GFx::AS2::Value *)pReserved;
    this->pCurrent = (Scaleform::GFx::AS2::Value *)pReserved;
    this->pPrevPageTop = pPageEnd - 1;
    this->pPageEnd = (Scaleform::GFx::AS2::Value *)&pReserved->pNext;
  }
  else
  {
    --this->pCurrent;
  }
}
