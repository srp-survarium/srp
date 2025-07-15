bool __thiscall Scaleform::Render::JPEG::FileReader::MatchFormat(
        Scaleform::Render::JPEG::FileReader *this,
        Scaleform::File *file,
        unsigned __int8 *headerArg,
        unsigned int headerArgSize)
{
  Scaleform::Render::FileHeaderReader<2> header; // [esp+0h] [ebp-8h] BYREF

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(
    &header,
    file,
    headerArg,
    headerArgSize,
    header.Buffer,
    2u);
  return header.pHeader && *header.pHeader == 0xFF && header.pHeader[1] == 0xD8;
}
