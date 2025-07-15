void __thiscall Scaleform::GFx::AMP::MovieInstructionStats::ScriptBufferStats::Read(
        Scaleform::GFx::AMP::MovieInstructionStats::ScriptBufferStats *this,
        unsigned int str,
        unsigned int version)
{
  unsigned int v3; // esi
  void (__thiscall *v4)(unsigned int, unsigned int *, int); // edx
  void (__thiscall *v6)(unsigned int, unsigned int *, int); // edx
  void (__thiscall *v7)(unsigned int, unsigned int *, int); // edx
  void (__thiscall *v8)(unsigned int, unsigned int *, int); // edx
  unsigned int v9; // edi
  Scaleform::ArrayLH<Scaleform::GFx::AMP::MovieInstructionStats::InstructionTimePair,2,Scaleform::ArrayDefaultPolicy> *p_InstructionTimesArray; // ebx
  int v11; // edi
  void (__thiscall *v12)(unsigned int, unsigned int *, int); // edx
  void (__thiscall *v13)(unsigned int, int *, int); // edx
  Scaleform::GFx::AMP::MovieInstructionStats::InstructionTimePair *Data; // eax
  unsigned int i; // [esp+30h] [ebp-Ch] BYREF
  int v16; // [esp+34h] [ebp-8h] BYREF
  int v17; // [esp+38h] [ebp-4h]

  v3 = str;
  v4 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)str + 40);
  i = 0;
  v4(str, &i, 4);
  this->SwdHandle = i;
  v6 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 40);
  str = 0;
  v6(v3, &str, 4);
  this->BufferOffset = str;
  v7 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 40);
  str = 0;
  v7(v3, &str, 4);
  this->BufferLength = str;
  v8 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 40);
  str = 0;
  v8(v3, &str, 4);
  v9 = str;
  p_InstructionTimesArray = &this->InstructionTimesArray;
  if ( str >= this->InstructionTimesArray.Data.Size )
  {
    if ( str >= this->InstructionTimesArray.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&this->InstructionTimesArray,
        &this->InstructionTimesArray,
        str + (str >> 2));
  }
  else if ( str < this->InstructionTimesArray.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&this->InstructionTimesArray,
      &this->InstructionTimesArray,
      str);
  }
  this->InstructionTimesArray.Data.Size = v9;
  v11 = 0;
  for ( i = 0; i < this->InstructionTimesArray.Data.Size; ++i )
  {
    v12 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 40);
    str = 0;
    v12(v3, &str, 4);
    p_InstructionTimesArray->Data.Data[v11].Offset = str;
    v13 = *(void (__thiscall **)(unsigned int, int *, int))(*(_DWORD *)v3 + 40);
    v16 = 0;
    v17 = 0;
    v13(v3, &v16, 8);
    Data = p_InstructionTimesArray->Data.Data;
    LODWORD(Data[v11].Time) = v16;
    HIDWORD(Data[v11++].Time) = v17;
  }
}
