char __thiscall Scaleform::GFx::AS3::IMEManager::IsCandidateListLoaded(Scaleform::GFx::AS3::IMEManager *this)
{
  Scaleform::GFx::Movie *pMovie; // ecx
  Scaleform::GFx::Value v; // [esp+8h] [ebp-18h] BYREF

  pMovie = this->pMovie;
  if ( !pMovie )
    return 0;
  v.pObjectInterface = 0;
  v.Type = VT_Undefined;
  if ( !Scaleform::GFx::Movie::GetVariable(pMovie, &v, "_global.gfx_ime_candidate_list_state") )
  {
    if ( (v.Type & 0x40) != 0 )
    {
      v.pObjectInterface->ObjectRelease(v.pObjectInterface, &v, (void *)v.mValue.IValue);
      v.pObjectInterface = 0;
    }
    v.Type = VT_Number;
    v.mValue.NValue = 0.0;
  }
  if ( (v.Type & 0x40) != 0 )
    v.pObjectInterface->ObjectRelease(v.pObjectInterface, &v, (void *)v.mValue.IValue);
  return 1;
}
