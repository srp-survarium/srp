void __thiscall Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>(
        Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32> *this)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Pages; // esi
  Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject> *v3; // ebp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v4; // eax
  unsigned int v5; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // edx
  Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject> **v7; // edi
  int v8; // [esp+10h] [ebp-4h] BYREF

  p_Pages = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Pages;
  this->Pages.Data.Data = 0;
  this->Pages.Data.Size = 0;
  this->Pages.Data.Policy.Capacity = 0;
  this->pReserved = 0;
  v3 = (Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject> *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                this,
                                                                132,
                                                                0);
  if ( p_Pages->Policy.Capacity < 0xF )
  {
    if ( p_Pages->Data )
    {
      v4 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                                    Scaleform::Memory::pGlobalHeap,
                                                                                    p_Pages->Data,
                                                                                    64);
    }
    else
    {
      v8 = 2;
      v4 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                                    Scaleform::Memory::pGlobalHeap,
                                                                                    p_Pages,
                                                                                    64,
                                                                                    &v8);
    }
    p_Pages->Data = v4;
    p_Pages->Policy.Capacity = 16;
  }
  v5 = p_Pages->Size + 1;
  if ( v5 >= p_Pages->Size )
  {
    if ( v5 >= p_Pages->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Pages,
        p_Pages,
        v5 + (v5 >> 2));
  }
  else if ( v5 < p_Pages->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_Pages,
      p_Pages,
      p_Pages->Size + 1);
  }
  Data = p_Pages->Data;
  p_Pages->Size = v5;
  v7 = (Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject> **)&Data[v5 - 1];
  if ( v7 )
    *v7 = v3;
  this->pPageEnd = v3 + 32;
  this->pPageStart = v3;
  this->pCurrent = v3;
  this->pPrevPageTop = v3;
  if ( v3 )
    v3->pObject = 0;
}
