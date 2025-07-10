void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Value *v4; // edi

  v3 = argc;
  v4 = argv;
  if ( (!argc
     || Scaleform::GFx::AS3::Value::Convert2UInt32(
          argv,
          (Scaleform::GFx::AS3::CheckResult *)&argc,
          (Scaleform::GFx::AS3::Value::V1U *)&argv)->Result
     && Scaleform::GFx::AS3::VectorBase<long>::Resize(
          (Scaleform::GFx::AS3::VectorBase<long> *)&this->V,
          (Scaleform::GFx::AS3::CheckResult *)&argc,
          (unsigned int)argv)->Result)
    && v3 > 1 )
  {
    this->V.Fixed = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 1);
  }
}
