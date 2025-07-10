void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index)
{
  unsigned int Size; // eax

  Size = this->Data.Size;
  if ( Size == 1 )
  {
    Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->Data,
      0);
  }
  else
  {
    memmove(
      (unsigned __int8 *)&this->Data.Data[index],
      (unsigned __int8 *)&this->Data.Data[index + 1],
      40 * (Size - index - 1));
    --this->Data.Size;
  }
}
