HRESULT __cdecl XAudio2Create(
        IXAudio2 **ppXAudio2,
        unsigned int Flags,
        XAUDIO2_WINDOWS_PROCESSOR_SPECIFIER XAudio2Processor)
{
  GUID *v4; // [esp+0h] [ebp-10h]
  int hr; // [esp+8h] [ebp-8h]
  IXAudio2 *pXAudio2; // [esp+Ch] [ebp-4h] BYREF

  if ( (Flags & 1) != 0 )
    v4 = &_GUID_db05ea35_0329_4d4b_a53a_6dead03d3852;
  else
    v4 = &_GUID_5a508685_a254_4fba_9b82_9a24b00306af;
  hr = CoCreateInstance(v4, 0, 1u, &_GUID_8bcf1f58_9fe7_4583_8ac6_e2adc465c8bb, (LPVOID *)&pXAudio2);
  if ( hr >= 0 )
  {
    hr = pXAudio2->Initialize(pXAudio2, Flags, XAudio2Processor);
    if ( hr < 0 )
      pXAudio2->Release(pXAudio2);
    else
      *ppXAudio2 = pXAudio2;
  }
  return hr;
}
