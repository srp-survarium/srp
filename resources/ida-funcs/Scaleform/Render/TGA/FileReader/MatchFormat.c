bool __thiscall Scaleform::Render::TGA::FileReader::MatchFormat(
        Scaleform::Render::TGA::FileReader *this,
        Scaleform::File *file,
        unsigned __int8 *headerArg,
        unsigned int headerArgSize)
{
  unsigned __int8 v5; // dl
  int v6; // ebp
  int v7; // esi
  int v8; // edi
  unsigned __int8 v9; // bl
  Scaleform::Render::FileHeaderReaderImpl v10; // [esp+0h] [ebp-18h] BYREF
  unsigned __int8 tempBuffer[20]; // [esp+4h] [ebp-14h] BYREF

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(&v10, file, headerArg, headerArgSize, tempBuffer, 0x12u);
  if ( !v10.pHeader )
    return 0;
  v5 = v10.pHeader[7];
  v6 = v10.pHeader[2];
  v9 = v10.pHeader[16];
  if ( v10.pHeader[1] )
  {
    if ( v10.pHeader[1] != 1 || v6 != 1 )
      return 0;
  }
  else if ( v6 != 2 )
  {
    return 0;
  }
  if ( v5 && v5 != 24 && v5 != 32 || v9 != 8 && v9 != 24 && v9 != 32 || (v10.pHeader[17] & 0xC0) != 0 )
    return 0;
  v8 = *((unsigned __int16 *)v10.pHeader + 7);
  v7 = *((unsigned __int16 *)v10.pHeader + 6);
  return file->GetLength(file) >= v7 * v8 * (v9 >> 3) + 18;
}
