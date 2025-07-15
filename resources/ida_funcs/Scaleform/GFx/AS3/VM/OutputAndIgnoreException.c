void __thiscall Scaleform::GFx::AS3::VM::OutputAndIgnoreException(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // esi

  p_ExceptionObj = &this->ExceptionObj;
  this->HandleException = 0;
  Scaleform::GFx::AS3::VM::OutputError(this, &this->ExceptionObj);
  if ( (p_ExceptionObj->Flags & 0x1F) > 9 )
  {
    if ( (p_ExceptionObj->Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_ExceptionObj);
      p_ExceptionObj->Flags &= 0xFFFFFFE0;
      return;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(p_ExceptionObj);
  }
  p_ExceptionObj->Flags &= 0xFFFFFFE0;
}
