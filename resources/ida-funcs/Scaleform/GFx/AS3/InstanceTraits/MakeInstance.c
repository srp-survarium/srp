Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *__cdecl Scaleform::GFx::AS3::InstanceTraits::MakeInstance<Scaleform::GFx::AS3::InstanceTraits::fl::Array>(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::Array *t)
{
  Scaleform::GFx::AS3::Instance *v2; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v3; // esi
  Scaleform::MemoryHeap *MHeap; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *v5; // eax

  v2 = (Scaleform::GFx::AS3::Instance *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = (Scaleform::GFx::AS3::Instances::fl::Array *)v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v2, t);
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl::Array_vtbl *)&Scaleform::GFx::AS3::Instances::fl::Array::`vftable';
    MHeap = t->pVM->MHeap;
    v3->SA.Length = 0;
    v3->SA.ValueHLowInd = 0;
    v3->SA.ValueHHighInd = 0;
    v3->SA.DefaultValue.Flags = 0;
    v3->SA.DefaultValue.Bonus.pWeakProxy = 0;
    v3->SA.ValueA.Data.Data = 0;
    v3->SA.ValueA.Data.Size = 0;
    v3->SA.ValueA.Data.Policy.Capacity = 0;
    v3->SA.ValueA.Data.pHeap = MHeap;
    v3->SA.ValueH.mHash.pHeap = MHeap;
    v5 = result;
    v3->SA.ValueH.mHash.pTable = 0;
    result->pV = v3;
  }
  else
  {
    v5 = result;
    result->pV = 0;
  }
  return v5;
}
