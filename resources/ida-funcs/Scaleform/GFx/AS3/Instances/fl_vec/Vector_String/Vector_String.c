void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Vector_String(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::VM *pVM; // eax
  const Scaleform::MemoryHeap *MHeap; // ecx

  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, t);
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_vtbl *)&Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::`vftable';
  pVM = t->pVM;
  MHeap = pVM->MHeap;
  this->V.VMRef = pVM;
  this->V.Fixed = 0;
  this->V.__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >_vtbl *)&Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::`vftable';
  this->V.ValueA.Data.Data = 0;
  this->V.ValueA.Data.Size = 0;
  this->V.ValueA.Data.Policy.Capacity = 0;
  this->V.ValueA.Data.pHeap = MHeap;
}
