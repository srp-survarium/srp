Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::SoundObject *prop_name,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list)
{
  Scaleform::GFx::AS3::SoundObject *v4; // edi
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  bool v7; // zf
  unsigned int ind; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack v9; // [esp+Ch] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XMLList *v10; // [esp+14h] [ebp-10h]
  Scaleform::GFx::AS3::Instances::fl::ChildGet cb; // [esp+18h] [ebp-Ch] BYREF

  v4 = prop_name;
  if ( Scaleform::GFx::AS3::GetVectorInd(
         (Scaleform::GFx::AS3::CheckResult *)&prop_name,
         (const Scaleform::GFx::AS3::Multiname *)prop_name,
         &ind)->Result )
  {
    if ( ind < this->Children.Data.Size )
      Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(list, this->Children.Data.Data[ind].pObject);
    v6 = result;
    result->Result = 1;
  }
  else if ( ((int)v4->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable
           & 8) != 0 )
  {
    v9.Element = this;
    v9.__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack_vtbl *)&Scaleform::GFx::AS3::Instances::fl::AttrGet::`vftable';
    v10 = list;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachAttr(this, v4, &v9);
    v6 = result;
    result->Result = 1;
  }
  else
  {
    cb.List = list;
    cb.Element = this;
    cb.__vftable = (Scaleform::GFx::AS3::Instances::fl::ChildGet_vtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGet::`vftable';
    v7 = Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(this, v4, &cb) == 0;
    v6 = result;
    result->Result = !v7;
  }
  return v6;
}
