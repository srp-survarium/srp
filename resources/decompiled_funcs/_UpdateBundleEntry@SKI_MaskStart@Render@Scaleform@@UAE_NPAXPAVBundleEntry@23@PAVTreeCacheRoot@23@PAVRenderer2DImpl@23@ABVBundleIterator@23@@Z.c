BOOL __thiscall Scaleform::Render::SKI_MaskStart::UpdateBundleEntry(
        Scaleform::Render::SKI_MaskStart *this,
        void *__formal,
        int p,
        Scaleform::Render::TreeCacheRoot *tr,
        Scaleform::Render::Renderer2DImpl *r,
        const Scaleform::Render::BundleIterator *a6)
{
  Scaleform::Render::BundleEntry *v6; // edi
  bool v7; // zf
  Scaleform::Render::MaskPrimitive::MaskAreaType v8; // esi
  Scaleform::Render::MaskBundle *v9; // eax
  Scaleform::Render::Bundle *v10; // eax
  Scaleform::Render::Bundle *v11; // esi

  v6 = (Scaleform::Render::BundleEntry *)p;
  if ( !*(_DWORD *)(p + 20) )
  {
    v7 = this->Type == SortKey_MaskStartClipped;
    p = 67;
    v8 = v7;
    v9 = (Scaleform::Render::MaskBundle *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            tr,
                                            64,
                                            &p);
    if ( v9 )
    {
      Scaleform::Render::MaskBundle::MaskBundle(v9, r->pHal.pObject, v8);
      v11 = v10;
    }
    else
    {
      v11 = 0;
    }
    Scaleform::Render::BundleEntry::SetBundle(v6, v11, 0);
    if ( v11 )
      Scaleform::RefCountNTSImpl::Release(v11);
  }
  return v6->pBundle.pObject != 0;
}
