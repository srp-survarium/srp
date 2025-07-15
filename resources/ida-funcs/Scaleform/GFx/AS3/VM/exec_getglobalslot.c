void __thiscall Scaleform::GFx::AS3::VM::exec_getglobalslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_index)
{
  Scaleform::GFx::AS3::Value *pCurrent; // ebp
  Scaleform::GFx::ASStringNode *GlobalObject; // edi
  unsigned int Size; // ecx
  signed int v7; // eax
  unsigned int v8; // esi
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // eax

  if ( (_S15 & 1) == 0 )
  {
    _S15 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  if ( this->OpStack.pCurrent++ != (Scaleform::GFx::AS3::Value *)-16 )
  {
    *this->OpStack.pCurrent = v;
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
        ++v.Bonus.pWeakProxy->RefCount;
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(&v);
    }
  }
  pCurrent = this->OpStack.pCurrent;
  GlobalObject = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::VM::GetGlobalObject(this);
  Size = GlobalObject->Size;
  v7 = *(_DWORD *)(Size + 44) + slot_index - 1;
  if ( v7 >= 0 && (v8 = *(_DWORD *)(Size + 20), v7 >= v8) )
  {
    Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(
      (Scaleform::GFx::AS3::SlotInfo *)(32 * (v7 - v8) + *(_DWORD *)(Size + 28) + 8),
      (Scaleform::GFx::AS3::CheckResult *)&slot_index,
      pCurrent,
      GlobalObject);
  }
  else
  {
    SlotInfo = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                  *(Scaleform::GFx::AS3::Slots **)(Size + 24),
                                                  (Scaleform::GFx::AS3::AbsoluteIndex)v7);
    Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(
      SlotInfo,
      (Scaleform::GFx::AS3::CheckResult *)&slot_index,
      pCurrent,
      GlobalObject);
  }
}
