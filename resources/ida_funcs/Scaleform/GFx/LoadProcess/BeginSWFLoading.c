char __thiscall Scaleform::GFx::LoadProcess::BeginSWFLoading(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::Resource *pfile)
{
  char result; // al

  result = Scaleform::GFx::SWFProcessInfo::Initialize(
             &this->ProcessInfo,
             pfile,
             this->pLoadStates.pObject->pLog.pObject,
             this->pLoadStates.pObject->pZlibSupport.pObject,
             this->pLoadStates.pObject->pParseControl.pObject,
             1);
  if ( result )
  {
    this->pLoadData.pObject->FileAttributes = this->ProcessInfo.FileAttributes;
    Scaleform::GFx::MovieDataDef::LoadTaskData::BeginSWFLoading(this->pLoadData.pObject, &this->ProcessInfo.Header);
    return 1;
  }
  return result;
}
