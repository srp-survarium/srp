Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *t)
{
  Scaleform::GFx::AS3::Instances::fl::Catch *v2; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v3; // esi
  Scaleform::GFx::AS3::VM *pVM; // eax
  const Scaleform::MemoryHeap *MHeap; // ecx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *v6; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v2, t);
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double_vtbl *)&Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::`vftable';
    pVM = t->pVM;
    MHeap = pVM->MHeap;
    v3->V.Fixed = 0;
    v3->V.VMRef = pVM;
    v6 = result;
    v3->V.__vftable = (Scaleform::GFx::AS3::VectorBase<double>_vtbl *)&Scaleform::GFx::AS3::VectorBase<double>::`vftable';
    v3->V.ValueA.Data.Data = 0;
    v3->V.ValueA.Data.Size = 0;
    v3->V.ValueA.Data.Policy.Capacity = 0;
    v3->V.ValueA.Data.pHeap = MHeap;
    result->pV = v3;
  }
  else
  {
    v6 = result;
    result->pV = 0;
  }
  return v6;
}
