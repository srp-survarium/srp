const Scaleform::GFx::Value *__thiscall Scaleform::GFx::Value::operator=(
        Scaleform::GFx::Value *this,
        const Scaleform::GFx::Value *src)
{
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // ecx
  int IValue; // eax

  if ( this != src )
  {
    if ( (this->Type & 0x40) != 0 )
    {
      ((void (__stdcall *)(Scaleform::GFx::Value *, int))this->pObjectInterface->ObjectRelease)(
        this,
        this->mValue.IValue);
      this->pObjectInterface = 0;
    }
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
  return this;
}
