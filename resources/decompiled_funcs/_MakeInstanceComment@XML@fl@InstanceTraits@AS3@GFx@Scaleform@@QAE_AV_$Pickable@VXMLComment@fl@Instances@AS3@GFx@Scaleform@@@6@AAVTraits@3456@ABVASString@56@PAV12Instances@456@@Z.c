Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> *__thiscall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceComment(
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        const Scaleform::GFx::ASString *n,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::Instance *v5; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLComment *v6; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> *v8; // eax

  v5 = (Scaleform::GFx::AS3::Instance *)this->pVM->MHeap->Alloc(this->pVM->MHeap, 40, 0);
  v6 = (Scaleform::GFx::AS3::Instances::fl::XMLComment *)v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v5, t);
    v6->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLComment_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
    pNode = n->pNode;
    v6->Text = (Scaleform::GFx::ASString)n->pNode;
    ++pNode->RefCount;
    v6->Parent.pObject = p;
    if ( p )
      p->RefCount = (p->RefCount + 1) & 0x8FBFFFFF;
    v8 = result;
    v6->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLComment_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLComment::`vftable';
    result->pV = v6;
  }
  else
  {
    v8 = result;
    result->pV = 0;
  }
  return v8;
}
