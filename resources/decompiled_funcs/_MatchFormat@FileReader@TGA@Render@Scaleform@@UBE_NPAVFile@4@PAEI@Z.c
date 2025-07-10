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
  Scaleform::Render::FileHeaderReader<18> header; // [esp+0h] [ebp-18h] BYREF

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(
    &header,
    file,
    headerArg,
    headerArgSize,
    header.Buffer,
    0x12u);
  if ( !header.pHeader )
    return 0;
  v5 = header.pHeader[7];
  v6 = header.pHeader[2];
  v9 = header.pHeader[16];
  if ( header.pHeader[1] )
  {
    if ( header.pHeader[1] != 1 || v6 != 1 )
      return 0;
  }
  else if ( v6 != 2 )
  {
    return 0;
  }
  if ( v5 && v5 != 24 && v5 != 32 || v9 != 8 && v9 != 24 && v9 != 32 || (header.pHeader[17] & 0xC0) != 0 )
    return 0;
  v8 = *((unsigned __int16 *)header.pHeader + 7);
  v7 = *((unsigned __int16 *)header.pHeader + 6);
  return file->GetLength(file) >= v7 * v8 * (v9 >> 3) + 18;
}
