void __thiscall Scaleform::GFx::Value::~Value(Scaleform::GFx::Value *this)
{
  if ( (this->Type & 0x40) != 0 )
  {
    ((void (__stdcall *)(Scaleform::GFx::Value *, int))this->pObjectInterface->ObjectRelease)(this, this->mValue.IValue);
    this->pObjectInterface = 0;
  }
  this->Type = VT_Undefined;
}
