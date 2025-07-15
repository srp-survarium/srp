char __thiscall Scaleform::GFx::AS3::Value::MakeWeakRef(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::AS3::GASRefCountBase *WeakBase; // eax
  Scaleform::GFx::AS3::WeakProxy *pV; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::WeakProxy> result; // [esp+8h] [ebp-4h] BYREF

  if ( (this->Flags & 0x200) != 0 )
    return 0;
  if ( (this->Flags & 0x1F) <= 0xA )
    return 0;
  WeakBase = Scaleform::GFx::AS3::Value::GetWeakBase(this);
  if ( !WeakBase )
    return 0;
  pV = Scaleform::GFx::AS3::GASRefCountBase::CreateWeakProxy(WeakBase, &result)->pV;
  this->Flags |= 0x200u;
  this->Bonus.pWeakProxy = pV;
  Scaleform::GFx::AS3::Value::ReleaseInternal(this);
  return 1;
}
