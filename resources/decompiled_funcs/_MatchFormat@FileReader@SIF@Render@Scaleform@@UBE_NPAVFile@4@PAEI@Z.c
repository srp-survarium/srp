bool __thiscall Scaleform::Render::SIF::FileReader::MatchFormat(
        Scaleform::Render::SIF::FileReader *this,
        Scaleform::File *file,
        unsigned __int8 *headerArg,
        unsigned int headerArgSize)
{
  Scaleform::Render::FileHeaderReader<4> header; // [esp+0h] [ebp-8h] BYREF

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(
    &header,
    file,
    headerArg,
    headerArgSize,
    header.Buffer,
    4u);
  return header.pHeader
      && *header.pHeader == 83
      && header.pHeader[1] == 73
      && header.pHeader[2] == 70
      && header.pHeader[3] == 32;
}
