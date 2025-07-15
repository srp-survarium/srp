void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instance *v3; // eax
  Scaleform::GFx::AS3::Object *v4; // esi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax

  v3 = (Scaleform::GFx::AS3::Instance *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v3, t);
    v4->__vftable = (Scaleform::GFx::AS3::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
    p_EmptyStringNode = &t->pVM->StringManagerRef->pStringManager->EmptyStringNode;
    v4[1].__vftable = (Scaleform::GFx::AS3::Object_vtbl *)p_EmptyStringNode;
    ++p_EmptyStringNode->RefCount;
    v4[1].pRCCRaw = 0;
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
