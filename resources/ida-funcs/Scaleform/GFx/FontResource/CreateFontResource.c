Scaleform::GFx::FontResource *__cdecl Scaleform::GFx::FontResource::CreateFontResource(
        const __m128i *pname,
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
  Scaleform::GFx::ResourceLib::BindHandle v12; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::ResourceKey v13; // [esp+1Ch] [ebp-8h] BYREF

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
  Scaleform::GFx::ResourceKey::ResourceKey(&v13, &GFxSystemFontResourceKeyInterface_Instance, v7);
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v12.State = RS_Unbound;
  v12.pResource = 0;
  if ( Scaleform::GFx::ResourceWeakLib::BindResourceKey(plib, &v12, &v13) != RS_NeedsResolve )
  {
    v4 = Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&v12);
    goto LABEL_16;
  }
  v8 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::GFx::Resource *, const __m128i *, unsigned int))pprovider->GetKey)(
                                     pprovider,
                                     pname,
                                     fontFlags);
  if ( v8 )
  {
    v9 = (Scaleform::GFx::FontResource *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
    if ( v9 )
    {
      Scaleform::GFx::FontResource::FontResource(v9, v8, &v13);
      v4 = v10;
      if ( v10 )
      {
        Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(v12.pSlot, v10);
        goto LABEL_13;
      }
    }
    else
    {
      v4 = 0;
    }
  }
  Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(v12.pSlot, (const __m128i *)uri);
LABEL_13:
  if ( v8 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v8);
LABEL_16:
  if ( v12.State == RS_Available )
  {
    Scaleform::GFx::Resource::Release(v12.pResource);
  }
  else if ( v12.State >= RS_WaitingResolve )
  {
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v12.pResource);
  }
  if ( v13.pKeyInterface )
    v13.pKeyInterface->Release(v13.pKeyInterface, v13.hKeyData);
  return (Scaleform::GFx::FontResource *)v4;
}
