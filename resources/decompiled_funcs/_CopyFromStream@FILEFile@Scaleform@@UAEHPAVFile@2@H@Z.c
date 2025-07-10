int __thiscall Scaleform::FILEFile::CopyFromStream(
        Scaleform::BufferedFile *this,
        Scaleform::File *pstream,
        int byteSize)
{
  int v3; // edi
  int v4; // ebp
  int v5; // esi
  int v6; // ecx
  int v7; // eax
  _BYTE v10[16384]; // [esp+Ch] [ebp-4000h] BYREF

  v3 = byteSize;
  v4 = 0;
  if ( !byteSize )
    return 0;
  do
  {
    v5 = 0x4000;
    if ( v3 <= 0x4000 )
      v5 = v3;
    v6 = pstream->Read(pstream, v10, v5);
    v7 = 0;
    if ( v6 > 0 )
      v7 = this->Write(this, v10, v6);
    v4 += v7;
    v3 -= v7;
  }
  while ( v7 >= v5 && v3 );
  return v4;
}
