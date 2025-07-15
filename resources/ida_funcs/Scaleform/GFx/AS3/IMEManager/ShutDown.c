void __thiscall Scaleform::GFx::AS3::IMEManager::ShutDown(Scaleform::GFx::AS3::IMEManager *this)
{
  Scaleform::GFx::Value *p_CandListVal; // esi

  p_CandListVal = &this->CandListVal;
  if ( (this->CandListVal.Type & 0x40) != 0 )
  {
    ((void (__stdcall *)(Scaleform::GFx::Value *, int))this->CandListVal.pObjectInterface->ObjectRelease)(
      &this->CandListVal,
      this->CandListVal.mValue.IValue);
    p_CandListVal->pObjectInterface = 0;
    p_CandListVal->Type = VT_Undefined;
    this->pMovie = 0;
  }
  else
  {
    this->CandListVal.Type = VT_Undefined;
    this->pMovie = 0;
  }
}
