void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::AS2::Object>>::DestructArray(
        Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // ecx
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
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
        }
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
