void __thiscall Scaleform::GFx::AS3::VM::exec_setglobalslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_index)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *GlobalObject; // eax
  Scaleform::GFx::AS3::Value *v4; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::SlotIndex v7; // [esp-8h] [ebp-10h]
  Scaleform::GFx::AS3::Value *pCurrent; // [esp-4h] [ebp-Ch]

  pCurrent = this->OpStack.pCurrent;
  v7.Index = slot_index;
  GlobalObject = Scaleform::GFx::AS3::VM::GetGlobalObject(this);
  Scaleform::GFx::AS3::Object::SetSlotValue(GlobalObject, (Scaleform::GFx::AS3::CheckResult *)&slot_index, v7, pCurrent);
  v4 = this->OpStack.pCurrent;
  if ( (v4->Flags & 0x1F) <= 9 )
    goto LABEL_7;
  if ( (v4->Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
LABEL_7:
    --this->OpStack.pCurrent;
    return;
  }
  pWeakProxy = v4->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
  v4->Flags &= 0xFFFFFDE0;
  v4->Bonus.pWeakProxy = 0;
  v4->value.VS._1.VInt = 0;
  v4->value.VS._2.VObj = 0;
  --this->OpStack.pCurrent;
}
