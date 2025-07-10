void __thiscall Scaleform::GFx::AS2::MemoryContextImpl::~MemoryContextImpl(
        Scaleform::GFx::AS3::MemoryContextImpl *this)
{
  Scaleform::MemoryHeap *Heap; // ecx
  Scaleform::Render::Text::Allocator *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx

  Heap = this->Heap;
  this->__vftable = (Scaleform::GFx::AS3::MemoryContextImpl_vtbl *)&Scaleform::GFx::AS2::MemoryContextImpl::`vftable';
  Heap->SetLimitHandler(Heap, 0);
  this->LimHandler.__vftable = (Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit_vtbl *)&Scaleform::Render::StateData::Interface::`vftable';
  pObject = this->TextAllocator.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->ASGC.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::RefCountVImpl *)this->StringMgr.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  this->__vftable = (Scaleform::GFx::AS3::MemoryContextImpl_vtbl *)&Scaleform::GFx::MemoryContext::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
