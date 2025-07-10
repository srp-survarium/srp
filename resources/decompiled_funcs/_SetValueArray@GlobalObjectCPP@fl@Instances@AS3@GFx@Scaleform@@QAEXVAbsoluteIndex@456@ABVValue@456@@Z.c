void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::SetValueArray(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        const Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::Assign(&this->Values.Data.Data[ind.Index], v);
}
