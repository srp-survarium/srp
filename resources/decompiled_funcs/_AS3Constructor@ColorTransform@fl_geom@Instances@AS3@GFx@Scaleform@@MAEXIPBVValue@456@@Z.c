void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Value *v5; // edi

  v3 = argc;
  if ( argc )
  {
    v5 = argv;
    if ( Scaleform::GFx::AS3::Value::Convert2Number(
           argv,
           (Scaleform::GFx::AS3::CheckResult *)&argc,
           &this->redMultiplier)->Result
      && v3 > 1
      && Scaleform::GFx::AS3::Value::Convert2Number(
           v5 + 1,
           (Scaleform::GFx::AS3::CheckResult *)&argc,
           &this->greenMultiplier)->Result
      && v3 > 2
      && Scaleform::GFx::AS3::Value::Convert2Number(
           v5 + 2,
           (Scaleform::GFx::AS3::CheckResult *)&argc,
           &this->blueMultiplier)->Result
      && v3 > 3
      && Scaleform::GFx::AS3::Value::Convert2Number(
           v5 + 3,
           (Scaleform::GFx::AS3::CheckResult *)&argc,
           &this->alphaMultiplier)->Result
      && v3 > 4
      && Scaleform::GFx::AS3::Value::Convert2Number(v5 + 4, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->redOffset)->Result
      && v3 > 5
      && Scaleform::GFx::AS3::Value::Convert2Number(
           v5 + 5,
           (Scaleform::GFx::AS3::CheckResult *)&argc,
           &this->greenOffset)->Result
      && v3 > 6
      && Scaleform::GFx::AS3::Value::Convert2Number(
           v5 + 6,
           (Scaleform::GFx::AS3::CheckResult *)&argc,
           &this->blueOffset)->Result
      && v3 > 7 )
    {
      Scaleform::GFx::AS3::Value::Convert2Number(v5 + 7, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->alphaOffset);
    }
  }
}
