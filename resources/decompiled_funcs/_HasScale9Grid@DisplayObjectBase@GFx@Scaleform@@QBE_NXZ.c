BOOL __thiscall Scaleform::GFx::DisplayObjectBase::HasScale9Grid(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::Rect<float> result; // [esp+0h] [ebp-10h] BYREF

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::GetScale9Grid(RenderNode, &result);
  return result.x2 > (double)result.x1 && result.y2 > (double)result.y1;
}
