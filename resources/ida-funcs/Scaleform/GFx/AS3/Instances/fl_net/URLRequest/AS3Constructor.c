void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLRequest::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->Url);
}
