int __thiscall Scaleform::LongFormatter::GetSize(Scaleform::LongFormatter *this)
{
  return (char *)this - this->ValueStr + 76;
}
