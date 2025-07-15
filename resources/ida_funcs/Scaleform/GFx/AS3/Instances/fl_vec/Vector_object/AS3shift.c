void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::AS3shift(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *p_V; // esi
  Scaleform::GFx::AS3::CheckResult v3; // [esp+7h] [ebp-1h] BYREF

  p_V = &this->V;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(&this->V, &v3)->Result )
  {
    if ( p_V->ValueA.Data.Size )
    {
      Scaleform::GFx::AS3::Value::Assign(result, p_V->ValueA.Data.Data);
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        &p_V->ValueA,
        0);
    }
  }
}
