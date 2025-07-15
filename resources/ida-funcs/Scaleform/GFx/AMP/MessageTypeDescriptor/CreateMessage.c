void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageAppControl>::CreateMessage(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageAppControl> *this)
{
  Scaleform::GFx::AMP::MessageAppControl *v1; // eax
  int v2; // [esp+4h] [ebp-4h] BYREF

  v2 = 580;
  v1 = (Scaleform::GFx::AMP::MessageAppControl *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this,
                                                   36,
                                                   &v2);
  if ( v1 )
    Scaleform::GFx::AMP::MessageAppControl::MessageAppControl(v1, 0);
}


Scaleform::GFx::AMP::MessageCompressed *__thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageCompressed>::CreateMessage(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageCompressed> *this)
{
  Scaleform::GFx::AMP::Message *v1; // eax
  _DWORD *v2; // esi
  int v4; // [esp+4h] [ebp-4h] BYREF

  v4 = 580;
  v1 = (Scaleform::GFx::AMP::Message *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         36,
                                         &v4);
  v2 = &v1->__vftable;
  if ( !v1 )
    return 0;
  Scaleform::GFx::AMP::Message::Message(v1);
  *v2 = &Scaleform::GFx::AMP::MessageCompressed::`vftable';
  v2[6] = 0;
  v2[7] = 0;
  v2[8] = 0;
  return (Scaleform::GFx::AMP::MessageCompressed *)v2;
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageFontRequest>::CreateMessage(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageFontRequest> *this)
{
  Scaleform::GFx::AMP::MessageFontRequest *v1; // eax
  int v2; // [esp+4h] [ebp-4h] BYREF

  v2 = 580;
  v1 = (Scaleform::GFx::AMP::MessageFontRequest *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    28,
                                                    &v2);
  if ( v1 )
    Scaleform::GFx::AMP::MessageFontRequest::MessageFontRequest(v1, 0);
}


Scaleform::GFx::AMP::MessageHeartbeat *__thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageHeartbeat>::CreateMessage(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageHeartbeat> *this)
{
  Scaleform::GFx::AMP::Message *v1; // eax
  _DWORD *v2; // esi
  int v4; // [esp+4h] [ebp-4h] BYREF

  v4 = 580;
  v1 = (Scaleform::GFx::AMP::Message *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         24,
                                         &v4);
  v2 = &v1->__vftable;
  if ( !v1 )
    return 0;
  Scaleform::GFx::AMP::Message::Message(v1);
  *v2 = &Scaleform::GFx::AMP::MessageHeartbeat::`vftable';
  return (Scaleform::GFx::AMP::MessageHeartbeat *)v2;
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageImageRequest>::CreateMessage(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageImageRequest> *this)
{
  Scaleform::GFx::AMP::MessageImageRequest *v1; // eax
  int v2; // [esp+4h] [ebp-4h] BYREF

  v2 = 580;
  v1 = (Scaleform::GFx::AMP::MessageImageRequest *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this,
                                                     28,
                                                     &v2);
  if ( v1 )
    Scaleform::GFx::AMP::MessageImageRequest::MessageImageRequest(v1, 0);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageInitState>::CreateMessage(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageInitState> *this)
{
  Scaleform::GFx::AMP::MessageInitState *v1; // eax
  int v2; // [esp+4h] [ebp-4h] BYREF

  v2 = 580;
  v1 = (Scaleform::GFx::AMP::MessageInitState *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  this,
                                                  32,
                                                  &v2);
  if ( v1 )
    Scaleform::GFx::AMP::MessageInitState::MessageInitState(v1, 0, 0);
}


Scaleform::GFx::AMP::MessageLog *__thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageLog>::CreateMessage(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageLog> *this)
{
  char v1; // bl
  Scaleform::GFx::AMP::MessageLog *v2; // esi
  int v3; // eax
  int v4; // edi
  void *v5; // esi
  Scaleform::String v7; // [esp+Ch] [ebp-8h] BYREF
  int v8; // [esp+10h] [ebp-4h] BYREF

  v1 = 0;
  v8 = 580;
  v2 = (Scaleform::GFx::AMP::MessageLog *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            this,
                                            36,
                                            &v8);
  if ( v2 )
  {
    Scaleform::String::String(&v7, (const __m128i *)uri);
    v1 = 1;
    Scaleform::GFx::AMP::MessageLog::MessageLog(v2, &v7, 0, 0);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  if ( (v1 & 1) != 0 )
  {
    v5 = (void *)(v7.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v7.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  }
  return (Scaleform::GFx::AMP::MessageLog *)v4;
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageObjectsReportRequest>::CreateMessage(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageObjectsReportRequest> *this)
{
  Scaleform::GFx::AMP::MessageObjectsReportRequest *v1; // eax
  int v2; // [esp+4h] [ebp-4h] BYREF

  v2 = 580;
  v1 = (Scaleform::GFx::AMP::MessageObjectsReportRequest *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             this,
                                                             36,
                                                             &v2);
  if ( v1 )
    Scaleform::GFx::AMP::MessageObjectsReportRequest::MessageObjectsReportRequest(v1);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessagePort>::CreateMessage(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessagePort> *this)
{
  Scaleform::GFx::AMP::MessagePort *v1; // eax
  int v2; // [esp+4h] [ebp-4h] BYREF

  v2 = 580;
  v1 = (Scaleform::GFx::AMP::MessagePort *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                             Scaleform::Memory::pGlobalHeap,
                                             this,
                                             48,
                                             &v2);
  if ( v1 )
    Scaleform::GFx::AMP::MessagePort::MessagePort(v1, 0, 0, 0);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSourceRequest>::CreateMessage(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSourceRequest> *this)
{
  Scaleform::GFx::AMP::MessageSourceRequest *v1; // eax
  int v2; // [esp+4h] [ebp-4h] BYREF

  v2 = 580;
  v1 = (Scaleform::GFx::AMP::MessageSourceRequest *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      this,
                                                      40,
                                                      &v2);
  if ( v1 )
    Scaleform::GFx::AMP::MessageSourceRequest::MessageSourceRequest(v1, 0, 0);
}


void __thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSwdRequest>::CreateMessage(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageSwdRequest> *this)
{
  Scaleform::GFx::AMP::MessageSwdRequest *v1; // eax
  int v2; // [esp+4h] [ebp-4h] BYREF

  v2 = 580;
  v1 = (Scaleform::GFx::AMP::MessageSwdRequest *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this,
                                                   32,
                                                   &v2);
  if ( v1 )
    Scaleform::GFx::AMP::MessageSwdRequest::MessageSwdRequest(v1, 0, 0);
}
