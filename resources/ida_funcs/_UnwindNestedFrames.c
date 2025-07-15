void __userpurge _UnwindNestedFrames(
        _EXCEPTION_REGISTRATION_RECORD **a1@<ebx>,
        EHRegistrationNode *pRN,
        _EXCEPTION_RECORD *pExcept)
{
  RtlUnwind(pRN, &ReturnPoint, pExcept, 0);
  pExcept->ExceptionFlags &= ~2u;
  *a1 = NtCurrentTeb()->NtTib.ExceptionList;
}
