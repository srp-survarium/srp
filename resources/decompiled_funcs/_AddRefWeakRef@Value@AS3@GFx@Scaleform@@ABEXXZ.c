void __thiscall Scaleform::GFx::AS3::Value::AddRefWeakRef(Scaleform::GFx::AS3::Value *this)
{
  ++this->Bonus.pWeakProxy->RefCount;
}
