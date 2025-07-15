void __thiscall Scaleform::GFx::AMP::Message::Read(Scaleform::GFx::AMP::Message *this, Scaleform::String str)
{
  Scaleform::File *pData; // esi
  void (__thiscall *v3)(Scaleform::String::DataDesc *, char *, int); // edx
  void *v5; // edi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int HeapTypeBits; // eax
  int (__thiscall *v8)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v9; // [esp+14h] [ebp-4h] BYREF

  pData = (Scaleform::File *)str.pData;
  v3 = *(void (__thiscall **)(Scaleform::String::DataDesc *, char *, int))(*(_DWORD *)str.HeapTypeBits + 40);
  HIBYTE(v9) = 0;
  v3(str.pData, (char *)&v9 + 3, 1);
  if ( !HIBYTE(v9) )
  {
    Scaleform::String::String(&str);
    Scaleform::GFx::AMP::Message::ReadString(pData, &str);
    v5 = (void *)(str.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((str.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  }
  Read = pData->Read;
  str.pData = 0;
  Read(pData, (unsigned __int8 *)&str, 4);
  HeapTypeBits = str.HeapTypeBits;
  this->Version = str.HeapTypeBits;
  if ( HeapTypeBits >= 0x16 )
  {
    v8 = pData->Read;
    LOBYTE(str.pData) = 0;
    v8(pData, (unsigned __int8 *)&str, 1);
    this->GFxVersion = (unsigned __int8)str.pData;
  }
}
