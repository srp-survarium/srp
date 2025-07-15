void __thiscall Scaleform::GFx::AS3::VM::ExecuteAndRetrieveResult(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  if ( !this->HandleException )
  {
    Scaleform::GFx::AS3::VM::ExecuteCode(this, 1u);
    if ( !this->HandleException )
    {
      if ( (result->Flags & 0x1F) > 9 )
      {
        if ( (result->Flags & 0x200) != 0 )
        {
          pWeakProxy = result->Bonus.pWeakProxy;
          if ( pWeakProxy->RefCount-- == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          result->Flags &= 0xFFFFFDE0;
          result->Bonus.pWeakProxy = 0;
          result->value.VNumber = 0.0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(result);
        }
      }
      *result = *this->OpStack.pCurrent--;
    }
  }
}
