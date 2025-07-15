bool __thiscall Scaleform::Render::JPEG::FileReader::MatchFormat(
        Scaleform::Render::JPEG::FileReader *this,
        Scaleform::File *file,
        unsigned __int8 *headerArg,
        unsigned int headerArgSize)
{
  Scaleform::Render::FileHeaderReaderImpl v5; // [esp+0h] [ebp-8h] BYREF
  unsigned __int8 tempBuffer[4]; // [esp+4h] [ebp-4h] BYREF

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(&v5, file, headerArg, headerArgSize, tempBuffer, 2u);
  return v5.pHeader && *v5.pHeader == 0xFF && v5.pHeader[1] == 0xD8;
}
