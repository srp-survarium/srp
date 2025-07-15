bool __thiscall Scaleform::Render::DDS::DDSFileImageSource::ReadHeader(
        Scaleform::Render::DDS::DDSFileImageSource *this)
{
  bool result; // al
  Scaleform::File *pObject; // ecx
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int Height; // ecx
  int v6; // [esp+10h] [ebp-108h] BYREF
  int v7; // [esp+14h] [ebp-104h] BYREF
  unsigned __int8 buf[256]; // [esp+18h] [ebp-100h] BYREF

  this->pFile.pObject->Read(this->pFile.pObject, (unsigned __int8 *)&v7, 4);
  if ( v7 != 542327876 )
    return 0;
  pObject = this->pFile.pObject;
  Read = pObject->Read;
  v6 = 0;
  Read(pObject, (unsigned __int8 *)&v6, 4);
  if ( v6 != 124 || this->pFile.pObject->Read(this->pFile.pObject, buf, 120) != 120 )
    return 0;
  result = Scaleform::Render::DDS::Image_ParseDDSHeader(&this->HeaderInfo, buf, 0);
  if ( result )
  {
    this->HeaderInfo.OppositeEndian = 0;
    Scaleform::Render::DDS::DDSDescr::CalcShifts(&this->HeaderInfo.DDSFmt);
    if ( this->Format == Image_None )
      this->Format = this->HeaderInfo.Format;
    Height = this->HeaderInfo.Height;
    this->Size.Width = this->HeaderInfo.Width;
    this->Size.Height = Height;
    this->FilePos = this->pFile.pObject->LTell(this->pFile.pObject);
    return 1;
  }
  return result;
}
