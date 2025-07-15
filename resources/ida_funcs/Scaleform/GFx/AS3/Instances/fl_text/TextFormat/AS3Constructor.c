void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextFormat::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_text::TextFormat *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS2::Object::SetValue((Scaleform::GFx::AS3::Instances::fl_geom::Transform *)this, argc, argv);
  if ( argc )
    Scaleform::GFx::AS3::Value::Assign(&this->mFont, argv);
  if ( argc >= 2 )
    Scaleform::GFx::AS3::Value::Assign(&this->mSize, argv + 1);
  if ( argc >= 3 )
    Scaleform::GFx::AS3::Value::Assign(&this->mColor, argv + 2);
  if ( argc >= 4 )
    Scaleform::GFx::AS3::Value::Assign(&this->mBold, argv + 3);
  if ( argc >= 5 )
    Scaleform::GFx::AS3::Value::Assign(&this->mItalic, argv + 4);
  if ( argc >= 6 )
    Scaleform::GFx::AS3::Value::Assign(&this->mUnderline, argv + 5);
  if ( argc >= 7 )
    Scaleform::GFx::AS3::Value::Assign(&this->mUrl, argv + 6);
  if ( argc >= 8 )
    Scaleform::GFx::AS3::Value::Assign(&this->mTarget, argv + 7);
  if ( argc >= 9 )
    Scaleform::GFx::AS3::Value::Assign(&this->mAlign, argv + 8);
  if ( argc >= 0xA )
    Scaleform::GFx::AS3::Value::Assign(&this->mLeftMargin, argv + 9);
  if ( argc >= 0xB )
    Scaleform::GFx::AS3::Value::Assign(&this->mRightMargin, argv + 10);
  if ( argc >= 0xC )
    Scaleform::GFx::AS3::Value::Assign(&this->mIndent, argv + 11);
  if ( argc >= 0xD )
    Scaleform::GFx::AS3::Value::Assign(&this->mLeading, argv + 12);
}
