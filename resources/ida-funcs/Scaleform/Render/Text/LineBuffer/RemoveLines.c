void __thiscall Scaleform::Render::Text::LineBuffer::RemoveLines(
        Scaleform::Render::Text::LineBuffer *this,
        unsigned int lineIdx,
        unsigned int num)
{
  unsigned int v3; // ebx
  Scaleform::Render::Text::LineBuffer::Line *v5; // edi
  unsigned int Size; // eax
  unsigned int i; // [esp+10h] [ebp-4h]

  v3 = lineIdx;
  for ( i = 0; i < num; ++i )
  {
    if ( !this || v3 >= this->Lines.Data.Size || (v3 & 0x80000000) != 0 )
      break;
    v5 = this->Lines.Data.Data[v3];
    if ( v5 )
    {
      Scaleform::Render::Text::LineBuffer::Line::Release(this->Lines.Data.Data[v3]);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
    }
    if ( v3 < this->Lines.Data.Size )
      ++v3;
  }
  Size = this->Lines.Data.Size;
  if ( Size != num )
  {
    memmove(
      (int)&this->Lines.Data.Data[lineIdx],
      (const __m128i *)(&this->Lines.Data.Data[lineIdx] + num),
      4 * (Size - lineIdx - num));
    this->Lines.Data.Size -= num;
    return;
  }
  if ( !Size )
  {
    if ( !this->Lines.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        0);
    goto LABEL_18;
  }
  if ( (this->Lines.Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_18:
    this->Lines.Data.Size = 0;
    return;
  }
  if ( this->Lines.Data.Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Lines.Data.Data);
    this->Lines.Data.Data = 0;
  }
  this->Lines.Data.Policy.Capacity = 0;
  this->Lines.Data.Size = 0;
}
