void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Value *v5; // edi

  v3 = argc;
  if ( argc )
  {
    v5 = argv;
    if ( Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->x)->Result
      && v3 > 1
      && Scaleform::GFx::AS3::Value::Convert2Number(v5 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->y)->Result
      && v3 > 2
      && Scaleform::GFx::AS3::Value::Convert2Number(v5 + 2, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->z)->Result
      && v3 > 3 )
    {
      Scaleform::GFx::AS3::Value::Convert2Number(v5 + 3, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->w);
    }
  }
}
