Scaleform::Render::UserDataPrimitive *__thiscall Scaleform::Render::UserDataPrimitive::`vector deleting destructor'(
        Scaleform::Render::UserDataPrimitive *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::UserDataPrimitive_vtbl *)&Scaleform::Render::UserDataPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,68>'};
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::UserDataPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  pObject = (Scaleform::RefCountVImpl *)this->pUserData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


void *__thiscall Scaleform::Render::UserDataPrimitive::`vector deleting destructor'(char *this, unsigned int a2)
{
  return Scaleform::Render::UserDataPrimitive::`vector deleting destructor'(
           (Scaleform::Render::UserDataPrimitive *)(this - 8),
           a2);
}
