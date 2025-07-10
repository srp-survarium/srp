void __thiscall Scaleform::GFx::AMP::DefaultSocketFactory<Scaleform::GFx::AMP::GFxSocketImpl>::Destroy(
        Scaleform::GFx::AMP::DefaultSocketFactory<Scaleform::GFx::AMP::GFxSocketImpl> *this,
        Scaleform::GFx::AMP::SocketInterface *socketImpl)
{
  if ( socketImpl )
    ((void (__thiscall *)(Scaleform::GFx::AMP::SocketInterface *, int))socketImpl->~Scaleform::GFx::AMP::SocketInterface)(
      socketImpl,
      1);
}
