void __thiscall Scaleform::Render::HAL::~HAL(Scaleform::Render::HAL *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx

  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->UserDataStack.Data.Data);
  Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2>>::freeMem(&this->BeginDisplayDataList);
  Scaleform::ConstructorMov<Scaleform::Render::HAL::FilterStackEntry>::DestructArray(
    this->FilterStack.Data.Data,
    this->FilterStack.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->FilterStack.Data.Data);
  Scaleform::ConstructorMov<Scaleform::Render::HAL::RenderTargetEntry>::DestructArray(
    this->RenderTargetStack.Data.Data,
    this->RenderTargetStack.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->RenderTargetStack.Data.Data);
  Scaleform::ConstructorMov<Scaleform::Render::HAL::MaskStackEntry>::DestructArray(
    this->MaskStack.Data.Data,
    this->MaskStack.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->MaskStack.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->BlendModeStack.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->ProjectionMatrix3DStack.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->ViewMatrix3DStack.Data.Data);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&this->QueueProcessor);
  pObject = (Scaleform::RefCountVImpl *)this->pRenderBufferManager.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::Render::RenderQueue::Shutdown(&this->Queue);
  v3 = (Scaleform::RefCountVImpl *)this->Matrices.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
