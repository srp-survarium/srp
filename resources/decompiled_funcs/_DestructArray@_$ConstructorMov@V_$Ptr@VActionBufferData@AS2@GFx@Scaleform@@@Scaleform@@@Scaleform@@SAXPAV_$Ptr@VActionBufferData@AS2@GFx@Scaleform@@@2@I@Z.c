void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>>::DestructArray(
        Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr> *p,
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
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
