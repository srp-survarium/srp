int __thiscall Scaleform::SysFile::GetErrorCode(Scaleform::SysFile *this)
{
  Scaleform::File *pObject; // ecx

  pObject = this->pFile.pObject;
  if ( pObject )
    return pObject->GetErrorCode(pObject);
  else
    return 4097;
}
