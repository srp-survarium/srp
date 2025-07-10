void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  if ( argc )
  {
    if ( Scaleform::GFx::AS3::Value::Convert2Boolean(argv) )
      this->WeakKeys = 1;
  }
}
