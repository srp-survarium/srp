bool __thiscall Scaleform::GFx::AS2::FnCall::CheckThisPtr(Scaleform::GFx::AS2::FnCall *this, unsigned int type)
{
  return this->ThisPtr && this->ThisPtr->GetObjectType(this->ThisPtr) == type;
}
