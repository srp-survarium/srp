void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *p,
        unsigned int count)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::AS3::VMAbcFile *pObject; // ecx
  unsigned int RefCount; // eax

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pObject;
      if ( v2->pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          v2->pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)pObject - 1);
        }
        else
        {
          RefCount = pObject->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
          }
        }
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
