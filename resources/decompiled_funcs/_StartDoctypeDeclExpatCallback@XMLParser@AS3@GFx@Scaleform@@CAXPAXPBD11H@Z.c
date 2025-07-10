void __cdecl Scaleform::GFx::AS3::XMLParser::StartDoctypeDeclExpatCallback(_DWORD *userData)
{
  const void *v1; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *v2; // edi
  unsigned int v3; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // eax

  v1 = (const void *)userData[13];
  v2 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)(userData + 10);
  v3 = userData[11] + 1;
  if ( v3 >= userData[11] )
  {
    if ( v3 >= userData[12] )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v2,
        v1,
        v3 + (v3 >> 2));
  }
  else if ( v3 < userData[12] >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v2,
      v1,
      userData[11] + 1);
  }
  Data = v2->Data;
  userData[11] = v3;
  Data[v3 - 1] = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)6;
}
