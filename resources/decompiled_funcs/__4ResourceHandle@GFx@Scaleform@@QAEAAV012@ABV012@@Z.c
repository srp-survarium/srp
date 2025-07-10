Scaleform::GFx::ResourceHandle *__thiscall Scaleform::GFx::ResourceHandle::operator=(
        Scaleform::GFx::ResourceHandle *this,
        const Scaleform::GFx::ResourceHandle *src)
{
  Scaleform::GFx::Resource *pResource; // ecx
  Scaleform::GFx::Resource *v4; // ecx

  if ( src->HType == RH_Pointer )
  {
    pResource = src->pResource;
    if ( pResource )
      Scaleform::RefCountImpl::AddRef(pResource);
  }
  if ( this->HType == RH_Pointer )
  {
    v4 = this->pResource;
    if ( v4 )
      Scaleform::GFx::Resource::Release(v4);
  }
  *this = *src;
  return this;
}
