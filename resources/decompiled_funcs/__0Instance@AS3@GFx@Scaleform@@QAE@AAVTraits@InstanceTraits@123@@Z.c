void __thiscall Scaleform::GFx::AS3::Instance::Instance(
        Scaleform::GFx::AS3::Instance *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  this->pRCCRaw = (unsigned int)t->pVM->GC.GC;
  this->__vftable = (Scaleform::GFx::AS3::Instance_vtbl *)&Scaleform::GFx::AS3::Object::`vftable';
  this->RefCount = 1;
  this->pTraits.pObject = t;
  t->RefCount = (t->RefCount + 1) & 0x8FBFFFFF;
  this->DynAttrs.mHash.pTable = 0;
  this->pUserDataHolder = 0;
  this->__vftable = (Scaleform::GFx::AS3::Instance_vtbl *)&Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle::`vftable';
  Scaleform::GFx::AS3::Traits::ConstructTail(t, this);
}
