void __thiscall Scaleform::GFx::Value::ReleaseManagedValue(Scaleform::GFx::Value *this)
{
  this->pObjectInterface->ObjectRelease(this->pObjectInterface, this, (void *)this->mValue.IValue);
  this->pObjectInterface = 0;
}
