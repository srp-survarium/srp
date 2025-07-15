char __thiscall Scaleform::Render::SIF::SIFFileImageSource::ReadHeader(
        Scaleform::Render::SIF::SIFFileImageSource *this)
{
  Scaleform::File *pObject; // ecx
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::File *v5; // ecx
  int (__thiscall *v6)(Scaleform::File *, unsigned __int8 *, int); // eax
  Scaleform::Render::ImageFormat v7; // eax
  Scaleform::File *v8; // ecx
  int (__thiscall *v9)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::File *v10; // ecx
  int (__thiscall *v11)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::File *v12; // ecx
  int (__thiscall *v13)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::File *v14; // ecx
  int (__thiscall *v15)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::File *v16; // ecx
  int (__thiscall *v17)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::File *v18; // ecx
  int (__thiscall *v19)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v20; // eax
  unsigned int Width; // ecx
  unsigned __int8 v22; // [esp+47h] [ebp-9h] BYREF
  unsigned __int32 v23; // [esp+48h] [ebp-8h] BYREF
  char first[4]; // [esp+4Ch] [ebp-4h] BYREF

  this->pFile.pObject->Read(this->pFile.pObject, (unsigned __int8 *)first, 4);
  if ( strncmp(first, "SIF ", 4u) )
    return 0;
  pObject = this->pFile.pObject;
  Read = pObject->Read;
  v22 = 0;
  Read(pObject, &v22, 1);
  if ( v22 != 17 )
    return 0;
  v5 = this->pFile.pObject;
  v6 = v5->Read;
  v23 = 0;
  v6(v5, (unsigned __int8 *)&v23, 4);
  v7 = v23;
  v8 = this->pFile.pObject;
  this->Format = v23;
  this->HeaderInfo.Format = v7;
  v9 = v8->Read;
  v23 = 0;
  v9(v8, (unsigned __int8 *)&v23, 4);
  v10 = this->pFile.pObject;
  this->Use = v23;
  v11 = v10->Read;
  v22 = 0;
  v11(v10, &v22, 1);
  v12 = this->pFile.pObject;
  this->HeaderInfo.Flags = v22 & 0xFD;
  v13 = v12->Read;
  v22 = 0;
  v13(v12, &v22, 1);
  v14 = this->pFile.pObject;
  this->HeaderInfo.LevelCount = v22;
  v15 = v14->Read;
  v23 = 0;
  v15(v14, (unsigned __int8 *)&v23, 2);
  v16 = this->pFile.pObject;
  this->HeaderInfo.RawPlaneCount = v23;
  v17 = v16->Read;
  v23 = 0;
  v17(v16, (unsigned __int8 *)&v23, 4);
  v18 = this->pFile.pObject;
  this->HeaderInfo.Width = v23;
  v19 = v18->Read;
  v23 = 0;
  v19(v18, (unsigned __int8 *)&v23, 4);
  v20 = v23;
  Width = this->HeaderInfo.Width;
  this->HeaderInfo.Height = v23;
  this->Size.Width = Width;
  this->Size.Height = v20;
  this->FilePos = this->pFile.pObject->LTell(this->pFile.pObject);
  return 1;
}
