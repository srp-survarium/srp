void __thiscall Scaleform::GFx::AMP::ImageInfo::Read(
        Scaleform::GFx::AMP::ImageInfo *this,
        unsigned int str,
        unsigned int version)
{
  Scaleform::File *v3; // esi
  int (__thiscall *v4)(Scaleform::File *, unsigned __int8 *, int); // edx
  void *v6; // ebp
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v8)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v9)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v10)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v11)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v12)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v13)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v14; // [esp+3Ch] [ebp-4h] BYREF

  v3 = (Scaleform::File *)str;
  v4 = *(int (__thiscall **)(Scaleform::File *, unsigned __int8 *, int))(*(_DWORD *)str + 40);
  v14 = 0;
  v4((Scaleform::File *)str, (unsigned __int8 *)&v14, 4);
  this->Id = v14;
  Scaleform::GFx::AMP::readString(v3, &this->Name);
  if ( version < 0x1D )
  {
    Scaleform::String::String((Scaleform::String *)&str);
    Scaleform::GFx::AMP::readString(v3, (Scaleform::String *)&str);
    v6 = (void *)(str & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((str & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
  }
  Read = v3->Read;
  str = 0;
  Read(v3, (unsigned __int8 *)&str, 4);
  this->Bytes = str;
  v8 = v3->Read;
  LOBYTE(str) = 0;
  v8(v3, (unsigned __int8 *)&str, 1);
  this->External = (_BYTE)str != 0;
  v9 = v3->Read;
  str = 0;
  v9(v3, (unsigned __int8 *)&str, 4);
  this->AtlasId = str;
  v10 = v3->Read;
  str = 0;
  v10(v3, (unsigned __int8 *)&str, 4);
  this->AtlasTop = str;
  v11 = v3->Read;
  str = 0;
  v11(v3, (unsigned __int8 *)&str, 4);
  this->AtlasBottom = str;
  v12 = v3->Read;
  str = 0;
  v12(v3, (unsigned __int8 *)&str, 4);
  this->AtlasLeft = str;
  v13 = v3->Read;
  str = 0;
  v13(v3, (unsigned __int8 *)&str, 4);
  this->AtlasRight = str;
}
