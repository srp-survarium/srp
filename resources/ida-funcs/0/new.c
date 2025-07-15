void *__cdecl operator new(unsigned int size)
{
  void *result; // eax
  std::bad_alloc pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  while ( 1 )
  {
    result = malloc(size);
    if ( result )
      break;
    if ( !_callnewh(size) )
    {
      if ( (_S1_0 & 1) == 0 )
      {
        _S1_0 |= 1u;
        std::bad_alloc::bad_alloc(&nomem);
        atexit(operator_new_::_6_::_dynamic_atexit_destructor_for__nomem__);
      }
      std::bad_alloc::bad_alloc(&pExceptionObject, &nomem);
      _CxxThrowException(&pExceptionObject, &_TI2_AVbad_alloc_std__);
    }
  }
  return result;
}


void *__cdecl operator new(unsigned int __formal, void *_Where)
{
  return _Where;
}
