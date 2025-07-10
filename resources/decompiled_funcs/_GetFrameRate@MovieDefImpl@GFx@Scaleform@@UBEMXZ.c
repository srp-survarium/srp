double __thiscall Scaleform::GFx::MovieDefImpl::GetFrameRate(Scaleform::GFx::MovieDefImpl *this)
{
  return this->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FPS;
}
