Scaleform::GFx::Resource *__thiscall Scaleform::GFx::ResourceHandle::GetResourceAndBinding(
        Scaleform::GFx::ResourceHandle *this,
        Scaleform::GFx::ResourceBinding *pbinding,
        Scaleform::GFx::ResourceBinding **presBinding)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::Resource *v5; // esi
  unsigned int BindIndex; // [esp-8h] [ebp-10h]
  Scaleform::GFx::ResourceBindData v7; // [esp+0h] [ebp-8h] BYREF

  if ( this->HType )
  {
    BindIndex = this->BindIndex;
    v7.pResource.pObject = 0;
    v7.pBinding = 0;
    Scaleform::GFx::ResourceBinding::GetResourceData(pbinding, &v7, BindIndex);
    pObject = v7.pResource.pObject;
    *presBinding = v7.pBinding;
    v5 = pObject;
    if ( pObject )
      Scaleform::GFx::Resource::Release(pObject);
    return v5;
  }
  else
  {
    *presBinding = pbinding;
    return this->pResource;
  }
}
