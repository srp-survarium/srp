void __thiscall Scaleform::GFx::AS2::FnCall::FnCall(
        Scaleform::GFx::AS2::FnCall *this,
        Scaleform::GFx::AS2::Value *ResIn,
        Scaleform::GFx::AS2::ObjectInterface *ThisIn,
        Scaleform::GFx::AS2::Environment *EnvIn,
        int NargsIn,
        int FirstIn)
{
  this->Result = ResIn;
  this->ThisPtr = ThisIn;
  this->__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
  this->ThisFunctionRef.Flags = 0;
  this->ThisFunctionRef.Function = 0;
  this->ThisFunctionRef.pLocalFrame = 0;
  this->Env = EnvIn;
  this->NArgs = NargsIn;
  this->FirstArgBottomIndex = FirstIn;
}
