Scaleform::Render::ProjectionMatrix3DPrimitive *__thiscall Scaleform::Render::ViewMatrix3DPrimitive::`scalar deleting destructor'(
        Scaleform::Render::ProjectionMatrix3DPrimitive *this,
        char a2)
{
  this->Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ProjectionMatrix3DPrimitive_vtbl *)&Scaleform::Render::ViewMatrix3DPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::ViewMatrix3DPrimitive,68>'};
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
