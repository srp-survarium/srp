void __cdecl Scaleform::GFx::AMP::Message::ReadString(Scaleform::File *inFile, Scaleform::String *str)
{
  Scaleform::String *v2; // edi
  Scaleform::File *v3; // esi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  int i; // ebp
  int (__thiscall *v6)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v2 = str;
  Scaleform::String::Clear(str);
  v3 = inFile;
  Read = inFile->Read;
  v7 = 0;
  Read(inFile, (unsigned __int8 *)&v7, 4);
  for ( i = v7; i; --i )
  {
    v6 = v3->Read;
    LOBYTE(inFile) = 0;
    v6(v3, (unsigned __int8 *)&inFile, 1);
    Scaleform::String::AppendChar(v2, (char)inFile);
  }
}
