void __thiscall Scaleform::GFx::AS2::Value::~Value(Scaleform::GFx::AS2::Value *this)
{
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
}
