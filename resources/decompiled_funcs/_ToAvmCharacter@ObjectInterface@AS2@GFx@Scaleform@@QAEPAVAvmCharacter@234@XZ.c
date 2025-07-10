Scaleform::Ptr<Scaleform::GFx::AS2::Object> *__thiscall Scaleform::GFx::AS2::ObjectInterface::ToAvmCharacter(
        Scaleform::GFx::AS2::ObjectInterface *this)
{
  if ( (unsigned int)(this->GetObjectType(this) - 2) > 3 )
    return 0;
  else
    return &this[-1].pProto;
}
