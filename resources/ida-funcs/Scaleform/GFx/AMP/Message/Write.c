void __thiscall Scaleform::GFx::AMP::Message::Write(Scaleform::GFx::AMP::Message *this, unsigned int str)
{
  unsigned __int8 v3; // al
  Scaleform::File *v4; // esi
  void (__thiscall *v5)(unsigned int, unsigned __int8 *, int); // edx
  Scaleform::String *v6; // eax
  void *v7; // ebx
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v9)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned __int8 v10[4]; // [esp+10h] [ebp-4h] BYREF

  if ( this->Version >= 0x1C )
  {
    v4 = (Scaleform::File *)str;
    v5 = *(void (__thiscall **)(unsigned int, unsigned __int8 *, int))(*(_DWORD *)str + 36);
    v10[0] = 0;
    v5(str, v10, 1);
    v6 = this->GetMessageName(this, &str);
    Scaleform::GFx::AMP::writeString(v4, v6);
    v7 = (void *)(str & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((str & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  }
  else
  {
    v3 = this->GetMessageType(this);
    v4 = (Scaleform::File *)str;
    v10[0] = v3;
    (*(void (__thiscall **)(unsigned int, unsigned __int8 *, int))(*(_DWORD *)str + 36))(str, v10, 1);
  }
  Write = v4->Write;
  str = this->Version;
  Write(v4, (const unsigned __int8 *)&str, 4);
  if ( this->Version >= 0x16 )
  {
    v9 = v4->Write;
    LOBYTE(str) = this->GFxVersion;
    v9(v4, (const unsigned __int8 *)&str, 1);
  }
}
