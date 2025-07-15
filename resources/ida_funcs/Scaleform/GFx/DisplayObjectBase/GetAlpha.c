double __thiscall Scaleform::GFx::DisplayObjectBase::GetAlpha(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *pObject; // eax

  pObject = this->pRenNode.pObject;
  if ( pObject )
    return *(float *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                                + 4 * ((int)((int)&pObject[-1] - ((unsigned int)pObject & 0xFFFFF000)) / 28)
                                + 20)
                    + 92)
         * 100.0;
  else
    return Scaleform::Render::Cxform::Identity.M[0][3] * 100.0;
}
