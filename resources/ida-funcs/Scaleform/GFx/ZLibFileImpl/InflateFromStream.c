unsigned int __thiscall Scaleform::GFx::ZLibFileImpl::InflateFromStream(
        Scaleform::GFx::ZLibFileImpl *this,
        unsigned __int8 *dst,
        unsigned int bytes)
{
  unsigned int result; // eax
  unsigned int v5; // eax
  int v6; // eax

  if ( this->ErrorCode )
    return 0;
  this->ZStream.next_out = dst;
  this->ZStream.avail_out = bytes;
  while ( 1 )
  {
    if ( !this->ZStream.avail_in )
    {
      v5 = ((int (__stdcall *)(unsigned __int8 *, int))this->pIn.pObject->Read)(this->DataBuffer, 4096);
      if ( !v5 )
        goto LABEL_13;
      this->ZStream.next_in = this->DataBuffer;
      this->ZStream.avail_in = v5;
    }
    v6 = inflate(&this->ZStream, 2);
    if ( v6 == 1 )
    {
      result = bytes - this->ZStream.avail_out;
      this->LogicalStreamPos += result;
      this->AtEofFlag = 1;
      return result;
    }
    if ( v6 )
      break;
    if ( !this->ZStream.avail_out )
    {
      result = bytes - this->ZStream.avail_out;
      this->LogicalStreamPos += result;
      return result;
    }
  }
  this->ErrorCode = 1;
LABEL_13:
  result = bytes - this->ZStream.avail_out;
  this->LogicalStreamPos += result;
  return result;
}
