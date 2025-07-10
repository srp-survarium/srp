void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index)
{
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ecx

  if ( this->Data.Size == 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->Data,
      this,
      0);
  }
  else
  {
    pCharacter = this->Data.Data[index].pCharacter;
    if ( pCharacter )
      Scaleform::RefCountNTSImpl::Release(pCharacter);
    memmove(
      (unsigned __int8 *)&this->Data.Data[index],
      (unsigned __int8 *)&this->Data.Data[index + 1],
      12 * (this->Data.Size - index - 1));
    --this->Data.Size;
  }
}
