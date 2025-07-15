void __thiscall Scaleform::GFx::AS3::StackReader::Read(
        Scaleform::GFx::AS3::StackReader *this,
        Scaleform::GFx::AS3::Multiname *obj)
{
  unsigned __int32 v2; // eax
  Scaleform::GFx::AS3::ValueStack *OpStack; // esi
  Scaleform::GFx::AS3::Value *pCurrent; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v7; // zf
  Scaleform::GFx::AS3::WeakProxy *v8; // eax

  v2 = obj->Kind - 1;
  while ( 2 )
  {
    switch ( v2 )
    {
      case 0u:
      case 8u:
        Scaleform::GFx::AS3::StackReader::CheckObject(this, this->OpStack->pCurrent);
        if ( !this->VMRef->HandleException )
        {
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&obj->Obj,
            (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this->OpStack->pCurrent->value.VS._1.VInt);
          obj->Kind &= 0xFFFFFFFC;
          OpStack = this->OpStack;
          pCurrent = OpStack->pCurrent;
          if ( (OpStack->pCurrent->Flags & 0x1F) <= 9 )
            goto LABEL_17;
          if ( (OpStack->pCurrent->Flags & 0x200) == 0 )
            goto LABEL_16;
          pWeakProxy = pCurrent->Bonus.pWeakProxy;
          v7 = pWeakProxy->RefCount-- == 1;
          if ( !v7 )
            goto LABEL_15;
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          pCurrent->Flags &= 0xFFFFFDE0;
          pCurrent->Bonus.pWeakProxy = 0;
          pCurrent->value.VS._1.VInt = 0;
          pCurrent->value.VS._2.VObj = 0;
          --OpStack->pCurrent;
        }
        return;
      case 4u:
      case 0xCu:
        Scaleform::GFx::AS3::Multiname::PickRTNameUnsafe(obj, this->OpStack);
        Scaleform::GFx::AS3::StackReader::CheckObject(this, this->OpStack->pCurrent);
        if ( this->VMRef->HandleException )
          return;
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&obj->Obj,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this->OpStack->pCurrent->value.VS._1.VInt);
        obj->Kind &= 0xFFFFFFFC;
        OpStack = this->OpStack;
        pCurrent = OpStack->pCurrent;
        if ( (OpStack->pCurrent->Flags & 0x1F) <= 9 )
          goto LABEL_17;
        if ( (OpStack->pCurrent->Flags & 0x200) == 0 )
        {
LABEL_16:
          Scaleform::GFx::AS3::Value::ReleaseInternal(pCurrent);
LABEL_17:
          --OpStack->pCurrent;
          return;
        }
        v8 = pCurrent->Bonus.pWeakProxy;
        v7 = v8->RefCount-- == 1;
        if ( v7 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
LABEL_15:
        pCurrent->Flags &= 0xFFFFFDE0;
        pCurrent->Bonus.pWeakProxy = 0;
        pCurrent->value.VS._1.VInt = 0;
        pCurrent->value.VS._2.VObj = 0;
        --OpStack->pCurrent;
        return;
      case 5u:
      case 0xDu:
        Scaleform::GFx::AS3::Multiname::PickRTNameUnsafe(obj, this->OpStack);
        return;
      case 0xFu:
        this->VMRef->UI->Output(this->VMRef->UI, Output_Warning, "Reading chained multiname in itself.");
        v2 = obj->Kind - 1;
        if ( v2 <= 0xF )
          continue;
        return;
      default:
        return;
    }
  }
}
