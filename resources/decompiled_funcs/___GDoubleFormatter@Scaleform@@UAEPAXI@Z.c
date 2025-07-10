Scaleform::DoubleFormatter *__thiscall Scaleform::DoubleFormatter::`scalar deleting destructor'(
        Scaleform::DoubleFormatter *this,
        char a2)
{
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::DoubleFormatter_vtbl *)&Scaleform::FmtResource::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
