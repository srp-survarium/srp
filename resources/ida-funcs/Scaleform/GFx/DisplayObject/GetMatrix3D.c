Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *__thiscall Scaleform::GFx::DisplayObject::GetMatrix3D(
        Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // eax
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *result; // eax
  Scaleform::Render::TreeNode *pObject; // eax

  pScrollRect = this->pScrollRect;
  if ( pScrollRect )
    return (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)&pScrollRect->OrigTransformMatrix;
  result = this->pIndXFormData;
  if ( !result )
  {
    pObject = this->pRenNode.pObject;
    if ( pObject )
      return (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                                                                                        + 4
                                                                                        * ((int)((int)&pObject[-1]
                                                                                               - ((unsigned int)pObject
                                                                                                & 0xFFFFF000))
                                                                                         / 28)
                                                                                        + 20)
                                                                            + 16);
    else
      return (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)&Scaleform::Render::Matrix3x4<float>::Identity;
  }
  return result;
}
