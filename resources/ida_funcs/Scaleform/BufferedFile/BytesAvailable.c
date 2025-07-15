int __thiscall Scaleform::BufferedFile::BytesAvailable(Scaleform::BufferedFile *this)
{
  int result; // eax

  result = this->pFile.pObject->BytesAvailable(this->pFile.pObject);
  if ( this->BufferMode == ReadBuffer )
  {
    result += this->DataSize - this->Pos;
  }
  else if ( this->BufferMode == WriteBuffer )
  {
    result -= this->Pos;
    if ( result < 0 )
      return 0;
  }
  return result;
}
