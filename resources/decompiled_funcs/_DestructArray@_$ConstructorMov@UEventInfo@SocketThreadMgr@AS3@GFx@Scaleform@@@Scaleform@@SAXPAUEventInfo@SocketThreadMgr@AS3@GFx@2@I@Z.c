void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo>::DestructArray(
        Scaleform::GFx::AS3::SocketThreadMgr::EventInfo *p,
        unsigned int count)
{
  Scaleform::Array<unsigned long,2,Scaleform::ArrayDefaultPolicy> *p_EventParameters; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_EventParameters = &p[count - 1].EventParameters;
    v3 = count;
    do
    {
      if ( p_EventParameters->Data.Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_EventParameters->Data.Data);
      p_EventParameters = (Scaleform::Array<unsigned long,2,Scaleform::ArrayDefaultPolicy> *)((char *)p_EventParameters
                                                                                            - 16);
      --v3;
    }
    while ( v3 );
  }
}
