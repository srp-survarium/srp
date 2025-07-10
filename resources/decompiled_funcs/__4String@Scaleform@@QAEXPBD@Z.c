void __thiscall Scaleform::String::operator=(Scaleform::String *this, char *pstr)
{
  if ( pstr )
    Scaleform::String::AssignString(this, pstr, strlen(pstr));
  else
    Scaleform::String::AssignString(this, 0, 0);
}
