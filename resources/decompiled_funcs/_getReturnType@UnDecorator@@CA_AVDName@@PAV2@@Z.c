DName *__cdecl UnDecorator::getReturnType(DName *result, DName *pDeclarator)
{
  if ( *UnDecorator::gName == 64 )
  {
    ++UnDecorator::gName;
    DName::DName(result, pDeclarator);
  }
  else
  {
    UnDecorator::getDataType(result, pDeclarator);
  }
  return result;
}
