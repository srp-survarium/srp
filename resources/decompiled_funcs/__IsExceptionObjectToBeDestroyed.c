int __cdecl _IsExceptionObjectToBeDestroyed(void *pExceptionObject)
{
  void **i; // eax

  for ( i = (void **)_getptd()->_pFrameInfoChain; ; i = (void **)i[1] )
  {
    if ( !i )
      return 1;
    if ( *i == pExceptionObject )
      break;
  }
  return 0;
}
