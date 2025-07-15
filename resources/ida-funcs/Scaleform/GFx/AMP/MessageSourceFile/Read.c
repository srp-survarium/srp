void __thiscall Scaleform::GFx::AMP::MessageSourceFile::Read(
        Scaleform::GFx::AMP::MessageSourceFile *this,
        unsigned int str)
{
  Scaleform::File *v2; // esi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v5; // edi
  int v6; // ecx
  int (__thiscall *v7)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int Size; // eax
  unsigned int v9; // ebx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *p_FileData; // ebp
  int (__thiscall *v11)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v13; // [esp+1Ch] [ebp-8h] BYREF
  int v14; // [esp+20h] [ebp-4h]

  v2 = (Scaleform::File *)str;
  Scaleform::GFx::AMP::Message::Read(this, (Scaleform::String)str);
  Read = v2->Read;
  v5 = 0;
  v13 = 0;
  v14 = 0;
  Read(v2, (unsigned __int8 *)&v13, 8);
  v6 = v14;
  LODWORD(this->FileHandle) = v13;
  HIDWORD(this->FileHandle) = v6;
  v7 = v2->Read;
  str = 0;
  v7(v2, (unsigned __int8 *)&str, 4);
  Size = this->FileData.Data.Size;
  v9 = str;
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
  p_FileData->Size = v9;
  if ( v9 )
  {
    do
    {
      v11 = v2->Read;
      LOBYTE(str) = 0;
      v11(v2, (unsigned __int8 *)&str, 1);
      p_FileData->Data[v5++] = str;
    }
    while ( v5 < v9 );
  }
  Scaleform::GFx::AMP::Message::ReadString(v2, &this->Filename);
}
