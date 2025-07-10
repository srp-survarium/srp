void __thiscall Scaleform::GFx::GFxInitImportActions::ExecuteInContext(
        Scaleform::GFx::GFxInitImportActions *this,
        Scaleform::GFx::DisplayObjContainer *m,
        Scaleform::GFx::MovieDefImpl *pbindDef,
        bool recursiveCheck)
{
  unsigned int ImportIndex; // ebx
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // esi
  Scaleform::GFx::MovieDefImpl *v6; // esi
  _RTL_CRITICAL_SECTION *p_cs; // [esp-4h] [ebp-10h]

  ImportIndex = this->ImportIndex;
  pObject = pbindDef->pBindData.pObject;
  EnterCriticalSection(&pObject->ImportSourceLock.cs);
  p_cs = &pObject->ImportSourceLock.cs;
  if ( ImportIndex < pObject->ImportSourceMovies.Data.Size )
  {
    v6 = pObject->ImportSourceMovies.Data.Data[ImportIndex].pObject;
    LeaveCriticalSection(p_cs);
    if ( v6
      && v6->pBindData.pObject->pDataDef.pObject->pData.pObject->InitActionsCnt > 0
      && (!recursiveCheck || v6 != m->GetResourceMovieDef(m)) )
    {
      m->ExecuteImportedInitActions(m, v6);
    }
  }
  else
  {
    LeaveCriticalSection(p_cs);
  }
}
