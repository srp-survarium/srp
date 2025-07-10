char __thiscall Scaleform::GFx::AS2::MovieClipObject::DeleteMember(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name)
{
  const char *pData; // eax
  void (__thiscall *v5)(struct Scaleform::GFx::AS2::MovieClipObject *); // eax
  __int16 ButtonEventNameMask; // ax
  Scaleform::GFx::AS2::Value v8; // [esp+Ch] [ebp-10h] BYREF

  if ( name->pNode->Size > 2 )
  {
    pData = name->pNode->pData;
    if ( *pData == 111 && pData[1] == 110 )
    {
      v5 = this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::MovieClipObject;
      v8.T.Type = 0;
      if ( ((unsigned __int8 (__thiscall *)(Scaleform::GFx::AS2::MovieClipObject *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v5)(
             this,
             psc,
             name,
             &v8) )
      {
        ButtonEventNameMask = Scaleform::GFx::AS2::MovieClipObject::GetButtonEventNameMask(psc, name);
        if ( ButtonEventNameMask )
          *(_WORD *)&this->ResolveHandler.Flags &= ~ButtonEventNameMask;
      }
      if ( v8.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v8);
    }
  }
  return Scaleform::GFx::AS2::Object::DeleteMember(this, psc, name);
}
