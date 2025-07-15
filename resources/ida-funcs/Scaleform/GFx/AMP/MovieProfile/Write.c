void __thiscall Scaleform::GFx::AMP::MovieProfile::Write(
        Scaleform::GFx::AMP::MovieProfile *this,
        Scaleform::File *str,
        unsigned int version)
{
  Scaleform::File *v3; // esi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v6)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v7)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int v8; // ebp
  int (__thiscall *v9)(Scaleform::File *, const unsigned __int8 *, int); // edx
  Scaleform::File_vtbl *v10; // eax
  Scaleform::File_vtbl *v11; // eax
  Scaleform::File_vtbl *v12; // eax
  int (__thiscall *v13)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v14)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int i; // ebx
  int (__thiscall *v16)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int v17; // [esp+34h] [ebp-10h]
  unsigned int v18; // [esp+38h] [ebp-Ch]
  unsigned int ViewHandle; // [esp+40h] [ebp-4h] BYREF

  v3 = str;
  Write = str->Write;
  ViewHandle = this->ViewHandle;
  Write(str, (const unsigned __int8 *)&ViewHandle, 4);
  v6 = v3->Write;
  str = (Scaleform::File *)this->MinFrame;
  v6(v3, (const unsigned __int8 *)&str, 4);
  v7 = v3->Write;
  str = (Scaleform::File *)this->MaxFrame;
  v7(v3, (const unsigned __int8 *)&str, 4);
  v8 = version;
  if ( version >= 4 )
  {
    Scaleform::GFx::AMP::writeString(v3, &this->ViewName);
    v9 = v3->Write;
    str = (Scaleform::File *)this->Version;
    v9(v3, (const unsigned __int8 *)&str, 4);
    v10 = v3->__vftable;
    str = (Scaleform::File *)LODWORD(this->Width);
    v10->Write(v3, (const unsigned __int8 *)&str, 4);
    v11 = v3->__vftable;
    str = (Scaleform::File *)LODWORD(this->Height);
    v11->Write(v3, (const unsigned __int8 *)&str, 4);
    v12 = v3->__vftable;
    str = (Scaleform::File *)LODWORD(this->FrameRate);
    v12->Write(v3, (const unsigned __int8 *)&str, 4);
    v13 = v3->Write;
    str = (Scaleform::File *)this->FrameCount;
    v13(v3, (const unsigned __int8 *)&str, 4);
  }
  if ( v8 >= 6 )
  {
    v14 = v3->Write;
    str = (Scaleform::File *)this->Markers.Data.Size;
    v14(v3, (const unsigned __int8 *)&str, 4);
    for ( i = 0; i < this->Markers.Data.Size; ++i )
    {
      if ( v8 >= 0xB )
        Scaleform::GFx::AMP::writeString(v3, &this->Markers.Data.Data[i].pObject->Name);
      v16 = v3->Write;
      str = (Scaleform::File *)this->Markers.Data.Data[i].pObject->Number;
      v16(v3, (const unsigned __int8 *)&str, 4);
    }
  }
  Scaleform::GFx::AMP::MovieInstructionStats::Write(this->InstructionStats.pObject, v3, v8);
  Scaleform::GFx::AMP::MovieFunctionStats::Write(this->FunctionStats.pObject, v3, v8);
  Scaleform::GFx::AMP::MovieSourceLineStats::Write(this->SourceLineStats.pObject, (int)this, (int)v3, v3, v8, v17, v18);
  if ( v8 >= 0x19 )
    Scaleform::GFx::AMP::MovieFunctionTreeStats::Write(this->FunctionTreeStats.pObject, v3, v8);
}
