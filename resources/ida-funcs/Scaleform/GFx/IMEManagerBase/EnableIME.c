void __thiscall Scaleform::GFx::IMEManagerBase::EnableIME(Scaleform::GFx::IMEManagerBase *this, BOOL enable)
{
  bool IMEDisabled; // al

  IMEDisabled = this->IMEDisabled;
  if ( IMEDisabled == enable )
  {
    this->IMEDisabled = !IMEDisabled;
    this->OnEnableIME(this, enable);
  }
}
