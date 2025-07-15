Scaleform::GFx::Resource *__thiscall Scaleform::GFx::AS3::MovieRoot::AddSocket(
        Scaleform::GFx::AS3::MovieRoot *this,
        bool initSockLib,
        Scaleform::GFx::AMP::SocketImplFactory *socketImplFactory,
        Scaleform::GFx::AS3::Instances::fl_net::Socket *sock)
{
  Scaleform::GFx::AS3::SocketThreadMgr *v5; // eax
  Scaleform::GFx::Resource *v6; // eax
  Scaleform::GFx::Resource *v7; // edi
  unsigned int Size; // edx
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2,Scaleform::ArrayDefaultPolicy> *p_Sockets; // esi
  _DWORD *p_pObject; // esi
  int v12; // [esp+8h] [ebp-4h] BYREF

  v12 = 327;
  v5 = (Scaleform::GFx::AS3::SocketThreadMgr *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 192,
                                                 &v12);
  if ( v5 )
  {
    Scaleform::GFx::AS3::SocketThreadMgr::SocketThreadMgr(v5, initSockLib, socketImplFactory, sock);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  Size = this->Sockets.Data.Size;
  p_Sockets = &this->Sockets;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &p_Sockets->Data,
    p_Sockets,
    Size + 1);
  p_pObject = &p_Sockets->Data.Data[p_Sockets->Data.Size - 1].pObject;
  if ( p_pObject )
  {
    if ( v7 )
      Scaleform::RefCountImpl::AddRef(v7);
    *p_pObject = v7;
  }
  if ( v7 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7);
  return v7;
}
