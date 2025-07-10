char __thiscall Scaleform::GFx::AS2::SelectionCtorFunction::SetMember(
        Scaleform::GFx::AS2::SelectionCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  Scaleform::GFx::InteractiveObject *v7; // eax
  Scaleform::GFx::Sprite *v8; // edi

  if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  pMovieImpl = penv->Target->pASRoot->pMovieImpl;
  if ( !strcmp(name->pNode->pData, "disableFocusAutoRelease") )
  {
    pMovieImpl->Flags ^= (unsigned int)&vostok::memory::s_CRT_arena[1379896]
                       & (pMovieImpl->Flags
                        ^ ((unsigned __int8)Scaleform::GFx::AS2::Value::ToBool(val, penv) << 22));
    return 1;
  }
  if ( !strcmp(name->pNode->pData, "alwaysEnableArrowKeys") )
  {
    pMovieImpl->Flags ^= (unsigned int)&vostok::memory::s_CRT_arena[39128632]
                       & (pMovieImpl->Flags
                        ^ ((unsigned __int8)Scaleform::GFx::AS2::Value::ToBool(val, penv) << 24));
    return 1;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "alwaysEnableKeyboardPress") )
  {
    pMovieImpl->Flags ^= (pMovieImpl->Flags
                        ^ ((unsigned __int8)Scaleform::GFx::AS2::Value::ToBool(val, penv) << 26))
                       & 0xC000000;
    return 1;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "disableFocusRolloverEvent") )
  {
    pMovieImpl->Flags ^= (pMovieImpl->Flags
                        ^ ((unsigned __int8)Scaleform::GFx::AS2::Value::ToBool(val, penv) << 28))
                       & 0x30000000;
    return 1;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "disableFocusKeys") )
  {
    pMovieImpl->Flags = pMovieImpl->Flags & 0x3FFFFFFF
                      | ((unsigned __int8)Scaleform::GFx::AS2::Value::ToBool(val, penv) << 30);
    return 1;
  }
  if ( !Scaleform::GFx::ASString::operator==(name, "modalClip") )
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  v7 = Scaleform::GFx::AS2::Value::ToCharacter(val, penv);
  v8 = (Scaleform::GFx::Sprite *)v7;
  if ( v7 && v7->GetType(v7) == MouseUp )
  {
    Scaleform::GFx::MovieImpl::SetModalClip(pMovieImpl, v8, 0);
    return 1;
  }
  else
  {
    Scaleform::GFx::MovieImpl::SetModalClip(pMovieImpl, 0, 0);
    return 1;
  }
}
