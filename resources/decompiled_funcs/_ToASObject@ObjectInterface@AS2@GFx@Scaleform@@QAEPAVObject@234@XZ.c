Scaleform::Ptr<Scaleform::GFx::AS2::Object> *__thiscall Scaleform::GFx::AS2::ObjectInterface::ToASObject(
        Scaleform::GFx::AS2::ObjectInterface *this)
{
  if ( (unsigned int)(this->GetObjectType(this) - 6) > 0x26 )
    return 0;
  else
    return &this[-2].pProto;
}
