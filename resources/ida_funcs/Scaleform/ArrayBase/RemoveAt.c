void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::MovieImpl::FontDesc,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::FontDesc,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::MovieImpl::FontDesc,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::FontDesc,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index)
{
  Scaleform::GFx::FontResource *pObject; // ecx
  Scaleform::GFx::MovieImpl::FontDesc *v4; // esi
  Scaleform::GFx::Resource *v5; // esi

  if ( this->Data.Size == 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::FontDesc,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::FontDesc,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->Data,
      this,
      0);
  }
  else
  {
    pObject = this->Data.Data[index].pFont.pObject;
    v4 = &this->Data.Data[index];
    if ( pObject )
      Scaleform::GFx::Resource::Release(pObject);
    v5 = v4->pMovieDef.pObject;
    if ( v5 )
      Scaleform::GFx::Resource::Release(v5);
    memmove(
      (unsigned __int8 *)&this->Data.Data[index],
      (unsigned __int8 *)&this->Data.Data[index + 1],
      8 * (this->Data.Size - index) - 8);
    --this->Data.Size;
  }
}


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


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index)
{
  unsigned int Size; // eax

  Size = this->Data.Size;
  if ( Size == 1 )
  {
    Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->Data,
      0);
  }
  else
  {
    memmove(
      (unsigned __int8 *)&this->Data.Data[index],
      (unsigned __int8 *)&this->Data.Data[index + 1],
      12 * (Size - index - 1));
    --this->Data.Size;
  }
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index)
{
  Scaleform::GFx::AS3::Value *Data; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *v5; // ecx

  if ( this->Data.Size == 1 )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->Data,
      0);
  }
  else
  {
    Data = this->Data.Data;
    Flags = Data[index].Flags;
    v5 = &Data[index];
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v5);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v5);
    }
    memmove(
      (unsigned __int8 *)&this->Data.Data[index],
      (unsigned __int8 *)&this->Data.Data[index + 1],
      16 * (this->Data.Size - index - 1));
    --this->Data.Size;
  }
}
