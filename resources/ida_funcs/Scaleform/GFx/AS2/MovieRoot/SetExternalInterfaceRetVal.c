void __thiscall Scaleform::GFx::AS2::MovieRoot::SetExternalInterfaceRetVal(
        Scaleform::GFx::AS2::MovieRoot *this,
        const Scaleform::GFx::Value *retVal)
{
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(this, retVal, &this->ExternalIntfRetVal);
}
