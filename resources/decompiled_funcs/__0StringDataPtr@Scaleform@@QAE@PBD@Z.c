void __thiscall Scaleform::StringDataPtr::StringDataPtr(Scaleform::StringDataPtr *this, const char *pstr)
{
  this->pStr = pstr;
  if ( pstr )
    this->Size = strlen(pstr);
  else
    this->Size = 0;
}
