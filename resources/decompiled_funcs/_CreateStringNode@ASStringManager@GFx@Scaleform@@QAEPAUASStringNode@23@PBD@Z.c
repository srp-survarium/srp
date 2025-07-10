Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASStringManager::CreateStringNode(
        Scaleform::GFx::ASStringManager *this,
        char *pstr)
{
  if ( pstr )
    return Scaleform::GFx::ASStringManager::CreateStringNode(this, pstr, strlen(pstr));
  else
    return &this->EmptyStringNode;
}
