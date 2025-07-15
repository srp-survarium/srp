void __thiscall Scaleform::Render::UserDataBundle::~UserDataBundle(Scaleform::Render::UserDataBundle *this)
{
  Scaleform::Render::UserDataPrimitive *p_Prim; // esi
  Scaleform::RefCountVImpl *pObject; // ecx

  p_Prim = &this->Prim;
  this->Prim.__vftable = (Scaleform::Render::UserDataPrimitive_vtbl *)&Scaleform::Render::UserDataPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,68>'};
  this->Prim.__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::UserDataPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  pObject = (Scaleform::RefCountVImpl *)this->Prim.pUserData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  p_Prim->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(p_Prim);
  this->__vftable = (Scaleform::Render::UserDataBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}
