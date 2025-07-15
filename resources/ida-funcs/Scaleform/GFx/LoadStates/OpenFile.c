Scaleform::File *__thiscall Scaleform::GFx::LoadStates::OpenFile(
        Scaleform::GFx::LoadStates *this,
        const char *pfilename,
        unsigned int loadConstants)
{
  Scaleform::GFx::LogState *v4; // esi
  Scaleform::Log *pObject; // eax

  if ( this->pBindStates.pObject->pFileOpener.pObject )
  {
    if ( ((unsigned int)&loc_200000 & loadConstants) != 0 )
    {
      pObject = 0;
    }
    else
    {
      pObject = this->pLog.pObject->pLog.pObject;
      if ( !pObject )
        pObject = Scaleform::Log::GetGlobalLog();
    }
    return this->pBindStates.pObject->pFileOpener.pObject->OpenFileEx(
             this->pBindStates.pObject->pFileOpener.pObject,
             pfilename,
             pObject,
             33,
             438);
  }
  else
  {
    v4 = this->pLog.pObject;
    if ( v4 )
    {
      if ( ((unsigned int)&loc_200000 & loadConstants) == 0 )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &v4->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "Loader failed to open '%s', FileOpener not installe",
          pfilename);
    }
    return 0;
  }
}
