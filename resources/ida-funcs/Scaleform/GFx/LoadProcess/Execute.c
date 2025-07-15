void __thiscall Scaleform::GFx::LoadProcess::Execute(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData::Read(this->pLoadData.pObject, this, this->pBindProcess.pObject);
}
