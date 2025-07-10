int __thiscall Scaleform::BufferedFile::Close(Scaleform::BufferedFile *this)
{
  if ( this->BufferMode == ReadBuffer )
  {
    this->BufferMode = NoBuffer;
  }
  else if ( this->BufferMode == WriteBuffer )
  {
    Scaleform::BufferedFile::FlushBuffer(this);
  }
  return ((int (__thiscall *)(Scaleform::File *))this->pFile.pObject->Close)(this->pFile.pObject);
}
