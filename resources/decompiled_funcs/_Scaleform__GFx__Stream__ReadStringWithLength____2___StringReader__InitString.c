void __thiscall Scaleform::GFx::Stream::ReadStringWithLength_::_2_::StringReader::InitString(
        Scaleform::GFx::Stream::ReadStringWithLength::__l2::StringReader *this,
        char *pbuffer,
        unsigned int size)
{
  unsigned int i; // edi
  Scaleform::GFx::Stream *pStream; // esi
  int v5; // ecx
  unsigned int Pos; // eax
  char v7; // cl

  for ( i = 0; i < size; ++i )
  {
    pStream = this->pStream;
    v5 = pStream->DataSize - pStream->Pos;
    pStream->UnusedBits = 0;
    if ( v5 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(pStream, 1);
    Pos = pStream->Pos;
    v7 = pStream->pBuffer[Pos];
    pStream->Pos = Pos + 1;
    pbuffer[i] = v7;
  }
}
