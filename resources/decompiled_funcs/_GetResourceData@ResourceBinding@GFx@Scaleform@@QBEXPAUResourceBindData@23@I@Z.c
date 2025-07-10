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
