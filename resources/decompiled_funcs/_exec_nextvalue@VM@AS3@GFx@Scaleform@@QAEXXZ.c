void __thiscall Scaleform::GFx::AS3::VM::exec_nextvalue(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // esi
  Scaleform::GFx::AS3::Value::VU *p_value; // eax
  Scaleform::GFx::AS3::Value *v4; // esi
  Scaleform::GFx::AS3::GlobalSlotIndex v5; // ebx
  Scaleform::GFx::AS3::Value *v6; // ebp
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *VNs; // ecx
  Scaleform::GFx::AS3::Value *v10; // [esp-8h] [ebp-2Ch]
  Scaleform::GFx::AS3::CheckResult result; // [esp+13h] [ebp-11h] BYREF
  int v12; // [esp+14h] [ebp-10h]
  Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,long> stack; // [esp+18h] [ebp-Ch]

  pCurrent = this->OpStack.pCurrent;
  v12 = 0;
  if ( Scaleform::GFx::AS3::Value::ToInt32Value(pCurrent, &result)->Result )
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
  v5.Index = p_value->VS._1.VInt;
  v6 = v4 - 1;
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
    VNs = v6->value.VS._1.VNs;
    v10 = v4 - 1;
    if ( (v6->Flags & 0x1F) == 0xB )
      Scaleform::GFx::AS3::Instances::fl::Namespace::GetNextPropertyValue(VNs, v10, v5);
    else
      ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Namespace *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::GlobalSlotIndex))VNs->__vftable[3].Finalize_GC)(
        VNs,
        v10,
        v5);
  }
}
