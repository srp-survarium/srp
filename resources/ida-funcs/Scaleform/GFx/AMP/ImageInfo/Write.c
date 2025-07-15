void __thiscall Scaleform::GFx::AMP::ImageInfo::Write(
        Scaleform::GFx::AMP::ImageInfo *this,
        unsigned int str,
        unsigned int version)
{
  Scaleform::File *v3; // esi
  int (__thiscall *v4)(Scaleform::File *, const unsigned __int8 *, int); // edx
  void *v6; // ebx
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v8)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v9)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v10)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v11)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v12)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v13)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int Id; // [esp+34h] [ebp-4h] BYREF

  v3 = (Scaleform::File *)str;
  v4 = *(int (__thiscall **)(Scaleform::File *, const unsigned __int8 *, int))(*(_DWORD *)str + 36);
  Id = this->Id;
  v4((Scaleform::File *)str, (const unsigned __int8 *)&Id, 4);
  Scaleform::GFx::AMP::writeString(v3, &this->Name);
  if ( version < 0x1D )
  {
    Scaleform::String::String((Scaleform::String *)&str, (const __m128i *)uri);
    Scaleform::GFx::AMP::writeString(v3, (Scaleform::String *)&str);
    v6 = (void *)(str & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((str & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
  }
  Write = v3->Write;
  str = this->Bytes;
  Write(v3, (const unsigned __int8 *)&str, 4);
  v8 = v3->Write;
  LOBYTE(str) = this->External;
  v8(v3, (const unsigned __int8 *)&str, 1);
  v9 = v3->Write;
  str = this->AtlasId;
  v9(v3, (const unsigned __int8 *)&str, 4);
  v10 = v3->Write;
  str = this->AtlasTop;
  v10(v3, (const unsigned __int8 *)&str, 4);
  v11 = v3->Write;
  str = this->AtlasBottom;
  v11(v3, (const unsigned __int8 *)&str, 4);
  v12 = v3->Write;
  str = this->AtlasLeft;
  v12(v3, (const unsigned __int8 *)&str, 4);
  v13 = v3->Write;
  str = this->AtlasRight;
  v13(v3, (const unsigned __int8 *)&str, 4);
}
