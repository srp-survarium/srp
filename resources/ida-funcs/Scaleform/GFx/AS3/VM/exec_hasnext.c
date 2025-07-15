void __thiscall Scaleform::GFx::AS3::VM::exec_hasnext(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // esi
  Scaleform::GFx::AS3::Value::VU *p_value; // eax
  Scaleform::GFx::AS3::Value *v4; // esi
  Scaleform::GFx::AS3::Value::V1U v5; // ebx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value *v8; // eax
  Scaleform::GFx::AS3::CheckResult result[4]; // [esp+10h] [ebp-18h] BYREF
  int v10; // [esp+14h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,long> stack; // [esp+18h] [ebp-10h] BYREF

  v10 = 0;
  pCurrent = this->OpStack.pCurrent;
  if ( Scaleform::GFx::AS3::Value::ToInt32Value(pCurrent, &result[3])->Result )
  {
    stack.Success = 1;
    p_value = &pCurrent->value;
  }
  else
  {
    stack.Success = 0;
    p_value = (Scaleform::GFx::AS3::Value::VU *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
  }
  v4 = this->OpStack.pCurrent;
  v5 = p_value->VS._1;
  if ( (v4->Flags & 0x1F) > 9 )
  {
    if ( (v4->Flags & 0x200) != 0 )
    {
      pWeakProxy = v4->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      v4->Flags &= 0xFFFFFDE0;
      v4->Bonus.pWeakProxy = 0;
      v4->value.VS._1.VInt = 0;
      v4->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
    }
  }
  --this->OpStack.pCurrent;
  if ( stack.Success )
  {
    v8 = *(Scaleform::GFx::AS3::Value **)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, int *, Scaleform::GFx::AS3::Value::V1U))(*(_DWORD *)v4[-1].value.VS._1.VInt + 64))(
                                           v4[-1].value.VS._1,
                                           &v10,
                                           v5);
    *(_DWORD *)&stack.Success = 3;
    stack._2 = 0;
    stack._1 = v8;
    Scaleform::GFx::AS3::Value::Assign(v4 - 1, (const Scaleform::GFx::AS3::Value *)&stack);
    Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&stack);
  }
}
