void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLDocument::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLDocument *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *v3; // eax
  Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *v4; // esi

  v3 = (Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::XMLNode(v3, t);
    v4->__vftable = (Scaleform::GFx::AS3::Instances::fl_xml::XMLNode_vtbl *)&Scaleform::GFx::AS3::Instances::fl_xml::XMLDocument::`vftable';
    v4[1].__vftable = 0;
    v4[1].pRCCRaw = 0;
    LOBYTE(v4[1].pNext) = 0;
    v4[1].pPrev = 0;
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
