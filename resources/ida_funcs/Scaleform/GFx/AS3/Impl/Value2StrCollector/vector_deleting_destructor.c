Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector *__thiscall Scaleform::GFx::AS3::Impl::Value2StrCollector::`vector deleting destructor'(
        Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
