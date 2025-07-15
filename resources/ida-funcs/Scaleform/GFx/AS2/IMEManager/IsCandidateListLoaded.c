char __thiscall Scaleform::GFx::AS2::IMEManager::IsCandidateListLoaded(Scaleform::GFx::AS2::IMEManager *this)
{
  char v1; // bl
  Scaleform::GFx::Movie *pMovie; // ecx
  Scaleform::GFx::AS2::MovieRoot *pObject; // esi
  Scaleform::GFx::Value v; // [esp+8h] [ebp-18h] BYREF

  v1 = 0;
  if ( !this->pMovie )
    return 0;
  pMovie = this->pMovie;
  v.pObjectInterface = 0;
  v.Type = VT_Undefined;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)pMovie->pASMovieRoot.pObject;
  if ( !(unsigned __int8)Scaleform::GFx::Movie::GetVariable(pMovie, &v, "_global.gfx_ime_candidate_list_state") )
  {
    if ( (v.Type & 0x40) != 0 )
    {
      v.pObjectInterface->ObjectRelease(v.pObjectInterface, &v, (void *)v.mValue.IValue);
      v.pObjectInterface = 0;
    }
    v.Type = VT_Number;
    v.mValue.NValue = 0.0;
  }
  if ( Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 9999) && 2.0 == v.mValue.NValue )
    v1 = 1;
  if ( (v.Type & 0x40) != 0 )
    v.pObjectInterface->ObjectRelease(v.pObjectInterface, &v, (void *)v.mValue.IValue);
  return v1;
}
