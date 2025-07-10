void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3name(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *result)
{
  const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *v3; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v5; // ecx
  Scaleform::GFx::AS3::CheckResult v6; // [esp+7h] [ebp-5h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // [esp+8h] [ebp-4h] BYREF

  if ( Scaleform::GFx::AS3::Instances::fl::XMLList::HasOneItem(this, &v6)->Result )
  {
    v3 = (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)this->List.Data.Data->pObject->GetQName(
                                                                                                   this->List.Data.Data->pObject,
                                                                                                   &v7);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)result,
      v3);
    if ( v7 )
    {
      if ( ((unsigned __int8)v7 & 1) == 0 )
      {
        RefCount = v7->RefCount;
        v5 = v7;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v7->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
        }
      }
    }
  }
}
