void __thiscall Scaleform::GFx::DisplayObjectBase::SetBlendMode(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::BlendMode blend)
{
  Scaleform::Render::TreeNode *RenderNode; // eax

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::SetBlendMode(RenderNode, blend != Blend_Normal ? blend : Blend_None);
  this->BlendMode = blend;
}
