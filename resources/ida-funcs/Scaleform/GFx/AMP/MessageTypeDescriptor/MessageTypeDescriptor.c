void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageAppControl>::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageAppControl>(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageAppControl> *this,
        const __m128i *messageTypeName,
        Scaleform::GFx::Resource *messageHandler)
{
  Scaleform::GFx::Resource *v4; // ecx
  Scaleform::GFx::AMP::IMessageHandler *v5; // edi

  v4 = messageHandler;
  if ( messageHandler )
  {
    Scaleform::RefCountImpl::AddRef(messageHandler);
    v4 = messageHandler;
  }
  v5 = (Scaleform::GFx::AMP::IMessageHandler *)v4;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageAppControl>_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageAppControl>_vtbl *)&Scaleform::GFx::AMP::BaseMessageTypeDescriptor::`vftable';
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->MessageHandler.pObject = v5;
  Scaleform::StringLH::StringLH(&this->MessageTypeName, messageTypeName);
  this->HandleImmediately = 0;
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageAppControl>_vtbl *)&Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageAppControl>::`vftable';
  if ( messageHandler )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)messageHandler);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageCompressed>::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageCompressed>(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageCompressed> *this,
        const __m128i *messageTypeName,
        Scaleform::GFx::Resource *messageHandler)
{
  Scaleform::GFx::Resource *v4; // ecx
  Scaleform::GFx::AMP::IMessageHandler *v5; // edi

  v4 = messageHandler;
  if ( messageHandler )
  {
    Scaleform::RefCountImpl::AddRef(messageHandler);
    v4 = messageHandler;
  }
  v5 = (Scaleform::GFx::AMP::IMessageHandler *)v4;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageCompressed>_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageCompressed>_vtbl *)&Scaleform::GFx::AMP::BaseMessageTypeDescriptor::`vftable';
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->MessageHandler.pObject = v5;
  Scaleform::StringLH::StringLH(&this->MessageTypeName, messageTypeName);
  this->HandleImmediately = 0;
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageCompressed>_vtbl *)&Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageCompressed>::`vftable';
  if ( messageHandler )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)messageHandler);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageFontRequest>::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageFontRequest>(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageFontRequest> *this,
        const __m128i *messageTypeName,
        Scaleform::GFx::Resource *messageHandler)
{
  Scaleform::GFx::Resource *v4; // ecx
  Scaleform::GFx::AMP::IMessageHandler *v5; // edi

  v4 = messageHandler;
  if ( messageHandler )
  {
    Scaleform::RefCountImpl::AddRef(messageHandler);
    v4 = messageHandler;
  }
  v5 = (Scaleform::GFx::AMP::IMessageHandler *)v4;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageFontRequest>_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageFontRequest>_vtbl *)&Scaleform::GFx::AMP::BaseMessageTypeDescriptor::`vftable';
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->MessageHandler.pObject = v5;
  Scaleform::StringLH::StringLH(&this->MessageTypeName, messageTypeName);
  this->HandleImmediately = 0;
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageFontRequest>_vtbl *)&Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageFontRequest>::`vftable';
  if ( messageHandler )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)messageHandler);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageHeartbeat>::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageHeartbeat>(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageHeartbeat> *this,
        const __m128i *messageTypeName,
        Scaleform::GFx::Resource *messageHandler)
{
  Scaleform::GFx::Resource *v4; // ecx
  Scaleform::GFx::AMP::IMessageHandler *v5; // edi

  v4 = messageHandler;
  if ( messageHandler )
  {
    Scaleform::RefCountImpl::AddRef(messageHandler);
    v4 = messageHandler;
  }
  v5 = (Scaleform::GFx::AMP::IMessageHandler *)v4;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageHeartbeat>_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageHeartbeat>_vtbl *)&Scaleform::GFx::AMP::BaseMessageTypeDescriptor::`vftable';
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->MessageHandler.pObject = v5;
  Scaleform::StringLH::StringLH(&this->MessageTypeName, messageTypeName);
  this->HandleImmediately = 0;
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageHeartbeat>_vtbl *)&Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageHeartbeat>::`vftable';
  if ( messageHandler )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)messageHandler);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageImageRequest>::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageImageRequest>(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageImageRequest> *this,
        const __m128i *messageTypeName,
        Scaleform::GFx::Resource *messageHandler)
{
  Scaleform::GFx::Resource *v4; // ecx
  Scaleform::GFx::AMP::IMessageHandler *v5; // edi

  v4 = messageHandler;
  if ( messageHandler )
  {
    Scaleform::RefCountImpl::AddRef(messageHandler);
    v4 = messageHandler;
  }
  v5 = (Scaleform::GFx::AMP::IMessageHandler *)v4;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageImageRequest>_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageImageRequest>_vtbl *)&Scaleform::GFx::AMP::BaseMessageTypeDescriptor::`vftable';
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->MessageHandler.pObject = v5;
  Scaleform::StringLH::StringLH(&this->MessageTypeName, messageTypeName);
  this->HandleImmediately = 0;
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageImageRequest>_vtbl *)&Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageImageRequest>::`vftable';
  if ( messageHandler )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)messageHandler);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageInitState>::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageInitState>(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageInitState> *this,
        const __m128i *messageTypeName,
        Scaleform::GFx::Resource *messageHandler)
{
  Scaleform::GFx::Resource *v4; // ecx
  Scaleform::GFx::AMP::IMessageHandler *v5; // edi

  v4 = messageHandler;
  if ( messageHandler )
  {
    Scaleform::RefCountImpl::AddRef(messageHandler);
    v4 = messageHandler;
  }
  v5 = (Scaleform::GFx::AMP::IMessageHandler *)v4;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageInitState>_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageInitState>_vtbl *)&Scaleform::GFx::AMP::BaseMessageTypeDescriptor::`vftable';
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->MessageHandler.pObject = v5;
  Scaleform::StringLH::StringLH(&this->MessageTypeName, messageTypeName);
  this->HandleImmediately = 0;
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageInitState>_vtbl *)&Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageInitState>::`vftable';
  if ( messageHandler )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)messageHandler);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageLog>::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageLog>(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageLog> *this,
        const __m128i *messageTypeName,
        Scaleform::GFx::Resource *messageHandler)
{
  Scaleform::GFx::Resource *v4; // ecx
  Scaleform::GFx::AMP::IMessageHandler *v5; // edi

  v4 = messageHandler;
  if ( messageHandler )
  {
    Scaleform::RefCountImpl::AddRef(messageHandler);
    v4 = messageHandler;
  }
  v5 = (Scaleform::GFx::AMP::IMessageHandler *)v4;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageLog>_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageLog>_vtbl *)&Scaleform::GFx::AMP::BaseMessageTypeDescriptor::`vftable';
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->MessageHandler.pObject = v5;
  Scaleform::StringLH::StringLH(&this->MessageTypeName, messageTypeName);
  this->HandleImmediately = 0;
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageLog>_vtbl *)&Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageLog>::`vftable';
  if ( messageHandler )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)messageHandler);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageObjectsReportRequest>::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageObjectsReportRequest>(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageObjectsReportRequest> *this,
        const __m128i *messageTypeName,
        Scaleform::GFx::Resource *messageHandler)
{
  Scaleform::GFx::Resource *v4; // ecx
  Scaleform::GFx::AMP::IMessageHandler *v5; // edi

  v4 = messageHandler;
  if ( messageHandler )
  {
    Scaleform::RefCountImpl::AddRef(messageHandler);
    v4 = messageHandler;
  }
  v5 = (Scaleform::GFx::AMP::IMessageHandler *)v4;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageObjectsReportRequest>_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageObjectsReportRequest>_vtbl *)&Scaleform::GFx::AMP::BaseMessageTypeDescriptor::`vftable';
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->MessageHandler.pObject = v5;
  Scaleform::StringLH::StringLH(&this->MessageTypeName, messageTypeName);
  this->HandleImmediately = 0;
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageObjectsReportRequest>_vtbl *)&Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageObjectsReportRequest>::`vftable';
  if ( messageHandler )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)messageHandler);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessagePort>::MessageTypeDescriptor<Scaleform::GFx::AMP::MessagePort>(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessagePort> *this,
        const __m128i *messageTypeName,
        Scaleform::GFx::Resource *messageHandler)
{
  Scaleform::GFx::Resource *v4; // ecx
  Scaleform::GFx::AMP::IMessageHandler *v5; // edi

  v4 = messageHandler;
  if ( messageHandler )
  {
    Scaleform::RefCountImpl::AddRef(messageHandler);
    v4 = messageHandler;
  }
  v5 = (Scaleform::GFx::AMP::IMessageHandler *)v4;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessagePort>_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessagePort>_vtbl *)&Scaleform::GFx::AMP::BaseMessageTypeDescriptor::`vftable';
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->MessageHandler.pObject = v5;
  Scaleform::StringLH::StringLH(&this->MessageTypeName, messageTypeName);
  this->HandleImmediately = 0;
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessagePort>_vtbl *)&Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessagePort>::`vftable';
  if ( messageHandler )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)messageHandler);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSourceRequest>::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSourceRequest>(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSourceRequest> *this,
        const __m128i *messageTypeName,
        Scaleform::GFx::Resource *messageHandler)
{
  Scaleform::GFx::Resource *v4; // ecx
  Scaleform::GFx::AMP::IMessageHandler *v5; // edi

  v4 = messageHandler;
  if ( messageHandler )
  {
    Scaleform::RefCountImpl::AddRef(messageHandler);
    v4 = messageHandler;
  }
  v5 = (Scaleform::GFx::AMP::IMessageHandler *)v4;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSourceRequest>_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSourceRequest>_vtbl *)&Scaleform::GFx::AMP::BaseMessageTypeDescriptor::`vftable';
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->MessageHandler.pObject = v5;
  Scaleform::StringLH::StringLH(&this->MessageTypeName, messageTypeName);
  this->HandleImmediately = 0;
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSourceRequest>_vtbl *)&Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSourceRequest>::`vftable';
  if ( messageHandler )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)messageHandler);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSwdRequest>::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSwdRequest>(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSwdRequest> *this,
        const __m128i *messageTypeName,
        Scaleform::GFx::Resource *messageHandler)
{
  Scaleform::GFx::Resource *v4; // ecx
  Scaleform::GFx::AMP::IMessageHandler *v5; // edi

  v4 = messageHandler;
  if ( messageHandler )
  {
    Scaleform::RefCountImpl::AddRef(messageHandler);
    v4 = messageHandler;
  }
  v5 = (Scaleform::GFx::AMP::IMessageHandler *)v4;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSwdRequest>_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSwdRequest>_vtbl *)&Scaleform::GFx::AMP::BaseMessageTypeDescriptor::`vftable';
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->MessageHandler.pObject = v5;
  Scaleform::StringLH::StringLH(&this->MessageTypeName, messageTypeName);
  this->HandleImmediately = 0;
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSwdRequest>_vtbl *)&Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSwdRequest>::`vftable';
  if ( messageHandler )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)messageHandler);
}
