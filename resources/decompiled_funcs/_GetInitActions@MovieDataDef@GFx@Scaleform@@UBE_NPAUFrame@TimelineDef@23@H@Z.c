char __thiscall Scaleform::GFx::MovieDataDef::GetInitActions(
        Scaleform::GFx::MovieDataDef *this,
        Scaleform::GFx::TimelineDef::Frame *pframe,
        unsigned int frame)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // esi
  _RTL_CRITICAL_SECTION *p_cs; // [esp-4h] [ebp-Ch]

  pObject = this->pData.pObject;
  EnterCriticalSection(&pObject->PlaylistLock.cs);
  p_cs = &pObject->PlaylistLock.cs;
  if ( frame < pObject->InitActionList.Data.Size )
  {
    *pframe = pObject->InitActionList.Data.Data[frame];
    LeaveCriticalSection(p_cs);
    return 1;
  }
  else
  {
    LeaveCriticalSection(p_cs);
    return 0;
  }
}
