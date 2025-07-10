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
