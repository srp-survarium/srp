void __thiscall Scaleform::GFx::ZLibFileImpl::Reset(Scaleform::GFx::ZLibFileImpl *this)
{
  z_stream_s *p_ZStream; // edi
  Scaleform::File *pObject; // ecx
  int InitialStreamPos; // edx

  p_ZStream = &this->ZStream;
  this->ErrorCode = 0;
  this->AtEofFlag = 0;
  if ( inflateReset(&this->ZStream) )
  {
    this->ErrorCode = 1;
  }
  else
  {
    pObject = this->pIn.pObject;
    InitialStreamPos = this->InitialStreamPos;
    p_ZStream->next_in = 0;
    this->ZStream.avail_in = 0;
    this->ZStream.next_out = 0;
    this->ZStream.avail_out = 0;
    pObject->Seek(pObject, InitialStreamPos, 0);
    this->LogicalStreamPos = 0;
    this->BacktrackSize = 0;
    this->BacktrackTail = 0;
    this->UserPos = 0;
  }
}
