void __thiscall Scaleform::GFx::AS3::Instances::fl::RegExp::AS3test(
        Scaleform::GFx::AS3::Instances::fl::RegExp *this,
        bool *result,
        const Scaleform::GFx::ASString *s)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // ecx
  bool v4; // zf
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> pobj; // [esp+0h] [ebp-4h] BYREF

  pobj.pObject = 0;
  Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(this, &pobj, s);
  pObject = pobj.pObject;
  v4 = pobj.pObject == 0;
  *result = pobj.pObject != 0;
  if ( !v4 && ((unsigned __int8)pObject & 1) == 0 )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
}
