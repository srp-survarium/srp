BOOL __thiscall Scaleform::Render::SKI_UserData::UpdateBundleEntry(
        Scaleform::Render::SKI_UserData *this,
        Scaleform::GFx::Resource *d,
        int p,
        Scaleform::Render::TreeCacheRoot *tr,
        Scaleform::Render::Renderer2DImpl *r,
        const Scaleform::Render::BundleIterator *__formal)
{
  Scaleform::Render::BundleEntry *v6; // edi
  Scaleform::Render::UserDataBundle *v7; // eax
  Scaleform::Render::Bundle *v8; // eax
  Scaleform::Render::Bundle *v9; // esi

  v6 = (Scaleform::Render::BundleEntry *)p;
  if ( !*(_DWORD *)(p + 20) )
  {
    p = 67;
    v7 = (Scaleform::Render::UserDataBundle *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                tr,
                                                52,
                                                &p);
    if ( v7 )
    {
      Scaleform::Render::UserDataBundle::UserDataBundle(v7, r->pHal.pObject, d);
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    Scaleform::Render::BundleEntry::SetBundle(v6, v9, 0);
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
  }
  return v6->pBundle.pObject != 0;
}
