int __thiscall Scaleform::BufferedFile::GetLength(Scaleform::BufferedFile *this)
{
  int result; // eax
  int v3; // edi

  result = this->pFile.pObject->GetLength(this->pFile.pObject);
  v3 = result;
  if ( result != -1 && this->BufferMode == WriteBuffer )
  {
    result = this->Pos + this->pFile.pObject->Tell(this->pFile.pObject);
    if ( result <= v3 )
      return v3;
  }
  return result;
}
