bool __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::HasOwnProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        const Scaleform::GFx::ASString *p)
{
  int v4; // eax
  bool v5; // bl
  Scaleform::GFx::AS3::Instances::fl::EmptyCallBack cb; // [esp+4h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+Ch] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+1Ch] [ebp-18h] BYREF

  if ( !p->pNode->Size )
    return 0;
  cb.Element = this;
  cb.__vftable = (Scaleform::GFx::AS3::Instances::fl::EmptyCallBack_vtbl *)&Scaleform::GFx::AS3::Instances::fl::EmptyCallBack::`vftable';
  Scaleform::GFx::AS3::Value::Value(&name, p);
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, this->pTraits.pObject->pVM->PublicNamespace.pObject, &name);
  if ( (name.Flags & 0x1F) > 9 )
  {
    if ( (name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
  }
  if ( (mn.Kind & 8) != 0 )
    v4 = Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachAttr(this, (Scaleform::GFx::AS3::SoundObject *)&mn, &cb);
  else
    v4 = Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(
           this,
           (Scaleform::GFx::AS3::SoundObject *)&mn,
           &cb);
  v5 = v4 != 0;
  Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  return v5;
}
