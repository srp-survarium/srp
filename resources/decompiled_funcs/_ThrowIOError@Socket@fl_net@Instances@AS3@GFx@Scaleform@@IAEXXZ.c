void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowIOError(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::VM *v4; // eax
  Scaleform::GFx::AS3::Value v; // [esp+8h] [ebp-10h] BYREF

  pObject = this->pTraits.pObject;
  v.Flags = 0;
  v.Bonus.pWeakProxy = 0;
  pVM = pObject->pVM;
  Scaleform::GFx::AS3::VM::Construct(pVM, "flash.errors.IOError", pVM->CurrentDomain, &v, 0, 0, 1);
  if ( !pVM->HandleException && (v.Flags & 0x1F) != 0 && ((v.Flags & 0x1F) - 12 > 3 || v.value.VS._1.VInt) )
  {
    v4 = this->pTraits.pObject->pVM;
    v4->HandleException = 1;
    Scaleform::GFx::AS3::Value::Assign(&v4->ExceptionObj, &v);
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
}
