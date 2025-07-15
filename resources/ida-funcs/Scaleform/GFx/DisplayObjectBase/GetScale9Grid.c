Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::DisplayObjectBase::GetScale9Grid(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::TreeNode *RenderNode; // eax

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::GetScale9Grid(RenderNode, result);
  return result;
}
