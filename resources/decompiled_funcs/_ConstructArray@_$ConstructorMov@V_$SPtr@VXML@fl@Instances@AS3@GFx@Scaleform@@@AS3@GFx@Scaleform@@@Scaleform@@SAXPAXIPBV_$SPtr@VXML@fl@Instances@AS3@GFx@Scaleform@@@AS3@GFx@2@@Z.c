void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>>::ConstructArray(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *p,
        unsigned int count,
        const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *psource)
{
  unsigned int v5; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // eax

  if ( count )
  {
    v5 = count;
    do
    {
      if ( p )
      {
        pObject = psource->pObject;
        p->pObject = psource->pObject;
        if ( pObject )
          pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
      }
      ++psource;
      ++p;
      --v5;
    }
    while ( v5 );
  }
}
