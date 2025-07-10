Scaleform::GFx::AS3::VectorBase<double> *__thiscall Scaleform::GFx::AS3::VectorBase<long>::`scalar deleting destructor'(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        char a2)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->ValueA.Data.Data);
  this->__vftable = (Scaleform::GFx::AS3::VectorBase<double>_vtbl *)&Scaleform::GFx::AS3::ArrayBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
