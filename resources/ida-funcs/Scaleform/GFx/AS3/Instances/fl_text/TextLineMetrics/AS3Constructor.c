void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextLineMetrics::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_text::TextLineMetrics *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Value *v5; // edi

  v3 = argc;
  if ( argc )
  {
    v5 = argv;
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->ascent);
    if ( v3 >= 2 )
      Scaleform::GFx::AS3::Value::Convert2Number(v5 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->descent);
    if ( v3 >= 3 )
      Scaleform::GFx::AS3::Value::Convert2Number(v5 + 2, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->height);
    if ( v3 >= 4 )
      Scaleform::GFx::AS3::Value::Convert2Number(v5 + 3, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->leading);
    if ( v3 >= 5 )
      Scaleform::GFx::AS3::Value::Convert2Number(v5 + 4, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->width);
    if ( v3 >= 6 )
      Scaleform::GFx::AS3::Value::Convert2Number(v5 + 5, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->x);
  }
}
