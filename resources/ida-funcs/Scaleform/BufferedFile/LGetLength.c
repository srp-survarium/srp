unsigned int __thiscall Scaleform::BufferedFile::LGetLength(Scaleform::BufferedFile *this)
{
  __int64 v2; // rax
  unsigned int v3; // edi
  unsigned int v4; // ebx
  __int64 v5; // rax

  v2 = this->pFile.pObject->LGetLength(this->pFile.pObject);
  v3 = HIDWORD(v2);
  v4 = v2;
  if ( (HIDWORD(v2) & (unsigned int)v2) != 0xFFFFFFFF && this->BufferMode == WriteBuffer )
  {
    v5 = this->Pos + this->pFile.pObject->LTell(this->pFile.pObject);
    if ( v5 > __SPAIR64__(v3, v4) )
      return v5;
  }
  return v4;
}
