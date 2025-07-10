double __thiscall Scaleform::GFx::MovieDefImpl::GetWidth(Scaleform::GFx::MovieDefImpl *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // eax
  float v3; // [esp+8h] [ebp-4h]
  float v4; // [esp+8h] [ebp-4h]

  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v3 = pObject->Header.FrameRect.x2 - pObject->Header.FrameRect.x1;
  v4 = v3 * 0.05000000074505806;
  return (float)ceil(v4);
}
