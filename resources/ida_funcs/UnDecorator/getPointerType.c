DName *__cdecl UnDecorator::getPointerType(DName *result, const DName *cv, const DName *name)
{
  UnDecorator::getPtrRefType(result, cv, name, 42);
  return result;
}
