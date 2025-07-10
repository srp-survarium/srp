const Scaleform::GFx::ExporterInfo *__thiscall Scaleform::GFx::MovieDefImpl::GetExporterInfo(
        Scaleform::GFx::MovieDefImpl *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx

  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  return pObject->Header.mExporterInfo.SI.Format != File_Unopened
       ? (const Scaleform::GFx::ExporterInfo *)&pObject->Header.mExporterInfo
       : 0;
}
