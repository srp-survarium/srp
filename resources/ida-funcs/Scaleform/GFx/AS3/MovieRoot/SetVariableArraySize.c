char __thiscall Scaleform::GFx::AS3::MovieRoot::SetVariableArraySize(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *ppathToVar,
        unsigned int count,
        Scaleform::GFx::Movie::SetVarType setType)
{
  const char *v4; // ebp
  int v6; // eax
  const char *v8; // ebx
  bool v9; // bl
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  void *v11; // eax
  Scaleform::GFx::AS3::Value val; // [esp+18h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value retVal; // [esp+28h] [ebp-28h] BYREF
  Scaleform::GFx::Value gfxval; // [esp+38h] [ebp-18h] BYREF

  v4 = ppathToVar;
  retVal.Flags = 0;
  retVal.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &retVal, ppathToVar)
    && (retVal.Flags & 0x1F) - 12 <= 3
    && retVal.value.VS._1.VInt
    && (v6 = *(_DWORD *)(retVal.value.VS._1.VInt + 20), *(_DWORD *)(v6 + 60) == 7)
    && (*(_DWORD *)(v6 + 56) & 0x20) == 0 )
  {
    if ( count != *(_DWORD *)(retVal.value.VS._1.VInt + 32) )
      Scaleform::GFx::AS3::Impl::SparseArray::Resize(
        (Scaleform::GFx::AS3::Impl::SparseArray *)(retVal.value.VS._1.VInt + 32),
        count);
    Scaleform::GFx::AS3::Value::~Value(&retVal);
    return 1;
  }
  else
  {
    Scaleform::GFx::AS3::VM::MakeArray(
      this->pAVM.pObject,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&ppathToVar);
    v8 = ppathToVar;
    Scaleform::GFx::AS3::Impl::SparseArray::Resize((Scaleform::GFx::AS3::Impl::SparseArray *)(ppathToVar + 32), count);
    val.Bonus.pWeakProxy = 0;
    val.Flags = 12;
    *(_QWORD *)&val.value.VNumber = (unsigned int)v8;
    gfxval.pObjectInterface = 0;
    gfxval.Type = VT_Undefined;
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &val, (Scaleform::GFx::ASStringNode *)&gfxval);
    v9 = this->SetVariable(this, v4, &gfxval, setType);
    if ( (gfxval.Type & 0x40) != 0 )
    {
      gfxval.pObjectInterface->ObjectRelease(gfxval.pObjectInterface, &gfxval, (void *)gfxval.mValue.IValue);
      gfxval.pObjectInterface = 0;
    }
    gfxval.Type = VT_Undefined;
    if ( (val.Flags & 0x1F) > 9 )
    {
      if ( (val.Flags & 0x200) != 0 )
      {
        pWeakProxy = val.Bonus.pWeakProxy;
        --val.Bonus.pWeakProxy->RefCount;
        if ( !pWeakProxy->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        val.Flags &= 0xFFFFFDE0;
        memset(&val.Bonus, 0, 12);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
      }
    }
    if ( (retVal.Flags & 0x1F) > 9 )
    {
      if ( (retVal.Flags & 0x200) != 0 )
      {
        v11 = retVal.Bonus.pWeakProxy;
        if ( retVal.Bonus.pWeakProxy->RefCount-- == 1 )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
          return v9;
        }
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&retVal);
      }
    }
    return v9;
  }
}
