Scaleform::GFx::Resource *__thiscall Scaleform::GFx::ResourceHandle::GetResourceAndBinding(
        Scaleform::GFx::ResourceHandle *this,
        Scaleform::GFx::ResourceBinding *pbinding,
        Scaleform::GFx::ResourceBinding **presBinding)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::Resource *v5; // esi
  volatile unsigned int BindIndex; // [esp-8h] [ebp-10h]
  Scaleform::GFx::ResourceBindData rbd; // [esp+0h] [ebp-8h] BYREF

  if ( this->HType )
  {
    BindIndex = this->BindIndex;
    rbd.pResource.pObject = 0;
    rbd.pBinding = 0;
    Scaleform::GFx::ResourceBinding::GetResourceData(pbinding, &rbd, BindIndex);
    pObject = rbd.pResource.pObject;
    *presBinding = rbd.pBinding;
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
