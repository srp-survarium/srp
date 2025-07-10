void __thiscall Scaleform::GFx::AS3::Traits::Add2StoredScopeStack(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::Value *o)
{
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->InitScope.Data,
    o);
}
