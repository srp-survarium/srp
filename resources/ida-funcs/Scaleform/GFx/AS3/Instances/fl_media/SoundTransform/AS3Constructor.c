void __thiscall Scaleform::GFx::AS3::Instances::fl_media::SoundTransform::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Value *v5; // edi

  v3 = argc;
  if ( argc )
  {
    v5 = argv;
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->Volume);
    if ( v3 >= 2 )
      Scaleform::GFx::AS3::Value::Convert2Number(v5 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->Pan);
  }
}
