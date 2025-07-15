void __thiscall Scaleform::GFx::AMP::MovieInstructionStats::ScriptBufferStats::Write(
        Scaleform::GFx::AMP::MovieInstructionStats::ScriptBufferStats *this,
        Scaleform::File *str,
        unsigned int version)
{
  Scaleform::File *v3; // esi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v6)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v7)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v8)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int v9; // ebp
  int v10; // ebx
  int (__thiscall *v11)(Scaleform::File *, const unsigned __int8 *, int); // edx
  Scaleform::GFx::AMP::MovieInstructionStats::InstructionTimePair *Data; // eax
  int Time; // ecx
  int Time_high; // edx
  Scaleform::File_vtbl *v15; // eax
  _DWORD v16[2]; // [esp+28h] [ebp-8h] BYREF

  v3 = str;
  Write = str->Write;
  v16[0] = this->SwdHandle;
  Write(str, (const unsigned __int8 *)v16, 4);
  v6 = v3->Write;
  str = (Scaleform::File *)this->BufferOffset;
  v6(v3, (const unsigned __int8 *)&str, 4);
  v7 = v3->Write;
  str = (Scaleform::File *)this->BufferLength;
  v7(v3, (const unsigned __int8 *)&str, 4);
  v8 = v3->Write;
  str = (Scaleform::File *)this->InstructionTimesArray.Data.Size;
  v8(v3, (const unsigned __int8 *)&str, 4);
  v9 = 0;
  if ( this->InstructionTimesArray.Data.Size )
  {
    v10 = 0;
    do
    {
      v11 = v3->Write;
      str = (Scaleform::File *)this->InstructionTimesArray.Data.Data[v10].Offset;
      v11(v3, (const unsigned __int8 *)&str, 4);
      Data = this->InstructionTimesArray.Data.Data;
      Time = Data[v10].Time;
      Time_high = HIDWORD(Data[v10].Time);
      v15 = v3->__vftable;
      v16[0] = Time;
      v16[1] = Time_high;
      v15->Write(v3, (const unsigned __int8 *)v16, 8);
      ++v9;
      ++v10;
    }
    while ( v9 < this->InstructionTimesArray.Data.Size );
  }
}
