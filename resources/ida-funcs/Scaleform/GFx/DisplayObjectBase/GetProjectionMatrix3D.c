bool __thiscall Scaleform::GFx::DisplayObjectBase::GetProjectionMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix4x4<float> *m,
        BOOL bInherit)
{
  Scaleform::Render::TreeNode *pObject; // ecx

  pObject = this->pRenNode.pObject;
  if ( pObject && Scaleform::Render::TreeNode::GetProjectionMatrix3D(pObject, m) )
    return 1;
  if ( bInherit && this->pParent )
    return this->pParent->GetProjectionMatrix3D(this->pParent, m, bInherit);
  return 0;
}
