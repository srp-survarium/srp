void __thiscall Scaleform::GFx::AS3::Classes::fl::Boolean::Construct(
        Scaleform::GFx::AS3::Classes::fl::Boolean *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool __formal)
{
  bool v5; // al

  if ( argc )
  {
    v5 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
    Scaleform::GFx::AS3::Value::SetBool(result, v5);
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetBool(result, 0);
  }
}
