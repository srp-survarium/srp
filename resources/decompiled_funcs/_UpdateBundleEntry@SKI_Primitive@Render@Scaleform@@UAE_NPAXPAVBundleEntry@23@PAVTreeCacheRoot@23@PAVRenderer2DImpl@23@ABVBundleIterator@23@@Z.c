BOOL __userpurge Scaleform::Render::SKI_Primitive::UpdateBundleEntry@<eax>(
        Scaleform::Render::SKI_Primitive *this@<ecx>,
        int a2@<edi>,
        void *d,
        Scaleform::Render::BundleEntry *p,
        int tr,
        Scaleform::Render::Renderer2DImpl *r,
        Scaleform::Render::Renderer2DImpl *__formal)
{
  void (__thiscall *AddRef)(struct Scaleform::Render::SKI_Primitive *, void *); // edx
  Scaleform::Render::TreeCacheRoot *v8; // esi
  Scaleform::Render::PrimitiveBundle *v9; // eax
  Scaleform::Render::Bundle *v10; // eax
  Scaleform::Render::Bundle *v11; // esi
  Scaleform::Render::SortKey ourKey; // [esp+10h] [ebp-8h] BYREF

  if ( !p->pBundle.pObject )
  {
    AddRef = Scaleform::Render::SKI_Primitive::Instance.AddRef;
    ourKey.Data = d;
    ((void (__thiscall *)(Scaleform::Render::SKI_Primitive *, void *, int))AddRef)(
      &Scaleform::Render::SKI_Primitive::Instance,
      d,
      a2);
    v8 = (Scaleform::Render::TreeCacheRoot *)r;
    tr = 67;
    v9 = (Scaleform::Render::PrimitiveBundle *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 r,
                                                 88,
                                                 &tr);
    if ( v9 )
    {
      Scaleform::Render::PrimitiveBundle::PrimitiveBundle(
        v9,
        v8,
        (const Scaleform::Render::SortKey *)&ourKey.Data,
        __formal);
      v11 = v10;
    }
    else
    {
      v11 = 0;
    }
    Scaleform::Render::BundleEntry::SetBundle(p, v11, 0);
    if ( v11 )
      Scaleform::RefCountNTSImpl::Release(v11);
    ((void (__thiscall *)(Scaleform::Render::SKI_Primitive *))Scaleform::Render::SKI_Primitive::Instance.Release)(&Scaleform::Render::SKI_Primitive::Instance);
  }
  return p->pBundle.pObject != 0;
}
