void __thiscall Scaleform::GFx::Stream::SyncFileStream(Scaleform::GFx::Stream *this)
{
  unsigned int v2; // eax

  v2 = this->pInput.pObject->Seek(this->pInput.pObject, this->Pos + this->FilePos - this->DataSize, 0);
  if ( v2 != -1 )
  {
    this->Pos = 0;
    this->FilePos = v2;
    this->DataSize = 0;
  }
}
