Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::Value::`scalar deleting destructor'(
        Scaleform::GFx::AS2::Value *this,
        char a2)
{
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
