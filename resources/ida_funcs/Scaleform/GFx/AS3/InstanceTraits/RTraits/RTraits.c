void __thiscall Scaleform::GFx::AS3::InstanceTraits::RTraits::RTraits(
        Scaleform::GFx::AS3::InstanceTraits::RTraits *this,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::ASString *n,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> ns,
        const Scaleform::GFx::AS3::InstanceTraits::Traits *pt,
        bool isDynamic,
        bool isFinal)
{
  Scaleform::GFx::ASStringNode *pNode; // eax

  Scaleform::GFx::AS3::Traits::Traits(this, vm, pt, isDynamic, isFinal);
  this->Ns.pObject = ns.pV;
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::RTraits_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::RTraits::`vftable';
  pNode = n->pNode;
  this->Name = (Scaleform::GFx::ASString)n->pNode;
  ++pNode->RefCount;
}
