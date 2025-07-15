void __thiscall Scaleform::GFx::DisplayObjectBase::SetMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix3x4<float> *m)
{
  unsigned __int8 *pIndXFormData; // eax
  Scaleform::Render::TreeNode *v4; // eax
  Scaleform::Render::TreeNode *RenderNode; // eax

  pIndXFormData = (unsigned __int8 *)this->pIndXFormData;
  if ( pIndXFormData )
  {
    memcpy(pIndXFormData, (unsigned __int8 *)m, 0x30u);
    this->pIndXFormData->IsOrig3D = 1;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::ContextImpl::Entry::getWritableData(RenderNode, 1u);
  }
  else
  {
    v4 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetMatrix3D(v4, m);
  }
  Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(this);
}
