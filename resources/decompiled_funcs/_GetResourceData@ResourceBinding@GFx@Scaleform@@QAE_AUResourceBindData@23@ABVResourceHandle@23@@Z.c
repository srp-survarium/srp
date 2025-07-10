Scaleform::GFx::ResourceBindData *__thiscall Scaleform::GFx::ResourceBinding::GetResourceData(
        Scaleform::GFx::ResourceBinding *this,
        Scaleform::GFx::ResourceBindData *result,
        const Scaleform::GFx::ResourceHandle *h)
{
  Scaleform::GFx::Resource *pResource; // edi

  result->pResource.pObject = 0;
  result->pBinding = 0;
  if ( h->HType == RH_Index )
  {
    Scaleform::GFx::ResourceBinding::GetResourceData(this, result, h->BindIndex);
    return result;
  }
  else
  {
    result->pBinding = this;
    if ( h->HType )
    {
      result->pResource.pObject = 0;
      return result;
    }
    else
    {
      pResource = h->pResource;
      if ( pResource )
      {
        Scaleform::RefCountImpl::AddRef(h->pResource);
        if ( result->pResource.pObject )
          Scaleform::GFx::Resource::Release(result->pResource.pObject);
      }
      result->pResource.pObject = pResource;
      return result;
    }
  }
}
