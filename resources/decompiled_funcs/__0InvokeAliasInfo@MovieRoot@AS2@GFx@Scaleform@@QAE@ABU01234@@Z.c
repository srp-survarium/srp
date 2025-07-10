void __thiscall Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo::InvokeAliasInfo(
        Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *this,
        const Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *__that)
{
  Scaleform::GFx::CharacterHandle *pObject; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // edx

  if ( __that->ThisObject.pObject )
    __that->ThisObject.pObject->RefCount = (__that->ThisObject.pObject->RefCount + 1) & 0x8FFFFFFF;
  this->ThisObject.pObject = __that->ThisObject.pObject;
  pObject = __that->ThisChar.pObject;
  if ( pObject )
    ++pObject->RefCount;
  this->ThisChar.pObject = __that->ThisChar.pObject;
  this->Function.Flags = 0;
  Function = __that->Function.Function;
  this->Function.Function = Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  this->Function.pLocalFrame = 0;
  pLocalFrame = __that->Function.pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->Function, pLocalFrame, __that->Function.Flags & 1);
}
