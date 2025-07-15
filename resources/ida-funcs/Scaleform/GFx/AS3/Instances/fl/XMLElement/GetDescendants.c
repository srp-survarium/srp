void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetDescendants(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list,
        Scaleform::GFx::AS3::SoundObject *prop_name)
{
  unsigned int v5; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl::AttrGet cb; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int size; // [esp+20h] [ebp+8h]

  if ( ((int)prop_name->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable
      & 8) != 0 )
  {
    cb.List = list;
    cb.Element = this;
    cb.__vftable = (Scaleform::GFx::AS3::Instances::fl::AttrGet_vtbl *)&Scaleform::GFx::AS3::Instances::fl::AttrGet::`vftable';
    Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachAttr(this, prop_name, &cb);
  }
  v5 = 0;
  size = this->Children.Data.Size;
  if ( size )
  {
    do
    {
      pObject = this->Children.Data.Data[v5].pObject;
      if ( ((int)prop_name->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable
          & 8) == 0
        && Scaleform::GFx::AS3::Instances::fl::XML::Matches(pObject, prop_name) )
      {
        Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(list, pObject);
      }
      pObject->GetDescendants(pObject, list, (const Scaleform::GFx::AS3::Multiname *)prop_name);
      ++v5;
    }
    while ( v5 < size );
  }
}
