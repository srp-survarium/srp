void __thiscall Scaleform::GFx::MovieDefImpl::WaitForFrame(Scaleform::GFx::MovieDefImpl *this, unsigned int frame)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData::WaitForFrame(
    this->pBindData.pObject->pDataDef.pObject->pData.pObject,
    frame);
}
