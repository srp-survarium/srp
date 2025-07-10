void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::MovieImpl::IndirectTransPair>::DestructArray(
        Scaleform::GFx::MovieImpl::IndirectTransPair *p,
        unsigned int count)
{
  Scaleform::GFx::MovieImpl::IndirectTransPair *v2; // esi
  unsigned int v3; // edi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::RefCountNTSImpl *v5; // ecx
  Scaleform::Render::ContextImpl::Entry *v6; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->OriginalParent.pObject;
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      v5 = v2->Obj.pObject;
      if ( v5 )
        Scaleform::RefCountNTSImpl::Release(v5);
      v6 = v2->TransformParent.pObject;
      if ( v2->TransformParent.pObject )
      {
        if ( v6->RefCount-- == 1 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v6);
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
