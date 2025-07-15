void __cdecl Scaleform::GFx::AMP::writeString(Scaleform::File *file, Scaleform::String *str)
{
  Scaleform::String *v2; // edi
  int Length; // eax
  Scaleform::File *v4; // ebx
  unsigned int i; // esi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v2 = str;
  Length = Scaleform::String::GetLength(str);
  v4 = file;
  v7 = Length;
  file->Write(file, (const unsigned __int8 *)&v7, 4);
  for ( i = 0; i < Scaleform::String::GetLength(v2); ++i )
  {
    Write = v4->Write;
    LOBYTE(file) = *(_BYTE *)((v2->HeapTypeBits & 0xFFFFFFFC) + i + 8);
    Write(v4, (const unsigned __int8 *)&file, 1);
  }
}
