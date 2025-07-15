void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::AS3pop(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this,
        long double *result)
{
  Scaleform::GFx::AS3::VectorBase<double> *p_V; // esi
  Scaleform::GFx::AS3::CheckResult v3; // [esp+7h] [ebp-1h] BYREF

  p_V = &this->V;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(&this->V, &v3)->Result )
  {
    if ( p_V->ValueA.Data.Size )
      *result = Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::Pop(&p_V->ValueA);
  }
}
