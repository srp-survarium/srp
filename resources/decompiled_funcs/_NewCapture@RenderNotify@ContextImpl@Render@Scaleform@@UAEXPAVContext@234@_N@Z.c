void __thiscall Scaleform::Render::ContextImpl::RenderNotify::NewCapture(
        Scaleform::Render::ContextImpl::RenderNotify *this,
        Scaleform::Render::ContextImpl::Context *context,
        bool hasChanges)
{
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *pPrev; // edx
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *p_ActiveContextSet; // ecx

  if ( context->pRenderer != this )
  {
    context->pRenderer = this;
    pPrev = this->ActiveContextSet.Root.pPrev;
    p_ActiveContextSet = (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)&this->ActiveContextSet;
    context->RenderNode.pPrev = pPrev;
    context->RenderNode.pNext = p_ActiveContextSet;
    p_ActiveContextSet->pPrev->pNext = &context->RenderNode;
    p_ActiveContextSet->pPrev = &context->RenderNode;
  }
}
