Scaleform::GFx::Resource *__thiscall Scaleform::GFx::ResourceHandle::GetResource(
        Scaleform::GFx::ResourceHandle *this,
        Scaleform::GFx::ResourceBinding *pbinding)
{
  Scaleform::GFx::Resource *result; // eax
  Scaleform::GFx::Resource *pObject; // esi
  Scaleform::GFx::ResourceBindData v4; // [esp+0h] [ebp-8h] BYREF

  result = this->pResource;
  if ( this->HType )
  {
    v4.pResource.pObject = 0;
    v4.pBinding = 0;
    Scaleform::GFx::ResourceBinding::GetResourceData(pbinding, &v4, (unsigned int)result);
    pObject = v4.pResource.pObject;
    if ( v4.pResource.pObject )
      Scaleform::GFx::Resource::Release(v4.pResource.pObject);
    return pObject;
  }
  return result;
}
