void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::AS3forEach(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *eacher,
        Scaleform::GFx::AS3::Value *thisObj)
{
  Scaleform::GFx::AS3::ArrayBase::ForEach(&this->V, eacher, thisObj, this);
}
