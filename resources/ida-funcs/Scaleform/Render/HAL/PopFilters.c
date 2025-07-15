void __thiscall Scaleform::Render::HAL::PopFilters(Scaleform::Render::HAL *this)
{
  Scaleform::Render::RenderEvent *v2; // ebp
  void *v3; // edi
  bool v4; // al
  Scaleform::ArrayLH<Scaleform::Render::HAL::FilterStackEntry,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_FilterStack; // ecx
  const Scaleform::Render::HAL::FilterStackEntry *v6; // eax
  unsigned int v7; // eax
  Scaleform::String v8; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::Render::HAL::FilterStackEntry v9; // [esp+10h] [ebp-10h] BYREF
  Scaleform::Render::HAL::FilterStackEntry result; // [esp+18h] [ebp-8h] BYREF

  Scaleform::String::String(&v8, (const __m128i *)"Scaleform::Render::HAL::PopFilters");
  v2 = this->GetEvent(this, 12);
  v3 = (void *)(v8.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v8.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  v4 = this->shouldRenderFilters(this, this->FilterStack.Data.Data[this->FilterStack.Data.Size - 1].pPrimitive.pObject);
  p_FilterStack = &this->FilterStack;
  if ( v4 )
  {
    v9.pPrimitive.pObject = 0;
    v9.pRenderTarget.pObject = 0;
    v6 = Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>>::Pop(
           p_FilterStack,
           &result);
    Scaleform::Render::HAL::FilterStackEntry::operator=(&v9, v6);
    if ( result.pRenderTarget.pObject )
      result.pRenderTarget.pObject->Release(result.pRenderTarget.pObject);
    if ( result.pPrimitive.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pPrimitive.pObject);
    if ( this->Profiler.OverrideMasks )
    {
      if ( !this->FilterStack.Data.Size )
        this->Profiler.DrawMode = 0;
      if ( v9.pRenderTarget.pObject )
        v9.pRenderTarget.pObject->Release(v9.pRenderTarget.pObject);
      if ( v9.pPrimitive.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v9.pPrimitive.pObject);
    }
    else
    {
      v7 = this->HALState & 0x100;
      if ( v7 && this->CachedFilterIndex < (signed int)this->FilterStack.Data.Size )
      {
        Scaleform::Render::HAL::FilterStackEntry::~FilterStackEntry(&v9);
        v2->End(v2);
        return;
      }
      this->CachedFilterIndex = -1;
      if ( v7 )
      {
        this->drawCachedFilter(this, v9.pPrimitive.pObject);
        this->GetRQProcessor(this)->QueueEmitFilter = QPF_All;
        this->HALState &= ~0x100u;
      }
      else
      {
        this->drawUncachedFilter(this, &v9);
      }
      if ( !this->FilterStack.Data.Size )
        this->HALState &= ~0x80u;
      if ( v9.pRenderTarget.pObject )
        v9.pRenderTarget.pObject->Release(v9.pRenderTarget.pObject);
      if ( v9.pPrimitive.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v9.pPrimitive.pObject);
    }
  }
  else
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>>::Pop(
      p_FilterStack,
      &result);
    if ( result.pRenderTarget.pObject )
      result.pRenderTarget.pObject->Release(result.pRenderTarget.pObject);
    if ( result.pPrimitive.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pPrimitive.pObject);
  }
  v2->End(v2);
}
