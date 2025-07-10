void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::Render::Image>>::DestructArray(
        Scaleform::Ptr<Scaleform::Render::Image> *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::Render::Image> *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->pObject )
        v2->pObject->Release(v2->pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
