void __thiscall Scaleform::Render::HAL::~HAL(Scaleform::Render::HAL *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx

  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->UserDataStack.Data.Data);
  Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2>>::freeMem(&this->BeginDisplayDataList);
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::~ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>(&this->FilterStack.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::~ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>(&this->RenderTargetStack.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::MaskStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::MaskStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::~ArrayDataBase<Scaleform::Render::HAL::MaskStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::MaskStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>(&this->MaskStack.Data);
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
