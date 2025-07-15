void __thiscall Scaleform::GFx::AMP::MessageSwdFile::Read(Scaleform::GFx::AMP::MessageSwdFile *this, unsigned int str)
{
  Scaleform::File *v2; // esi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v5; // ebp
  int (__thiscall *v6)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int Size; // eax
  unsigned int v8; // ebx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *p_FileData; // edi
  int (__thiscall *v10)(Scaleform::File *, unsigned __int8 *, int); // edx

  v2 = (Scaleform::File *)str;
  Scaleform::GFx::AMP::Message::Read(this, (Scaleform::String)str);
  Read = v2->Read;
  v5 = 0;
  str = 0;
  Read(v2, (unsigned __int8 *)&str, 4);
  this->Handle = str;
  v6 = v2->Read;
  str = 0;
  v6(v2, (unsigned __int8 *)&str, 4);
  Size = this->FileData.Data.Size;
  v8 = str;
  p_FileData = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->FileData;
  if ( str >= Size )
  {
    if ( str >= p_FileData->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_FileData,
        p_FileData,
        str + (str >> 2));
  }
  else if ( str < p_FileData->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_FileData,
      p_FileData,
      str);
  }
  p_FileData->Size = v8;
  if ( v8 )
  {
    do
    {
      v10 = v2->Read;
      LOBYTE(str) = 0;
      v10(v2, (unsigned __int8 *)&str, 1);
      p_FileData->Data[v5++] = str;
    }
    while ( v5 < v8 );
  }
  Scaleform::GFx::AMP::Message::ReadString(v2, &this->Filename);
}
