void __thiscall Scaleform::Render::ContextImpl::RenderNotify::ContextReleased(
        Scaleform::Render::ContextImpl::RenderNotify *this,
        Scaleform::Render::ContextImpl::Context *context)
{
  context->RenderNode.pPrev->pNext = context->RenderNode.pNext;
  context->RenderNode.pNext->pPrev = context->RenderNode.pPrev;
  context->pRenderer = 0;
  context->NextCaptureCalledInFrame = 0;
}
