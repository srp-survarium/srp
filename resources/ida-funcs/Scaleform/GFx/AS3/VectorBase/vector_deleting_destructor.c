Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *__thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::`vector deleting destructor'(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        char a2)
{
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(this->ValueA.Data.Data, this->ValueA.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->ValueA.Data.Data);
  this->__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>_vtbl *)&Scaleform::GFx::AS3::ArrayBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
