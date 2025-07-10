void __thiscall Scaleform::GFx::DisplayObjectBase::SetScale9Grid(
        Scaleform::GFx::DisplayObjectBase *this,
        const Scaleform::Render::Rect<float> *gr)
{
  Scaleform::Render::TreeNode *RenderNode; // eax

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::SetScale9Grid(RenderNode, (int)gr);
}
