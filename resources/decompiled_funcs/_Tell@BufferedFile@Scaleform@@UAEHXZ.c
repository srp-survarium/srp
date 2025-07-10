unsigned int __thiscall Scaleform::BufferedFile::Tell(Scaleform::BufferedFile *this)
{
  unsigned int result; // eax

  if ( this->BufferMode == ReadBuffer )
    return this->Pos + LODWORD(this->FilePos) - this->DataSize;
  result = this->pFile.pObject->Tell(this->pFile.pObject);
  if ( result != -1 && this->BufferMode == WriteBuffer )
    result += this->Pos;
  return result;
}
