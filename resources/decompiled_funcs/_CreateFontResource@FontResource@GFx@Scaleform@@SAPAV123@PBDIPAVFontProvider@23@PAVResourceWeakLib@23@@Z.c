Scaleform::GFx::FontResource *__cdecl Scaleform::GFx::FontResource::CreateFontResource(
        char *pname,
        unsigned int fontFlags,
        Scaleform::GFx::Resource *pprovider,
        Scaleform::GFx::ResourceWeakLib *plib)
{
  Scaleform::GFx::Resource *v4; // ebx
  Scaleform::GFx::GFxSystemFontResourceKey *v5; // eax
  Scaleform::RefCountVImpl *v6; // eax
  Scaleform::RefCountVImpl *v7; // esi
  Scaleform::GFx::Resource *v8; // esi
  Scaleform::GFx::FontResource *v9; // eax
  Scaleform::GFx::Resource *v10; // eax
  Scaleform::GFx::ResourceLib::BindHandle phandle; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::ResourceKey fontKey; // [esp+1Ch] [ebp-8h] BYREF

  v4 = 0;
  v5 = (Scaleform::GFx::GFxSystemFontResourceKey *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     20,
                                                     0);
  if ( v5 )
  {
    Scaleform::GFx::GFxSystemFontResourceKey::GFxSystemFontResourceKey(v5, pname, fontFlags, pprovider);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  Scaleform::GFx::ResourceKey::ResourceKey(&fontKey, &GFxSystemFontResourceKeyInterface_Instance, v7);
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  phandle.State = RS_Unbound;
  phandle.pResource = 0;
  if ( Scaleform::GFx::ResourceWeakLib::BindResourceKey(plib, &phandle, &fontKey) != 3 )
  {
    v4 = Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&phandle);
    goto LABEL_16;
  }
  v8 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::GFx::Resource *, char *, unsigned int))pprovider->GetKey)(
                                     pprovider,
                                     pname,
                                     fontFlags);
  if ( v8 )
  {
    v9 = (Scaleform::GFx::FontResource *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
    if ( v9 )
    {
      Scaleform::GFx::FontResource::FontResource(v9, v8, &fontKey);
      v4 = v10;
      if ( v10 )
      {
        Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(phandle.pSlot, v10);
        goto LABEL_13;
      }
    }
    else
    {
      v4 = 0;
    }
  }
  Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(phandle.pSlot, (char *)&buf);
LABEL_13:
  if ( v8 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v8);
LABEL_16:
  if ( phandle.State == RS_Available )
  {
    Scaleform::GFx::Resource::Release(phandle.pResource);
  }
  else if ( phandle.State >= RS_WaitingResolve )
  {
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)phandle.pResource);
  }
  if ( fontKey.pKeyInterface )
    fontKey.pKeyInterface->Release(fontKey.pKeyInterface, fontKey.hKeyData);
  return (Scaleform::GFx::FontResource *)v4;
}
