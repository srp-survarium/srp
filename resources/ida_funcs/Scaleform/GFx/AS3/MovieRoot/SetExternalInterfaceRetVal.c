void __thiscall Scaleform::GFx::AS3::MovieRoot::SetExternalInterfaceRetVal(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::ASStringNode *retVal)
{
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(this, retVal, &this->ExternalIntfRetVal);
}
