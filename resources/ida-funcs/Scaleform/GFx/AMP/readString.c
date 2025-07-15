void __cdecl Scaleform::GFx::AMP::readString(Scaleform::File *file, Scaleform::String *str)
{
  Scaleform::File *v2; // esi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v4; // edi
  Scaleform::String *v5; // ebp
  int (__thiscall *v6)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v7; // [esp+8h] [ebp-4h] BYREF

  v2 = file;
  Read = file->Read;
  v7 = 0;
  Read(file, (unsigned __int8 *)&v7, 4);
  v4 = v7;
  if ( v7 )
  {
    v5 = str;
    do
    {
      v6 = v2->Read;
      LOBYTE(file) = 0;
      v6(v2, (unsigned __int8 *)&file, 1);
      Scaleform::String::AppendChar(v5, (char)file);
      --v4;
    }
    while ( v4 );
  }
}
