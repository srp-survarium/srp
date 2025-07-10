void __thiscall Scaleform::GFx::DisplayObjectBase::SetCxform(
        Scaleform::GFx::DisplayObjectBase *this,
        const Scaleform::Render::Cxform *cx)
{
  Scaleform::Render::TreeNode *RenderNode; // eax

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  qmemcpy(&Scaleform::Render::ContextImpl::Entry::getWritableData(RenderNode, 2u)[10], cx, 0x20u);
}
