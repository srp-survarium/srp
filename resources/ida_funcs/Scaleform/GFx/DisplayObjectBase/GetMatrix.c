const Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::GFx::DisplayObjectBase::GetMatrix(
        Scaleform::GFx::DisplayObjectBase *this)
{
  const Scaleform::Render::Matrix2x4<float> *result; // eax
  Scaleform::Render::TreeNode *pObject; // eax

  result = (const Scaleform::Render::Matrix2x4<float> *)this->pIndXFormData;
  if ( !result )
  {
    pObject = this->pRenNode.pObject;
    if ( pObject )
      return (const Scaleform::Render::Matrix2x4<float> *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000)
                                                                                 + 0x10)
                                                                     + 4
                                                                     * ((int)((int)&pObject[-1]
                                                                            - ((unsigned int)pObject & 0xFFFFF000))
                                                                      / 28)
                                                                     + 20)
                                                         + 16);
    else
      return &Scaleform::Render::Matrix2x4<float>::Identity;
  }
  return result;
}
