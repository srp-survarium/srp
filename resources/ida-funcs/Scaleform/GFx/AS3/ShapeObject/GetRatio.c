double __thiscall Scaleform::GFx::AS3::ShapeObject::GetRatio(Scaleform::GFx::AS3::ShapeObject *this)
{
  Scaleform::Render::TreeNode *pObject; // ecx

  pObject = this->pRenNode.pObject;
  if ( pObject
    && *(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                            + 4 * ((int)((int)&pObject[-1] - ((unsigned int)pObject & 0xFFFFF000)) / 28)
                            + 20)
                + 4) == 3 )
  {
    return *(float *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                                + 4 * ((int)((int)&pObject[-1] - ((unsigned int)pObject & 0xFFFFF000)) / 28)
                                + 20)
                    + 148);
  }
  else
  {
    return 0.0;
  }
}
