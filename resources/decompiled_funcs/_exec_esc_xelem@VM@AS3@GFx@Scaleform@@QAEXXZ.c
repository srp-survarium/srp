void __thiscall Scaleform::GFx::AS3::VM::exec_esc_xelem(Scaleform::GFx::AS3::VM *this)
{
  char v1; // [esp+1h] [ebp-1h] BYREF

  v1 = HIBYTE(this);
  this->XMLSupport_.pObject->ToXMLString(
    this->XMLSupport_.pObject,
    (Scaleform::GFx::AS3::CheckResult *)&v1,
    this,
    this->OpStack.pCurrent);
}
