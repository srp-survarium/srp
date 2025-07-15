void __thiscall Scaleform::GFx::AS3::ReadArgs::ReadArgs(
        Scaleform::GFx::AS3::ReadArgs *this,
        Scaleform::GFx::AS3::VM *vm,
        unsigned int arg_count)
{
  const Scaleform::MemoryHeap *MHeap; // edx
  int *p_CallArgs; // edi
  Scaleform::GFx::AS3::ValueStack *opstack; // [esp+Ch] [ebp+4h]

  this->VMRef = vm;
  this->ArgNum = arg_count;
  this->OpStack = &vm->OpStack;
  this->FixedArr[0].Flags = 0;
  this->FixedArr[0].Bonus.pWeakProxy = 0;
  this->FixedArr[1].Flags = 0;
  this->FixedArr[1].Bonus.pWeakProxy = 0;
  this->FixedArr[2].Flags = 0;
  this->FixedArr[2].Bonus.pWeakProxy = 0;
  this->FixedArr[3].Flags = 0;
  this->FixedArr[3].Bonus.pWeakProxy = 0;
  this->FixedArr[4].Flags = 0;
  this->FixedArr[4].Bonus.pWeakProxy = 0;
  this->FixedArr[5].Flags = 0;
  this->FixedArr[5].Bonus.pWeakProxy = 0;
  this->FixedArr[6].Flags = 0;
  this->FixedArr[6].Bonus.pWeakProxy = 0;
  this->FixedArr[7].Flags = 0;
  this->FixedArr[7].Bonus.pWeakProxy = 0;
  MHeap = vm->MHeap;
  p_CallArgs = (int *)&this->CallArgs;
  this->CallArgs.Data.Data = 0;
  this->CallArgs.Data.Size = 0;
  this->CallArgs.Data.Policy.Capacity = 0;
  this->CallArgs.Data.pHeap = MHeap;
  if ( arg_count )
  {
    opstack = this->OpStack;
    if ( arg_count > 8 )
    {
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->CallArgs.Data,
        arg_count);
      memcpy(*p_CallArgs, (const __m128i *)&opstack->pCurrent[-(unsigned __int16)(arg_count - 1)], 16 * arg_count);
    }
    else
    {
      memcpy(
        (int)this->FixedArr,
        (const __m128i *)&this->OpStack->pCurrent[-(unsigned __int16)(arg_count - 1)],
        16 * arg_count);
    }
    opstack->pCurrent -= arg_count;
  }
}
