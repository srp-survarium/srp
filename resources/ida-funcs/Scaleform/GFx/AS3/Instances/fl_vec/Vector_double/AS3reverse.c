void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::AS3reverse(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *result)
{
  signed int v2; // eax
  signed int i; // esi
  long double *Data; // edx
  long double v5; // st7
  long double v6; // st6

  v2 = this->V.ValueA.Data.Size - 1;
  for ( i = 0; i < v2; Data[v2 + 1] = v5 )
  {
    Data = this->V.ValueA.Data.Data;
    v5 = Data[i++];
    v6 = Data[v2--];
    Data[i - 1] = v6;
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
}
