void __thiscall Scaleform::GFx::AS3::Value::Value(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Class *v)
{
  this->Flags = 13;
  this->Bonus.pWeakProxy = 0;
  this->value.VS._1.VInt = (int)v;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}
