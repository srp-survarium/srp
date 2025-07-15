char __thiscall Scaleform::GFx::AS2::IMEManager::IsCandidateListLoaded(Scaleform::GFx::AS2::IMEManager *this)
{
  char v1; // bl
  Scaleform::GFx::Movie *pMovie; // ecx
  Scaleform::GFx::AS2::MovieRoot *pObject; // esi
  Scaleform::GFx::Value pval; // [esp+8h] [ebp-18h] BYREF

  v1 = 0;
  if ( !this->pMovie )
    return 0;
  pMovie = this->pMovie;
  pval.pObjectInterface = 0;
  pval.Type = VT_Undefined;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)pMovie->pASMovieRoot.pObject;
  if ( !Scaleform::GFx::Movie::GetVariable(pMovie, &pval, "_global.gfx_ime_candidate_list_state") )
  {
    if ( (pval.Type & 0x40) != 0 )
    {
      pval.pObjectInterface->ObjectRelease(pval.pObjectInterface, &pval, (void *)pval.mValue.IValue);
      pval.pObjectInterface = 0;
    }
    pval.Type = VT_Number;
    pval.mValue.NValue = 0.0;
  }
  if ( Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 9999) && 2.0 == pval.mValue.NValue )
    v1 = 1;
  if ( (pval.Type & 0x40) != 0 )
    pval.pObjectInterface->ObjectRelease(pval.pObjectInterface, &pval, (void *)pval.mValue.IValue);
  return v1;
}
