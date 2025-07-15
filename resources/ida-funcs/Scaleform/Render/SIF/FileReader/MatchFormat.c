bool __thiscall Scaleform::Render::SIF::FileReader::MatchFormat(
        Scaleform::Render::SIF::FileReader *this,
        Scaleform::File *file,
        unsigned __int8 *headerArg,
        unsigned int headerArgSize)
{
  Scaleform::Render::FileHeaderReaderImpl v5; // [esp+0h] [ebp-8h] BYREF
  unsigned __int8 tempBuffer[4]; // [esp+4h] [ebp-4h] BYREF

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(&v5, file, headerArg, headerArgSize, tempBuffer, 4u);
  return v5.pHeader && *v5.pHeader == 83 && v5.pHeader[1] == 73 && v5.pHeader[2] == 70 && v5.pHeader[3] == 32;
}
