void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::GetValue(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::Assign(v, this->ValueA.Data.Data[ind].pObject);
}
