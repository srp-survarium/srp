BOOL __thiscall Scaleform::Render::SKI_ComplexPrimitive::UpdateBundleEntry(
        Scaleform::Render::SKI_ComplexPrimitive *this,
        void *__formal,
        int p,
        Scaleform::Render::TreeCacheRoot *tr,
        Scaleform::Render::Renderer2DImpl *a5,
        const Scaleform::Render::BundleIterator *a6)
{
  Scaleform::Render::BundleEntry *v6; // edi
  Scaleform::Render::ComplexPrimitiveBundle *v7; // eax
  Scaleform::Render::Bundle *v8; // eax
  Scaleform::Render::Bundle *v9; // esi

  v6 = (Scaleform::Render::BundleEntry *)p;
  if ( !*(_DWORD *)(p + 20) )
  {
    p = 67;
    v7 = (Scaleform::Render::ComplexPrimitiveBundle *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        tr,
                                                        48,
                                                        &p);
    if ( v7 )
    {
      Scaleform::Render::ComplexPrimitiveBundle::ComplexPrimitiveBundle(v7);
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
