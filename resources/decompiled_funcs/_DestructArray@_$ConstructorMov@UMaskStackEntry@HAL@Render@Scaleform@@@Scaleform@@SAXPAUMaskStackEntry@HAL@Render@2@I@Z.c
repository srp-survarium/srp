void __cdecl Scaleform::ConstructorMov<Scaleform::Render::HAL::MaskStackEntry>::DestructArray(
        Scaleform::Render::HAL::MaskStackEntry *p,
        unsigned int count)
{
  Scaleform::RefCountVImpl **v2; // esi
  unsigned int v3; // edi

  v2 = (Scaleform::RefCountVImpl **)&p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( *v2 )
        Scaleform::RefCountImpl::Release(*v2);
      v2 -= 6;
      --v3;
    }
    while ( v3 );
  }
}
