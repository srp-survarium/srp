void __stdcall __noreturn _CxxThrowException(void *pExceptionObject, const _s__ThrowInfo *pThrowInfo)
{
  EHExceptionRecord ThisException; // [esp+8h] [ebp-20h] BYREF

  qmemcpy(&ThisException, &ExceptionTemplate, sizeof(ThisException));
  ThisException.params.pExceptionObject = pExceptionObject;
  ThisException.params.pThrowInfo = (const _s_ThrowInfo *)pThrowInfo;
  if ( pThrowInfo && (pThrowInfo->attributes & 8) != 0 )
    ThisException.params.magicNumber = (unsigned int)&vostok::memory::s_CRT_arena[15617592];
  RaiseException(
    ThisException.ExceptionCode,
    ThisException.ExceptionFlags,
    ThisException.NumberParameters,
    &ThisException.params.magicNumber);
}
