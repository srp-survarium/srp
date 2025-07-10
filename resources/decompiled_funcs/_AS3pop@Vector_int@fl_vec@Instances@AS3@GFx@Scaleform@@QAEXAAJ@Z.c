void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::AS3pop(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        unsigned int *result)
{
  Scaleform::GFx::AS3::VectorBase<unsigned long> *p_V; // esi
  Scaleform::GFx::AS3::CheckResult v3; // [esp+7h] [ebp-1h] BYREF

  p_V = &this->V;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(&this->V, &v3)->Result )
  {
    if ( p_V->ValueA.Data.Size )
      *result = Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::Pop(&p_V->ValueA);
  }
}
