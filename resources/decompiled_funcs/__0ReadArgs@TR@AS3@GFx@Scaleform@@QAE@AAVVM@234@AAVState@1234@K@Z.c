void __thiscall Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(
        Scaleform::GFx::AS3::TR::ReadArgs *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::TR::State *s,
        unsigned int arg_count)
{
  const Scaleform::MemoryHeap *MHeap; // eax
  unsigned int Size; // ecx
  unsigned int v7; // edi
  unsigned int v8; // ebx
  Scaleform::GFx::AS3::Value *FixedArr; // ebp
  unsigned int v10; // ebp
  Scaleform::GFx::AS3::TR::State *StateRef; // ebx
  unsigned int v12; // ebp
  Scaleform::GFx::AS3::VM *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_OpStack; // ebx
  Scaleform::Pair<double,unsigned long> *v15; // eax
  unsigned int v16; // edi
  Scaleform::GFx::AS3::VM *vma; // [esp+10h] [ebp+4h]
  Scaleform::GFx::AS3::VM *vmb; // [esp+10h] [ebp+4h]
  Scaleform::GFx::AS3::VM *vmc; // [esp+10h] [ebp+4h]

  this->VMRef = vm;
  this->StateRef = s;
  this->Num = 0;
  this->ArgNum = arg_count;
  MHeap = vm->MHeap;
  this->CallArgs.Data.Data = 0;
  this->CallArgs.Data.Size = 0;
  this->CallArgs.Data.Policy.Capacity = 0;
  this->CallArgs.Data.pHeap = MHeap;
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
  if ( arg_count )
  {
    Size = this->StateRef->OpStack.Data.Size;
    v7 = Size - arg_count;
    if ( arg_count > 8 )
    {
      if ( v7 < Size )
      {
        v10 = v7;
        vmb = (Scaleform::GFx::AS3::VM *)arg_count;
        do
        {
          Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
            &this->CallArgs.Data,
            &this->StateRef->OpStack.Data.Data[v10++]);
          vmb = (Scaleform::GFx::AS3::VM *)((char *)vmb - 1);
        }
        while ( vmb );
      }
    }
    else if ( v7 < Size )
    {
      v8 = v7;
      FixedArr = this->FixedArr;
      vma = (Scaleform::GFx::AS3::VM *)arg_count;
      do
      {
        Scaleform::GFx::AS3::Value::Assign(FixedArr++, &this->StateRef->OpStack.Data.Data[v8++]);
        vma = (Scaleform::GFx::AS3::VM *)((char *)vma - 1);
      }
      while ( vma );
    }
    StateRef = this->StateRef;
    v12 = StateRef->OpStack.Data.Size;
    pHeap = (Scaleform::GFx::AS3::VM *)StateRef->OpStack.Data.pHeap;
    p_OpStack = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&StateRef->OpStack;
    vmc = pHeap;
    if ( v7 >= v12 )
    {
      if ( v7 >= p_OpStack->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_OpStack,
          pHeap,
          v7 + (v7 >> 2));
    }
    else
    {
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
        (Scaleform::GFx::AS3::Value *)&p_OpStack->Data[v7],
        v12 - v7);
      if ( v7 < p_OpStack->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_OpStack,
          vmc,
          v7);
    }
    p_OpStack->Size = v7;
    if ( v7 <= v12 )
    {
      this->Num += arg_count;
    }
    else
    {
      v15 = &p_OpStack->Data[v12];
      v16 = v7 - v12;
      if ( v16 )
      {
        do
        {
          if ( v15 )
          {
            LODWORD(v15->First) = 0;
            HIDWORD(v15->First) = 0;
          }
          ++v15;
          --v16;
        }
        while ( v16 );
        this->Num += arg_count;
      }
      else
      {
        this->Num += arg_count;
      }
    }
  }
  else
  {
    this->Num = this->Num;
  }
}
