void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3name(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *result)
{
  const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *v2; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v4; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v5; // [esp+4h] [ebp-4h] BYREF

  v5 = this;
  v2 = (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)this->GetQName(this, &v5);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)result,
    v2);
  if ( v5 && ((unsigned __int8)v5 & 1) == 0 )
  {
    RefCount = v5->RefCount;
    v4 = v5;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
    }
  }
}
