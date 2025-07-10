void __thiscall Scaleform::Render::DICommandQueue::OnNextCapture(
        Scaleform::Render::DICommandQueue *this,
        Scaleform::Render::ContextImpl::RenderNotify *pnotify)
{
  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)this);
  Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(this);
  Scaleform::Render::DICommandQueue::ExecuteNextCapture(this, pnotify);
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this);
}
