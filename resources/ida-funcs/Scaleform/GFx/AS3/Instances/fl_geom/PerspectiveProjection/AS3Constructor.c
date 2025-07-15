void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // edi
  Scaleform::GFx::AS3::Value *v5; // esi
  long double v6; // st7
  long double tmp; // [esp+8h] [ebp-18h] BYREF
  long double x; // [esp+10h] [ebp-10h] BYREF
  long double y; // [esp+18h] [ebp-8h] BYREF

  v3 = argc;
  if ( argc )
  {
    v5 = argv;
    if ( Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &tmp)->Result )
    {
      if ( tmp != 0.0 )
        this->fieldOfView = tmp;
      if ( v3 > 1
        && Scaleform::GFx::AS3::Value::Convert2Number(v5 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &tmp)->Result )
      {
        if ( tmp != 0.0 )
          this->focalLength = tmp;
        if ( v3 > 2
          && Scaleform::GFx::AS3::Value::Convert2Number(v5 + 2, (Scaleform::GFx::AS3::CheckResult *)&argc, &x)->Result
          && Scaleform::GFx::AS3::Value::Convert2Number(v5 + 3, (Scaleform::GFx::AS3::CheckResult *)&argc, &y)->Result
          && x != 0.0 )
        {
          v6 = y;
          if ( y != 0.0 )
          {
            this->projectionCenter.x = x;
            this->projectionCenter.y = v6;
          }
        }
      }
    }
  }
}
