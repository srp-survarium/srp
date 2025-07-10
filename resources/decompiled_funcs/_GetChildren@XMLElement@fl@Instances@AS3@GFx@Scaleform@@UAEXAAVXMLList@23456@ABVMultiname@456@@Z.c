void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetChildren(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list,
        Scaleform::GFx::AS3::SoundObject *prop_name)
{
  Scaleform::GFx::AS3::SoundObject *v3; // edi
  unsigned int ind; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::Instances::fl::ChildGet cb; // [esp+Ch] [ebp-Ch] BYREF

  v3 = prop_name;
  if ( Scaleform::GFx::AS3::GetVectorInd(
         (Scaleform::GFx::AS3::CheckResult *)&prop_name,
         (const Scaleform::GFx::AS3::Multiname *)prop_name,
         &ind)->Result )
  {
    if ( ind <= this->Children.Data.Size )
      Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(list, this->Children.Data.Data[ind].pObject);
  }
  else
  {
    cb.List = list;
    cb.Element = this;
    cb.__vftable = (Scaleform::GFx::AS3::Instances::fl::ChildGet_vtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGet::`vftable';
    Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(this, v3, &cb);
  }
}
