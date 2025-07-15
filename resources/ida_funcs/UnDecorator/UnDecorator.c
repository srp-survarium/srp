UnDecorator *__thiscall UnDecorator::UnDecorator(
        UnDecorator *this,
        char *output,
        const char *dName,
        int maxLen,
        char *(__cdecl *pGetParameter)(int),
        unsigned int disable)
{
  UnDecorator *result; // eax
  Replicator *p_ZNameList; // ecx

  result = this;
  this->ArgList.index = -1;
  p_ZNameList = &this->ZNameList;
  p_ZNameList->index = -1;
  UnDecorator::name = dName;
  UnDecorator::gName = dName;
  if ( output )
  {
    UnDecorator::maxStringLength = maxLen;
    UnDecorator::outputString = output;
  }
  else
  {
    UnDecorator::outputString = 0;
    UnDecorator::maxStringLength = 0;
  }
  UnDecorator::pZNameList = p_ZNameList;
  UnDecorator::disableFlags = disable;
  UnDecorator::pArgList = &result->ArgList;
  UnDecorator::m_pGetParameter = pGetParameter;
  UnDecorator::fExplicitTemplateParams = 0;
  return result;
}
