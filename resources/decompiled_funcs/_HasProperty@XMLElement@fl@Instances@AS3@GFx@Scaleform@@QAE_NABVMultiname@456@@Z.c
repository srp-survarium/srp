bool __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::HasProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::SoundObject *prop_name)
{
  Scaleform::GFx::AS3::SoundObject *v2; // edi
  unsigned int v5; // edx
  unsigned int ind; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::Instances::fl::EmptyCallBack cb; // [esp+Ch] [ebp-8h] BYREF

  v2 = prop_name;
  if ( Scaleform::GFx::AS3::GetVectorInd(
         (Scaleform::GFx::AS3::CheckResult *)&prop_name,
         (const Scaleform::GFx::AS3::Multiname *)prop_name,
         &ind)->Result )
    return ind == 0;
  v5 = (unsigned int)v2->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable >> 3;
  cb.Element = this;
  cb.__vftable = (Scaleform::GFx::AS3::Instances::fl::EmptyCallBack_vtbl *)&Scaleform::GFx::AS3::Instances::fl::EmptyCallBack::`vftable';
  if ( (v5 & 1) != 0 )
    return Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachAttr(this, v2, &cb) != 0;
  else
    return Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(this, v2, &cb) != 0;
}
