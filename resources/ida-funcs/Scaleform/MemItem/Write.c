void __thiscall Scaleform::MemItem::Write(Scaleform::MemItem *this, Scaleform::File *str, unsigned int version)
{
  Scaleform::StringLH *p_Name; // ebp
  int Length; // eax
  Scaleform::File *v6; // esi
  unsigned int i; // ebx
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v9)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v10)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v11)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v12)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int v13; // ebp
  int (__thiscall *v14)(Scaleform::File *, const unsigned __int8 *, int); // edx
  Scaleform::MemItemExtra *pObject; // eax
  int (__thiscall *v16)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int j; // ebx
  int v18; // [esp+1Ch] [ebp-18h]
  int v19; // [esp+30h] [ebp-4h] BYREF

  p_Name = &this->Name;
  Length = Scaleform::String::GetLength(&this->Name);
  v6 = str;
  v19 = Length;
  str->Write(str, (const unsigned __int8 *)&v19, 4);
  for ( i = 0; i < Scaleform::String::GetLength(p_Name); ++i )
  {
    Write = v6->Write;
    LOBYTE(str) = *(_BYTE *)((p_Name->HeapTypeBits & 0xFFFFFFFC) + i + 8);
    Write(v6, (const unsigned __int8 *)&str, 1);
  }
  v9 = v6->Write;
  LOBYTE(str) = this->HasValue;
  v9(v6, (const unsigned __int8 *)&str, 1);
  v10 = v6->Write;
  LOBYTE(str) = this->StartExpanded;
  v10(v6, (const unsigned __int8 *)&str, 1);
  v11 = v6->Write;
  str = (Scaleform::File *)this->Value;
  v11(v6, (const unsigned __int8 *)&str, 4);
  v12 = v6->Write;
  str = (Scaleform::File *)this->ID;
  v12(v6, (const unsigned __int8 *)&str, 4);
  v13 = version;
  if ( version <= 0xB )
  {
    pObject = this->ImageExtraData.pObject;
    v18 = 4;
    v14 = v6->Write;
    if ( pObject )
      str = (Scaleform::File *)pObject->ImageId;
    else
      str = 0;
  }
  else
  {
    v14 = v6->Write;
    v18 = 1;
    if ( this->ImageExtraData.pObject )
    {
      LOBYTE(str) = 1;
      v14(v6, (const unsigned __int8 *)&str, 1);
      Scaleform::MemItemExtra::Write(this->ImageExtraData.pObject, v6, v13);
      goto LABEL_11;
    }
    LOBYTE(str) = 0;
  }
  ((void (__stdcall *)(Scaleform::File **, int))v14)(&str, v18);
LABEL_11:
  v16 = v6->Write;
  str = (Scaleform::File *)this->Children.Data.Size;
  v16(v6, (const unsigned __int8 *)&str, 4);
  for ( j = 0; j < this->Children.Data.Size; ++j )
    Scaleform::MemItem::Write(this->Children.Data.Data[j].pObject, v6, v13);
}
