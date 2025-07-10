void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::XMLProcInstr(
        Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        const Scaleform::GFx::ASString *n,
        const Scaleform::GFx::ASString *v,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v7; // eax

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLProcInstr_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
  pNode = n->pNode;
  this->Text = (Scaleform::GFx::ASString)n->pNode;
  ++pNode->RefCount;
  this->Parent.pObject = p;
  if ( p )
    p->RefCount = (p->RefCount + 1) & 0x8FBFFFFF;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLProcInstr_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::`vftable';
  v7 = v->pNode;
  this->Data = (Scaleform::GFx::ASString)v->pNode;
  ++v7->RefCount;
}
