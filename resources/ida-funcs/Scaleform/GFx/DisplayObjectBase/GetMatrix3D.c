Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *__thiscall Scaleform::GFx::DisplayObjectBase::GetMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *result; // eax
  Scaleform::Render::TreeNode *pObject; // eax

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
