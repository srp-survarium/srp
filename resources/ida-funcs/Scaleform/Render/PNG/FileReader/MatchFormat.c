bool __thiscall Scaleform::Render::PNG::FileReader::MatchFormat(
        Scaleform::Render::PNG::FileReader *this,
        Scaleform::File *file,
        unsigned __int8 *headerArg,
        unsigned int headerArgSize)
{
  Scaleform::Render::FileHeaderReaderImpl v5; // [esp+0h] [ebp-Ch] BYREF
  unsigned __int8 tempBuffer[8]; // [esp+4h] [ebp-8h] BYREF

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(&v5, file, headerArg, headerArgSize, tempBuffer, 8u);
  return v5.pHeader && png_sig_cmp(v5.pHeader, 0, 8) == 0;
}
