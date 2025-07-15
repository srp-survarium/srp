void __thiscall Scaleform::Render::DrawableImageContext::OnCapture(Scaleform::Render::DrawableImageContext *this)
{
  Scaleform::Render::ContextImpl::Context *pNext; // ecx
  Scaleform::Render::DICommandQueue *Capacity; // esi
  unsigned int *p_SpinCount; // eax
  Scaleform::GFx::Resource *v5; // edi
  unsigned int *v6; // eax

  pNext = (Scaleform::Render::ContextImpl::Context *)this->pNext;
  if ( pNext )
    Scaleform::Render::ContextImpl::Context::Capture(pNext);
  Capacity = 0;
  if ( this == (Scaleform::Render::DrawableImageContext *)-64 )
    p_SpinCount = 0;
  else
    p_SpinCount = &this->TreeRootKillListLock.cs.SpinCount;
  if ( (unsigned int *)this->TreeRootKillList.Data.Policy.Capacity != p_SpinCount )
  {
    Capacity = (Scaleform::Render::DICommandQueue *)this->TreeRootKillList.Data.Policy.Capacity;
    if ( Capacity )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)this->TreeRootKillList.Data.Policy.Capacity);
    while ( 1 )
    {
      v5 = (Scaleform::GFx::Resource *)Capacity->pNext;
      Scaleform::Render::DICommandQueue::OnCapture(Capacity);
      v6 = this == (Scaleform::Render::DrawableImageContext *)-64 ? 0 : &this->TreeRootKillListLock.cs.SpinCount;
      if ( v5 == (Scaleform::GFx::Resource *)v6 )
        break;
      if ( v5 )
        Scaleform::RefCountImpl::AddRef(v5);
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)Capacity);
      Capacity = (Scaleform::Render::DICommandQueue *)v5;
    }
  }
  Scaleform::Render::DrawableImageContext::processTreeRootKillList((Scaleform::Render::DrawableImageContext *)((char *)this - 8));
  if ( Capacity )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)Capacity);
}
