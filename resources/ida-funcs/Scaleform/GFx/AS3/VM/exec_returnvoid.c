void __thiscall Scaleform::GFx::AS3::VM::exec_returnvoid(Scaleform::GFx::AS3::VM *this)
{
  bool v2; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // esi

  if ( !this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(this->CallStack.Size - 1) & 0x3F].DiscardResult )
  {
    if ( (_S15 & 1) == 0 )
    {
      _S15 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    v2 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
    pCurrent = this->OpStack.pCurrent;
    if ( !v2 )
    {
      *pCurrent = v;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
          ++v.Bonus.pWeakProxy->RefCount;
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(&v);
      }
    }
  }
}
