void __thiscall Scaleform::GFx::AMP::FuncTreeItem::Write(
        Scaleform::GFx::AMP::FuncTreeItem *this,
        Scaleform::File *str,
        unsigned int version)
{
  int FunctionId; // eax
  int FunctionId_high; // ecx
  Scaleform::File *v6; // edi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int BeginTime_high; // ecx
  int (__thiscall *v9)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int EndTime_high; // ecx
  int (__thiscall *v11)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v12)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v13)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int v14; // ebx
  unsigned int v15; // ebp
  int BeginTime; // [esp+18h] [ebp-8h] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  FunctionId = this->FunctionId;
  FunctionId_high = HIDWORD(this->FunctionId);
  v6 = str;
  Write = str->Write;
  BeginTime = FunctionId;
  v17 = FunctionId_high;
  Write(str, (const unsigned __int8 *)&BeginTime, 8);
  BeginTime_high = HIDWORD(this->BeginTime);
  v9 = v6->Write;
  BeginTime = this->BeginTime;
  v17 = BeginTime_high;
  v9(v6, (const unsigned __int8 *)&BeginTime, 8);
  EndTime_high = HIDWORD(this->EndTime);
  v11 = v6->Write;
  BeginTime = this->EndTime;
  v17 = EndTime_high;
  v11(v6, (const unsigned __int8 *)&BeginTime, 8);
  v12 = v6->Write;
  str = (Scaleform::File *)this->TreeItemId;
  v12(v6, (const unsigned __int8 *)&str, 4);
  v13 = v6->Write;
  str = (Scaleform::File *)this->Children.Data.Size;
  v13(v6, (const unsigned __int8 *)&str, 4);
  v14 = 0;
  if ( this->Children.Data.Size )
  {
    v15 = version;
    do
      Scaleform::GFx::AMP::FuncTreeItem::Write(this->Children.Data.Data[v14++].pObject, v6, v15);
    while ( v14 < this->Children.Data.Size );
  }
}
