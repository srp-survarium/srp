void __thiscall Scaleform::GFx::ResourceBinding::GetResourceData_Locked(
        Scaleform::GFx::ResourceBinding *this,
        Scaleform::GFx::ResourceBindData *pdata,
        volatile unsigned int index)
{
  Scaleform::Lock *p_ResourceLock; // ebp
  char v5; // bl
  Scaleform::GFx::ResourceBindData *volatile pResources; // edx
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::ResourceBindData *v8; // esi
  Scaleform::GFx::Resource *v9[2]; // [esp+10h] [ebp-8h] BYREF

  p_ResourceLock = &this->ResourceLock;
  v5 = 0;
  v9[0] = 0;
  EnterCriticalSection(&this->ResourceLock.cs);
  if ( index >= this->ResourceCount )
  {
    v5 = 1;
    v9[0] = 0;
    v9[1] = 0;
    v8 = (Scaleform::GFx::ResourceBindData *)v9;
  }
  else
  {
    pResources = this->pResources;
    pObject = pResources[index].pResource.pObject;
    v8 = &pResources[index];
    if ( pObject )
      Scaleform::RefCountImpl::AddRef(pObject);
  }
  if ( pdata->pResource.pObject )
    Scaleform::GFx::Resource::Release(pdata->pResource.pObject);
  *pdata = *v8;
  if ( (v5 & 1) != 0 && v9[0] )
    Scaleform::GFx::Resource::Release(v9[0]);
  LeaveCriticalSection(&p_ResourceLock->cs);
}
