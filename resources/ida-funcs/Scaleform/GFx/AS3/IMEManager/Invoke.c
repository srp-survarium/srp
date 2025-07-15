bool __userpurge Scaleform::GFx::AS3::IMEManager::Invoke@<al>(
        Scaleform::GFx::AS3::IMEManager *this@<ecx>,
        int a2@<edi>,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        const Scaleform::GFx::Value *pargFmt,
        unsigned int numArgs,
        int a7)
{
  char *v8; // ebx
  unsigned int v9; // esi
  char *v10; // edi
  Scaleform::GFx::Value *p_CandListVal; // ebp
  char *v12; // esi
  bool i; // al
  int v14; // eax
  Scaleform::GFx::Value mem; // [esp+3Ch] [ebp-30h] BYREF
  Scaleform::GFx::Value func; // [esp+54h] [ebp-18h] BYREF

  v8 = 0;
  if ( this->pMovie && (this->CandListVal.Type & 0x8Fu) >= 2 )
  {
    v9 = strlen(pmethodName);
    v10 = (char *)((int (__thiscall *)(Scaleform::MemoryHeap *, unsigned int, _DWORD, int))Scaleform::Memory::pGlobalHeap->Alloc)(
                    Scaleform::Memory::pGlobalHeap,
                    v9 + 1,
                    0,
                    a2);
    mem.pObjectInterface = 0;
    memcpy((int)v10, (const __m128i *)presult, v9);
    v10[v9] = 0;
    p_CandListVal = &this->CandListVal;
    v12 = strtok_s(0, v10, ".", (char **)&mem);
    Scaleform::GFx::Value::Value((Scaleform::GFx::Value *)&mem.Type, p_CandListVal);
    Scaleform::GFx::Value::Value((Scaleform::GFx::Value *)&func.Type, p_CandListVal);
    for ( i = mem.mValue.BValue; (mem.mValue.BValue & 0x8F) != 1; i = mem.mValue.BValue )
    {
      if ( !v12 )
        break;
      Scaleform::GFx::Value::operator=((Scaleform::GFx::Value *)&mem.Type, (const Scaleform::GFx::Value *)&func.Type);
      v8 = v12;
      (*(void (__thiscall **)(Scaleform::GFx::Value::ValueType, _DWORD, char *, Scaleform::GFx::Value::ValueType *, bool))(*(_DWORD *)mem.Type + 16))(
        mem.Type,
        *((_DWORD *)&mem.mValue.BValue + 1),
        v12,
        &func.Type,
        (mem.mValue.BValue & 0x8F) == 10);
      v12 = strtok_s((int)v12, 0, ".", (char **)&mem);
    }
    v14 = i & 0x8F;
    if ( v14 != 1 )
      (*(void (__thiscall **)(Scaleform::GFx::Value::ValueType, _DWORD, const Scaleform::GFx::Value *, char *, unsigned int, int, bool))(*(_DWORD *)mem.Type + 24))(
        mem.Type,
        *((_DWORD *)&mem.mValue.BValue + 1),
        pargFmt,
        v8,
        numArgs,
        a7,
        v14 == 10);
    ((void (__thiscall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->Free)(Scaleform::Memory::pGlobalHeap);
    if ( (func.Type & 0x40) != 0 )
    {
      func.pObjectInterface->ObjectRelease(func.pObjectInterface, &func, (void *)func.mValue.IValue);
      func.pObjectInterface = 0;
    }
    func.Type = VT_Undefined;
    if ( (mem.Type & 0x40) != 0 )
      mem.pObjectInterface->ObjectRelease(mem.pObjectInterface, &mem, (void *)mem.mValue.IValue);
  }
  return 0;
}
