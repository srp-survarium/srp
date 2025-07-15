bool __thiscall Scaleform::GFx::DisplayObjectBase::GetViewMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix3x4<float> *m,
        BOOL bInherit)
{
  Scaleform::Render::TreeNode *pObject; // eax

  pObject = this->pRenNode.pObject;
  if ( pObject
    && (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&pObject[-1] - ((unsigned int)pObject & 0xFFFFF000)) / 28)
                             + 20)
                 + 6)
      & 0x800) != 0 )
  {
    memcpy((int)m, (const __m128i *)&this->pPerspectiveData->ViewMatrix3D, sizeof(Scaleform::Render::Matrix3x4<float>));
    return 1;
  }
  else
  {
    return bInherit && this->pParent && this->pParent->GetViewMatrix3D(this->pParent, m, bInherit);
  }
}
