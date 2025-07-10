void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::Sprite>>::DestructArray(
        Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase> *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase> *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->pObject )
        Scaleform::RefCountNTSImpl::Release(v2->pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
