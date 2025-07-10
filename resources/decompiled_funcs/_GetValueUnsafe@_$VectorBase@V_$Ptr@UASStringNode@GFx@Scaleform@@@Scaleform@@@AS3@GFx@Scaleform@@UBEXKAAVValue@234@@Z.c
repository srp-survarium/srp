void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::GetValueUnsafe(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::AssignUnsafe(v, this->ValueA.Data.Data[ind].pObject);
}
