Scaleform::GFx::AS3ValueObjectInterface *__thiscall Scaleform::GFx::Value::ObjectInterface::`scalar deleting destructor'(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3ValueObjectInterface_vtbl *)&Scaleform::GFx::Value::ObjectInterface::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
