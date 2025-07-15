void __thiscall Scaleform::GFx::GFxInitImportActions::Execute(
        Scaleform::GFx::GFxInitImportActions *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // esi
  unsigned int ImportIndex; // ebx
  Scaleform::GFx::MovieDef *v5; // ebx
  _RTL_CRITICAL_SECTION *p_cs; // [esp-4h] [ebp-14h]

  pObject = m->GetResourceMovieDef(m)->pBindData.pObject;
  ImportIndex = this->ImportIndex;
  EnterCriticalSection(&pObject->ImportSourceLock.cs);
  p_cs = &pObject->ImportSourceLock.cs;
  if ( ImportIndex < pObject->ImportSourceMovies.Data.Size )
  {
    v5 = pObject->ImportSourceMovies.Data.Data[ImportIndex].pObject;
    LeaveCriticalSection(p_cs);
    if ( v5 )
    {
      if ( *(int *)(*((_DWORD *)v5[1].GetStateAddRef + 8) + 300) > 0 )
        m->ExecuteImportedInitActions(m, v5);
    }
  }
  else
  {
    LeaveCriticalSection(p_cs);
  }
}
