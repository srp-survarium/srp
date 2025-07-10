void __thiscall Scaleform::GFx::AS3::VM::exec_getglobalslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_index)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *GlobalObject; // eax
  Scaleform::GFx::AS3::SlotIndex v5; // [esp-8h] [ebp-Ch]
  Scaleform::GFx::AS3::Value *pCurrent; // [esp-4h] [ebp-8h]

  if ( (_S10_0 & 1) == 0 )
  {
    _S10_0 |= 1u;
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
  v5.Index = slot_index;
  GlobalObject = Scaleform::GFx::AS3::VM::GetGlobalObject(this);
  Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(
    GlobalObject,
    (Scaleform::GFx::AS3::CheckResult *)&slot_index,
    v5,
    pCurrent);
}
