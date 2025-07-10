void __thiscall Scaleform::GFx::Value::Value(Scaleform::GFx::Value *this, const Scaleform::GFx::Value *src)
{
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // eax
  int IValue; // ecx

  this->pObjectInterface = 0;
  this->Type = src->Type;
  this->mValue.NValue = src->mValue.NValue;
  this->DataAux = src->DataAux;
  if ( (src->Type & 0x40) != 0 )
  {
    pObjectInterface = src->pObjectInterface;
    IValue = this->mValue.IValue;
    this->pObjectInterface = src->pObjectInterface;
    pObjectInterface->ObjectAddRef(pObjectInterface, this, (void *)IValue);
  }
}
