Scaleform::GFx::Resource *__thiscall Scaleform::GFx::ResourceHandle::GetResource(
        Scaleform::GFx::ResourceHandle *this,
        Scaleform::GFx::ResourceBinding *pbinding)
{
  Scaleform::GFx::Resource *result; // eax
  Scaleform::GFx::Resource *pObject; // esi
  Scaleform::GFx::ResourceBindData rbd; // [esp+0h] [ebp-8h] BYREF

  result = this->pResource;
  if ( this->HType )
  {
    rbd.pResource.pObject = 0;
    rbd.pBinding = 0;
    Scaleform::GFx::ResourceBinding::GetResourceData(pbinding, &rbd, (volatile unsigned int)result);
    pObject = rbd.pResource.pObject;
    if ( rbd.pResource.pObject )
      Scaleform::GFx::Resource::Release(rbd.pResource.pObject);
    return pObject;
  }
  return result;
}
