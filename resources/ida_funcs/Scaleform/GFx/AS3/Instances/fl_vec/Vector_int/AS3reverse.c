void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::AS3reverse(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *result)
{
  signed int v2; // eax
  signed int i; // esi
  unsigned int *Data; // edx
  unsigned int v5; // edi

  v2 = this->V.ValueA.Data.Size - 1;
  for ( i = 0; i < v2; --v2 )
  {
    Data = this->V.ValueA.Data.Data;
    v5 = Data[i];
    Data[i] = Data[v2];
    Data[v2] = v5;
    ++i;
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
}
