void __thiscall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this)
{
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v2; // eax
  Scaleform::ArrayLH<Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *,2,Scaleform::ArrayDefaultPolicy> *p_Pages; // edi
  unsigned int Size; // eax
  unsigned int v5; // ebx
  Scaleform::GFx::AS2::Value *Values; // eax
  unsigned int v7; // eax

  if ( this->Pages.Data.Size <= 1 )
  {
    if ( this->pCurrent++ != (Scaleform::GFx::AS2::Value *)-16 )
      this->pCurrent->T.Type = 0;
  }
  else
  {
    v2 = this->Pages.Data.Data[this->Pages.Data.Size - 1];
    p_Pages = &this->Pages;
    v2->pNext = this->pReserved;
    this->pReserved = v2;
    Size = this->Pages.Data.Size;
    v5 = Size - 1;
    if ( Size )
    {
      if ( v5 < this->Pages.Data.Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Pages,
          &this->Pages,
          v5);
    }
    else if ( v5 >= this->Pages.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Pages,
        &this->Pages,
        v5 + (v5 >> 2));
    }
    this->Pages.Data.Size = v5;
    Values = p_Pages->Data.Data[v5 - 1]->Values;
    this->pPageStart = Values;
    Values += 32;
    this->pPageEnd = Values;
    this->pCurrent = Values - 1;
    v7 = this->Pages.Data.Size;
    if ( v7 <= 1 )
      this->pPrevPageTop = this->pPageStart;
    else
      this->pPrevPageTop = &p_Pages->Data.Data[v7 - 2]->Values[31];
  }
}


void __thiscall Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PopPage(
        Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32> *this)
{
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *v2; // eax
  Scaleform::ArrayLH<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,2,Scaleform::ArrayDefaultPolicy> *p_Pages; // edi
  unsigned int Size; // eax
  unsigned int v5; // ebx
  Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject> *Values; // eax
  unsigned int v7; // eax

  if ( this->Pages.Data.Size <= 1 )
  {
    if ( this->pCurrent++ != (Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject> *)-4 )
      this->pCurrent->pObject = 0;
  }
  else
  {
    v2 = this->Pages.Data.Data[this->Pages.Data.Size - 1];
    p_Pages = &this->Pages;
    v2->pNext = this->pReserved;
    this->pReserved = v2;
    Size = this->Pages.Data.Size;
    v5 = Size - 1;
    if ( Size )
    {
      if ( v5 < this->Pages.Data.Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Pages,
          &this->Pages,
          v5);
    }
    else if ( v5 >= this->Pages.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Pages,
        &this->Pages,
        v5 + (v5 >> 2));
    }
    this->Pages.Data.Size = v5;
    Values = p_Pages->Data.Data[v5 - 1]->Values;
    this->pPageStart = Values;
    Values += 32;
    this->pPageEnd = Values;
    this->pCurrent = Values - 1;
    v7 = this->Pages.Data.Size;
    if ( v7 <= 1 )
      this->pPrevPageTop = this->pPageStart;
    else
      this->pPrevPageTop = &p_Pages->Data.Data[v7 - 2]->Values[31];
  }
}
