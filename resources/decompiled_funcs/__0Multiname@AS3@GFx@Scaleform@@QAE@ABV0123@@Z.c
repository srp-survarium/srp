void __thiscall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        const Scaleform::GFx::AS3::Multiname *__that)
{
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // eax
  Scaleform::GFx::AS3::Value *p_Name; // ecx

  this->Kind = __that->Kind;
  pObject = __that->Obj.pObject;
  this->Obj.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  p_Name = &__that->Name;
  this->Name = __that->Name;
  if ( (__that->Name.Flags & 0x1F) > 9 )
  {
    if ( (p_Name->Flags & 0x200) != 0 )
      ++__that->Name.Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(p_Name);
  }
}
