Scaleform::Render::ProjectionMatrix3DBundle *__thiscall Scaleform::Render::ProjectionMatrix3DBundle::`scalar deleting destructor'(
        Scaleform::Render::ProjectionMatrix3DBundle *this,
        char a2)
{
  Scaleform::Render::ProjectionMatrix3DPrimitive *p_Prim; // ecx

  p_Prim = &this->Prim;
  p_Prim->Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ProjectionMatrix3DPrimitive_vtbl *)&Scaleform::Render::ViewMatrix3DPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::ViewMatrix3DPrimitive,68>'};
  p_Prim->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(p_Prim);
  this->__vftable = (Scaleform::Render::ProjectionMatrix3DBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
