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


void __thiscall Scaleform::GFx::ResourceBinding::GetResourceData(
        Scaleform::GFx::ResourceBinding *this,
        Scaleform::GFx::ResourceBindData *pdata,
        volatile unsigned int index)
{
  Scaleform::GFx::ResourceBindData *v3; // esi

  if ( this->Frozen && index < this->ResourceCount )
  {
    v3 = &this->pResources[index];
    if ( v3->pResource.pObject )
      Scaleform::RefCountImpl::AddRef(v3->pResource.pObject);
    if ( pdata->pResource.pObject )
      Scaleform::GFx::Resource::Release(pdata->pResource.pObject);
    *pdata = *v3;
  }
  else
  {
    Scaleform::GFx::ResourceBinding::GetResourceData_Locked(this, pdata, index);
  }
}
