void __thiscall Scaleform::Render::ContextImpl::RenderNotify::EndFrameContextNotify(
        Scaleform::Render::ContextImpl::RenderNotify *this)
{
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *pNext; // eax
  Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *i; // ecx

  pNext = this->ActiveContextSet.Root.pNext;
  for ( i = &this->ActiveContextSet;
        pNext != (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)i;
        pNext = pNext->pNext )
  {
    pNext->pContext->NextCaptureCalledInFrame = 0;
  }
}
