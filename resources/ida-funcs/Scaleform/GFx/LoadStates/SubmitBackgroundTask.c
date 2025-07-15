bool __thiscall Scaleform::GFx::LoadStates::SubmitBackgroundTask(
        Scaleform::GFx::LoadStates *this,
        Scaleform::GFx::LoaderTask *ptask)
{
  Scaleform::GFx::TaskManager *pObject; // ecx

  pObject = this->pTaskManager.pObject;
  return pObject && pObject->AddTask(pObject, ptask);
}
