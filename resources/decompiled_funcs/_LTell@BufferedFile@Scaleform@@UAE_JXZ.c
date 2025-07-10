unsigned __int64 __thiscall Scaleform::BufferedFile::LTell(Scaleform::BufferedFile *this)
{
  unsigned __int64 result; // rax

  if ( this->BufferMode == ReadBuffer )
    return this->FilePos + this->Pos - (unsigned __int64)this->DataSize;
  result = this->pFile.pObject->LTell(this->pFile.pObject);
  if ( (HIDWORD(result) & (unsigned int)result) != 0xFFFFFFFF && this->BufferMode == WriteBuffer )
    result += this->Pos;
  return result;
}
