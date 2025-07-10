DName *__cdecl UnDecorator::getSymbolName(DName *result)
{
  if ( *UnDecorator::gName == 63 )
  {
    if ( UnDecorator::gName[1] == 36 )
    {
      UnDecorator::getTemplateName(result, 1);
    }
    else
    {
      ++UnDecorator::gName;
      UnDecorator::getOperatorName(result, 0, 0);
    }
  }
  else
  {
    UnDecorator::getZName(result, 1, 0);
  }
  return result;
}
