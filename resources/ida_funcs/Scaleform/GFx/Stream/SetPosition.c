void __thiscall Scaleform::GFx::Stream::SetPosition(Scaleform::GFx::Stream *this, int pos)
{
  signed int FilePos; // edx
  unsigned int DataSize; // eax

  FilePos = this->FilePos;
  DataSize = this->DataSize;
  this->UnusedBits = 0;
  if ( pos < (int)(FilePos - DataSize) || pos >= FilePos )
  {
    if ( (this->ResyncFile || FilePos - DataSize + this->Pos != pos)
      && this->pInput.pObject->Seek(this->pInput.pObject, pos, 0) >= 0 )
    {
      this->ResyncFile = 0;
      this->Pos = 0;
      this->DataSize = 0;
      this->FilePos = pos;
    }
  }
  else
  {
    this->Pos = pos + DataSize - FilePos;
  }
}
