void __thiscall Scaleform::GFx::AS3::Value::Value(
        Scaleform::GFx::AS3::Value *this,
        const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v)
{
  this->Flags = 0;
  this->Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Value::AssignUnsafe(this, v->pObject);
}
