bool __thiscall Scaleform::Render::PNG::FileReader::MatchFormat(
        Scaleform::Render::PNG::FileReader *this,
        Scaleform::File *file,
        unsigned __int8 *headerArg,
        unsigned int headerArgSize)
{
  Scaleform::Render::FileHeaderReader<8> header; // [esp+0h] [ebp-Ch] BYREF

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(
    &header,
    file,
    headerArg,
    headerArgSize,
    header.Buffer,
    8u);
  return header.pHeader && png_sig_cmp((int)header.pHeader, 0, 8u) == 0;
}
